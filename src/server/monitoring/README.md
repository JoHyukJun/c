# 리눅스 성능 분석

## 개요

    - 리눅스 서버에서 발생하는 성능 저하 문제의 원인을 파악하고 해결 방안을 제시하는 과정

## uptime

    - 시스템의 가동 기간, Load Average 확인
    - 출력 내용
        - 시작 시간
        - 기동 시간
        - 접속 사용자 수
        - load average
            - 1분 평균, 5분 평균, 15분 평균
    - Load Average
        - 서버가 받고 있는 부하 평균
        - 단위 시간 동안의 R 과 D 상태의 프로세스 개수
        - R 상태
            - CPU 위주의 작업
        - D 상태
            - I/O 위주의 작업
        - R 상태의 프로세스가 많다면 CPU 개수를 늘리거나 스레드 개수를 조절
        - D 상태의 프로세스가 많다면 IOPS 가 높은 디바이스로 변경하거나 처리량을 줄여서 조절
        - vmstat
            - procs 칼럼을 확인
            - r: cpu
            - b: io

## dmesg

    - 커널 메시지 확인 (OOME 발생 여부, SYN Flooding 여부)
    - OOME(Out Of Memory Error)
        - 가용한 메모리가 부족해서 더이상 프로세스에게 할당해 줄 메모리가 없는 상황
        - OOM Killer
            - OOM 상황 발생 -> 프로세스 선택 -> 프로세스 종료 -> 시스템 안정화
            - oom_score
                - OOM Killer 가 종료 시킬 프로세스를 선택하는 기준
                - 스코어가 높은 프로세스가 먼저 종료
        - dmesg -T | grep -i oom
    - SYN Flooding
        - 공격자가 대량의 SYN 패킷만 보내서 소켓을 고갈시키는 공격
        - SYN Cookie
            - SYN 패킷의 정보들을 바탕으로 쿠키를 만듬
            - SYN + ACK 의 시퀀스 번호로 만들어서 응답
            - SYN Backlog 에 쌓지 않음
            - 자원 고갈 현상 방지
            - TCP Option 헤더를 무시하기 떄문에 Windows Scaling 등 성능 향상을 위한 옵션 동작하지 않음
            - SYN Flooding 공격이 들어왔을 경우에 발행
        - dmesg -T | grep -i "syn flooding"

## free

    - 시스템 메모리 사용 현황 확인
    - free
        - 어느 누구도 사용하고 있지 않은 메모리
    - available
        - 애플리케이션에게 실질적으로 할당 가능한 메모리
        - free + buff/cache
    - buff/cache
        - buff: 블록 디바이스가 가지고 있는 블록 자체에 대한 캐시
        - cache: I/O 성능 향상을 위해 사용하는 페이지 캐시
        - 페이지 캐시
            - 한 번 읽었던 파일은 페이지 캐시에 저장 함으로써 블록 디바이스가 아닌 메모리에서 파일의 내용을 읽음
        - I/O 성능 향상을 위해 존재하므로 애플리케이션에서 메모리를 필요로 한다면 buff/cache 영역을 해제하고 애플리케이션이 사용할 수 있는 영역으로 변경
        - buff/cache 가 높으면 I/O 가 많이 일어나는 환경
    - swap
        - 메모리가 부족한 상황에서 사용되는 가상 메모리 공간
        - 블록 디바이스의 일부 영역 사용
        - swap cached
            - swap in 이 되어도 swap 영역에서 지워지지 않음
        - swap 영역 사용시 성능 저하 발생
            - 메모리 참조에 I/O 가 빈번하게 발생
        - 최근 트렌드는 swap 영역 비활성화
            - 컨테이너는 빠르게 다시 띄울 수 있기 때문에 쿠버네티스 환경에서는 대부분 swap 영역을 비활성화

## df

    - 디스크 여유 공간 및 inode 공간 확인
    - 파일 핸들
        - 파일을 참조하고 있는 프로세스가 있을경우 용량이 줄어들지 않는 경우 존재
        - lsof 명령어를 통해 확인
    - inode 는 파일과 디렉터리의 개수(최대값 존재)

## top

    - 프로세스들의 CPU 사용률 확인
    - us
        - user 를 의미
        - 프로세스의 일반적인 CPU 사용량
    - wa
        - wating 을 의미
        - I/O 작업을 대기할 때의 CPU 사용량
    - 프로세스 상태
        - D: uninterruptible sleep(I/O)
        - R: running(CPU)
        - S: sleeping
        - Z: zombie
            - 부모 프로세스가 죽었는데 살아있는 프로세스
            - 시스템 리소스를 사용하진 않지만 PID 고갈 발생 가능성 있음

## netstat

    - 네트워크 연결 정보 확인
    - 소켓 상태
        - LISTEN
        - ESTABLISHED
        - CLOSE_WAIT
            - 애플리케이션 이상 동작
            - 정상적으로 소켓을 정리하는 등 연결을 끊기 위한 동작을 하지 못하는 상태
            - 서버 행업, 포트 고갈 등 서비스에 영향을 끼치는 문제를 일으킬 수 있기 때문에 원인 확인 및 해결 필요
        - TIME_WAIT

## tcpdump

    - 네트워크 패킷 수집 및 분석
    - nn 옵션
        - 프로토콜과 포트 번호를 숫자 그대로 표현
    - vvv 옵션
        - 출력 결과에 더 많은 정보를 표현
    - a 옵션
        - 패킷 내용도 함께 출력
