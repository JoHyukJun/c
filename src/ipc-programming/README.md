# ipc-programming

## IPC(Inter Process Communication)

    - 프로세스간 통신
    - 프로세스들 사이에서 데이터를 주고받는 행위 또는 그에 대한 방법, 경로
    - Process <----------------------------> Process
        - Data transfer
            - Byte stream
                - Pipe
                - Named pipe(FIFO)
                - Socket(stream)
            - Message
                - POSIX message queue
                - SysV message queue
                - Socket(datagram)
        - Shared memory
            - File memory mapping
                - Anonymous mapping
                - File mapping
            - Shared memory
                - SysV shared memory
                - POSIX shared memory
        - Synchronization
            - Semaphore
                - POSIX semaphore
                - SysV semaphore
            - File lock
                - File lock
                - Record lock

## Pipe

    - Uni-directional byte stream
    - Name / ID 존재하지 않음
    - Related process 간에 사용(fork())
    - Process ----> write ----> fd[1] ----> Pipe ----> fd[0] ----> read ----> Process
    - 사용하지 않는 fds 를 닫아 프로세스 자신이 쓰고 읽지 않도록 함
    - int pipe(int pipefd[2]);
        - pipe 생성
        - pipefd[0]: reader-side fd
        - pipefd[1]: writer-side fd
        - return
            - 성공: 0
            - 실패: -1
        - pipe 가 full 일 때 write 시도하면 blocking
        - pipe 가 empty 일 때 read 시도하면 blocking
        - write size 가 PIPE_BUF 보다 작으면 atomic, 크면 interleaved 될 수 있음
            - LINUX PIPE_BUF: 4KB
            - multiple writer 환경에서 유의

## Named Pipe(FIFO)

    - Uni-directional byte stream
    - 파일 경로가 ID
        - unrelated process 간에도 사용 가능
    - FIFO 생성과 open 이 분리되어 있음
    - open() 시 read-side 와 write-side 가 동기화 됨
        - 양쪽 모두 open 시도가 있어야 성공
        - open 시 O_NONBLOCK 이 유용하게 사용될 수 있음
    - Process ----> write ----> Named Pipe(/tmp/my_fifo) ----> read ----> Process
    - int mkfifo(const char *pathname, mode_t mode);
        - named pipe 생성
        - dpathname: 생성할 named pipe 파일 경로
        - mode: permission
        - return
            - 성공: 0
            - 실패: -1

## Message queue

    - message 기반 communication
        - not byte stream
        - 하나의 메시지는 하나의 블록
    - FIFO(First In First Out) 를 이용한 message queue
    - unrelated process 간에도 사용 가능
    - Process ----> send ----> message queue ----> recv ----> Process
    - SysV Message Queue
        - message 기반 communication
            - message 별 message type 지원
        - message queue
            - fifo
            - ipc key 기반 id(not fd)
        - management tools
            - ipcs: ipc object 관련 정보 조회
            - ipcrm: ipc object 삭제
        - int msgget(key_t key, int msgflg);
            - message queue id 를 구함
            - 옵션에 따라 생성도 가능
            - key: ipc object key or IPC_PRIVATE
                - IPC_PRIVATE: 지정 시 새로운 message queue id 생성
            - msgflg: permission + mask
                - IPC_CREAT: key 에 매치되는 message queue id 없으면 생성
                - IPC_EXCL: key 에 매치되는 message queue id 가 있으면 에러 발생
            - return
                - 성공: message queue id
                - 실패: -1
        - key_t ftok(const char *pathname, int proj_id);
            - filepath 와 proj_id 를 조합하여 key 값을 구함
            - unique 보장은 안됨
            - pathname
                - 조합할 파일 경로
                - 파일이 존재해야 하고, readable 해야 함
            - proj_id
                - 임의의 project id
            - return
                - 성공: ipc key
                - 실패: -1
        - int msgsnd(int msqid, const void *msgp, size_t msgsz, int msgflg);
            - message 전송
            - msqid: message queue id
            - msgq: 전송할 메시지 버퍼
            - msgsz: 전송 메시지 자이즈(mtext의 길이)
            - msgflg
                - IPC_NOWAIT: non-blocking I/O
            - return
                - 성공: 0
                - 실패: -1
        - ssize_t msgrcv(int msqid, void *msgp, size_t msgsz, long msgtyp, int msgflg);
            - msqid: message queue id
            - msgb: message 수신 버퍼
            - msgsz: 최대 수신 길이(mtext len)
            - msgtyp: 수신할 message type
                - 0: 첫번째 메시지 수신
                - 양수: msgtype 에 매치되는 첫번째 메시지 수신
                - 음수: 지정된 절대값보다 작거나 같은 msgtype 에 매치되는 첫번째 메시지 수신
            - msgflg
                - IPC_NOWAIT: non-blocking I/O
                - MSG_COPY
                    - n 번째 메시지를 복사해서 수신(msgtyp 이 index로 사용)
                    - IPC_NOWAIT 와 같이 사용
                - MSG_EXCEPT: msgtyp 과 매치되지 않는 메시지를 수신
                - MSG_NOERROR: 메시지 사이즈가 msgsz 보다 크면 truncate
            - return
                - 성공: 실제로 받은 데이터 길이(mtext len)
                - 실패: -1
    - POSIX Message Queue
        - Message 기반의 커뮤니케이션
            - partial read 없음
            - multiple message read 없음
        - 하나의 message queue 로 read/write 가능
        - multi-reader/writer 가능
        - fiel i/o 기반의 동작
            - i/o multiplexing 가능
        - message 우선순위 적용 가능
        - message notification 가능
        - link 시 -lrt 추가
        - mqd_t mq_open(cosnt char *name, int oflag);
            - mq open
        - mqd_t mq_open(const char *name, int oflag, mode_t mode, struct mq_attr *attr);
            - mq 생성하여 열기
            - name: mq name(반드시 / 로 시작해야함)
            - oflag
                - mast of O_RDONLY, O_WRONLY, O_RDWR, O_CREAT, O_CLOEXEC, O_EXCL, O_NONBLOCK
            - mode
                - permission
            - attr
                - 속성 지정
            - return
                - 성공: message queue descriptor
                - 실패: -1
        - int mq_close(mqd_t mqdes);
            - mq close
            - mqdes
                - message queue descriptor
            - return
                - 성공: 0
                - 실패: -1
        - int mq_unlink(const char *name);
            - mq 삭제
            - name: message queue descriptor name
            - return
                - 성공: 0
                - 실패: -1
        - int mq_send(mqd_t mqdes, const char *msg_ptr, size_t msg_len, unsigned int msg_prio);
            - 메시지 전송
            - mqdes
                - message queue descriptor
            - msg_ptr
                - pointer to send
            - msg_len
                - length to send
            - msg_prio
                - priority
                - 0(low) ~ 32768(high)
            - return
                - 성공: 0
                - 실패: -1
        - ssize_t mq_receive(mqd_t mqdes, char *msg_ptr, size_t msg_len, unsigned int *msg_prio);
            - 메시지 수신
            - mqdes
                - message queue descriptor
            - msg_ptr
                - pointer to receive
            - msg_len
                - length to receive
                - attr.mq_msgsize 보다 크거나 같아야 함
            - msg_prio
                - priority
                - 0(low) ~ 32768(high)
            - return
                - 성공: 읽은 바이트 수
                - 실패: -1
        - int mq_getattr(mqd_t mqdes, struct mq_attr *attr);
        - int mq_setattr(mqd_t mqdes, const struct mq_attr *newattr, struct mq_attr *oldattr);
            - struct mq_attr {
                long mq_flags;  /* flags: 0 or O_NONBLOCK */
                long mq_maxmsg; /* max of messages on queue */
                long mq_msgsize; /* mas message size (bytes) */
                long mq_curmsgs; /* number of messages currently in queue */
            };
            - mqdes
                - message queue descriptor
            - attr
                - attribute
            - return
                - 성공: 0
                - 실패: -1
        - int mq_notify(mqd_t mqdes, const struct sigevent *sevp);
            - 메시지 notification 설정
            - mqdes
                - message queue descriptor
            - sevp
                - notification 설정
                - union sigval {
                    int sigval_int;
                    void *sigval_ptr;
                }
                - struct sigevent {
                    int             sigev_notify; /* notification method */
                    int             sigev_signo; /* notification signal */
                    union sigval    sigev_value; /* data passed with notification */
                    void (*sigev_notify_function) (union sigval); /* function used for thread notification (SIGEV_THREAD) */
                    void *sigev_notify_attributes; /* attributes for notification thread (SIGEV_THREAD) */
                    pid_t sigev_notify_thread_id; /* id of thread to signal (SIGEV_THREAD_ID) */
                }
            - return
                - 성공: 0
                - 실패: -1

## Socket

    - 컴퓨터 네트워크 상에서 데이터를 교환하는 내부 종점(endpoint) 를 정의하기 위한 추상적인 개념
    - 두 socket 이 서로 연결되어야 데이터 통신 가능
    - 각 socket 은 address 가 있어 서로 identifying 가능
    - interface
        - 데이터 통신을 위한 애플리케이션 프로그래밍 인터페이스
        - 애플리케이션이 커널이 서비스하는 tcp/ip network stack 을 이용 가능
    - ipc on socket
        - 호스트 전용 도메인(unix domain socket) 혹은 인터넷 도메인 상에서 local address 사용
        - 양방향 통신
    - domain 과 type
        - 모든 socket 은 domain 과 type 을 지정
    - domain
        - socket 을 어떻게 identifying 하는가
        - socket 에 어떤 방법으로 address 를 부여하는가
        - Unix domain socket(AF_UNIX)
            - host only socket
                - 네트워크 통신 안됨
            - filepath 로 address
            - 양방향 통신
            - stream/datagram 모두 신뢰성 보장
            - file descriptor 전송 가능
        - IPv4 Internet domain socket(AF_INET)
        - IPv6 Internet domain socket(AF_IENT6)
    - type
        - 어떤 방식으로 데이터를 교환
        - stream(SOCK_STREAM)
            - connect-orient
            - byte stream
        - datagram(SOCK_DGRAM)
            - connectionless
            - unreliable

## Shared Memory

    - 일반 파일 mmap 을 이용한 shared memory
        - mapped area 를 읽으면 파일에서 내용을 읽음
        - mapped area 에 쓰면 파일에 씀
        - 각 프로세스가 파일에 i/o 를 하는 것과 같은 효과
        - 동일 파일/동일 영역에 대해 mmap()
        - mmap() 호출 시 flag 에 MAP_SHARED flag 를 포함
        - 서로 관련되지 않은 프로세스 간에 shared memory 생성 가능
        - read/write 가 파일 i/o 까지 이어지므로 성능이 안좋음
    - Annoymous mapping 을 이용한 shared memory
        - 특정 파일을 지정하지 않고 익명의 파일에 메모리 매핑
        - malled()ed address
            - fork() 시 각 프로세스가 별도의 영역을 갖게 됨
            - fork() 후 share qnfrksmd
        - annoymous mapped address
            - fork() 시 각 프로세스가 file descriptor/mapped address 를 공유
            - fork() 후 share 가능
        - mmap() 호출 시 flag 에 MAP_SHARED + MAP_ANONYMOUS 포함
        - mmap() 호출 시 fd 는 -1 로 설정
        - mmap() 호출 시 offset argument 는 무시됨
        - 실제 파일에 연결되지 않기 때문에 상대적으로 성능이 좋음
        - mapping 이후 fork() 된 reloated process 간에만 공유가 가능
        - /dev/zero 파일에 대해 mmap 하는 것은 annoymous mapping 과 같음
    - 둘 이상의 process 간에 공유하는 메모리 공간
    - unrelated process 간에도 공유 가능
    - 동기화 메커니즘 필요
    - SysV shared memory
    - Posix shared memory
        - file system 상에 파일 생성없이 shared memory 생성
            - unrelated process 간에도 공유 가능
            - file i/o overhead 가 없음
        - shm id 는 "/shmid" 의 형식이여함
        - shared memory 의 생성/삭제와 memory mapping 은 별도
        - 시스템 상의 shared memory 정보는 일반적으로 /dev/shm 에 mount 되어 있음

## Semaphore

    - 깃발을 이용한 신호 체계
    - 임계 영역을 보호하기 위한 수단
        - counting semaphore
            - semaphore 초기값을 n 으로 설정
            - n개의 프로세스는 대기(blocking) 없이 접근 가능
            - (n + 1) 번째 프로세스는 자원이 가능할 때까지 기다려야함(blocking)
            - semaphore 를 획득한 프로세스가 release 하면 기다리던 프로세스가 깨어나 semaphore 를 획득
        - binary semaphore
            - 초기값을 1로 설정한 counting semaphore(mutex)
            - semaphore 초기값을 1 으로 설정
            - 오직 하나의 프로세스가 대기(blocking) 없이 접근 가능
            - 나머지 모든 프로세스는 자원이 가능할 때까지 기다려야함
            - semaphore 를 획득한 프로세스가 release 하면 기다리던 프로세스가 깨어나 semaphore 를 획득

## File Lock

    - file 에 대한 lock mechanism
        - flock()
        - fcntl()
        - flockfile()
        - 상황에 적한한 lock mechanism 을 적용
    - 모든 프로세스 적용 여부
        - advisory locking
            - locking 하기로 한 프로세스들 간에 locking
            - 관련 없는 프로세스들은 무시 가능
        - mandatory locking
            - 파일에 lock 이 설정되면 모든 프로세스가 적용
    - Shared lock(reader lock)
        - exclusive lock 이 잡혀있지 않으면 잡을 수 있음
        - 여러 프로세스들이 shared lock 을 잡고 있을 수 있음
    - Exclusive lock
        - 아무런 lock 이 잡혀있지 않으면 잡을 수 있음
    - 자동 해제 조건
        - file close 시 lock 권한 해제
            - 특정 파일에 대한 여러 fd 중 하나라도 close 되면 lock 권한 해제
            - 특정 파일에 대한 모든 fd 가 close 되면 lock 권한 해제
        - process 종료 시 lock 권한 해제
