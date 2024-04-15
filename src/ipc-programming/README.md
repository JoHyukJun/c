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
