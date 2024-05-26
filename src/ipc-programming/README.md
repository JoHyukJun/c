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
    - Named Pipe(FIFO)
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
