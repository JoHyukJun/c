# 05-system-info

## qna

## q-01

다음과 같이 uname() 함수를 사용해 운영체제 정보를 검색했다. 운영체제 이름을 출력할 수 있도록 올바르게 작성한 것은?

    struct utsname uts;
    uname(&uts);

    1. printf("%s\n", uts.nodename)
    2. printf("%s\n", uts.osname)
    3. printf("%s\n", uts.sysname)
    4. printf("%s\n", uts.uname)

## a-01

### 3. printf("%s\n", uts.sysname)

    - sysname
        - 현재 운영체제의 이름을 저장
    - nodename
        - 네트웤를 통해 통신할 떄 사용하는 시스템의 이름을 저장
    - release
        - 운영체제의 릴리즈 번호를 저장
    - version
        - 운영체제의 버전 번호를 저장
    - machine
        - 운영체제가 동작하는 하드웨어의 표준 이름(아키텍처)를 저장

## q-02

sysconf() 함수를 사용해 로그인명의 최대 길이를 알아보려고 한다. 올바르게 작성한 것은?

    1. sysconf(_SC_NAME_MAX)
    2. sysconf(_SC_LOGIN_NAME_MAX)
    3. sysconf(_SC_LOGINNAME_MAX)
    4. sysconf(_SC_LOGIN_MAX)

## a-02

### 2. sysconf(_SC_LOGIN_NAME_MAX)

    - _SC_ARG_MAX
        - exec() 계열 함수에 사용하는 인자의 최대 크기
    - _SC_CHILD_MAX
        - 한 UID에 허용되는 최대 프로세스 개수
    - _SC_HOST_NAME_MAX
        - 호스트명의 최대 길이
    - _SC_LOGIN_NAME_MAX
        - 로그인명의 최대 길이
    - _SC_CLT_TCK
        - 초당 클록 틱 수
    - _SC_OPEN_MAX
        - 프로세스당 열 수 있는 최대 파일 수
    - _SC_PAGESIZE
        - 시스템 메모리의 페이지 크기
    - _SC_VERSION
        - 시스템이 지원하는 POSIX.1의 버전

## q-03

로그인명이 "jo"인 사용자 정보를 패스워드 파일에서 읽어오려고 한다. 올바르게 작성한 것은?

    1. getspname("jo")
    2. getspnam("jo")
    3. getpwname("jo")
    4. getpwnam("jo")

## a-03

### 4. getpwnam("jo")

    - 로그인명을 받아 /etc/passwd 파일에서 사용자 정보를 검색한 후 검색 결과를 passwd 구조체에 저장하고 주소를 리턴

## q-04

/etc/group 파일을 순차적으로 읽다가 파일의 오프셋을 처음으로 위치시키려고 한다. 이때 사용하는 함수는?

    1. getgrent()
    2. lseek()
    3. segrent()
    4. fseek()

## a-04

### 3. segrent()

    - void setgrent(void);
        - /etc/gourp 파일의 오프셋을 파일의 처음으로 위치

## q-05

localtime() 함수로 시간 정보를 분해하고 출력했더니 연도가 120으로 나왔다. 이것은 몇 년을 나타내는가?

    1. 2020
    2. 2030
    3. 2010
    4. 1200

## a-05

### 1. 2020

    - tm 구조체
        - tm_sec
            - 0 ~ 60
        - tm_min
            - 0 ~ 59
        - tm_hour
            - 0 ~ 23
        - tm_mday
            - 0 ~ 31
        - tm_mon
            - 0 ~ 11
            - 0은 1월, 11은 12월
        - tm_year
            - 연도 - 1900
        - tm_wday
            - 0 ~ 6
            - 0은 일요일, 6은 토요일
        - tm_yday
            - 0 ~ 365
        - tm_isdst
            - 서머타임제 시행 여부
            - 1이면 서머차임제 실시 중

## q-06

uname() 함수를 사용하여 myuname 명령을 만드시오. myuname 명령은 시스템의 호스트명, 운영체제 릴리즈 및 버전, 하드웨어 아키텍처 정보를 출력한다. myuname의 옵션은 다음과 같다.

    myuname
    -a : 전체 정보
    -k : 커널 릴리즈 출력
    -r : 커널 버전 번호 출력
    -n : 호스트 이름 출력
    -h : 하드웨어명 출력
    -s : 운영체제명 출력

## a-06

### ./myuname

## q-07

uname()과 gethostname() 함수로 호스트 이름을 검색해 출력하시오. 이때 두 함수가 출력하는 이름이 같은지 다른지 적으시오.

## a-07

###

## q-08

sysconf() 함수를 사용해 호스트명의 최대 길이, 최대 프로세스 개수, 로그인명과 최대 길이, 프로세스당 열 수 있는 최대 파일 수, 시스템이 지원하는 POSIX.1의 버전 정보를 출력하는 mysys 명령을 작성하시오. 이때 mysys의 옵션은 다음과 같다.

    mysys
    -a : 전체 정보
    -h : 호스트명의 최대 길이
    -p : 최대 프로세스 개수
    -l : 로그인명의 최대 길이
    -x : POSIX 버전

## a-08

###

## q-09

sysconf() 함수를 사용해 사용자가 입력한 로그인 ID의 길이가 시스템의 로그인 이름의 최대 길이보다 큰지 확인하는 프로그램을 작성하시오.

## a-09

###

## q-10

사용자 ID를 입력받아 홈 디렉터리와 로그인 셀을 출력하는 프로그램을 작성하시오.

## a-10

###

## q-11

사용자 ID를 입력받아 패스워드 에이징(min, max, warn, inactive) 정보를 출력하는 프로그램을 작성하시오.

## a-11

###

## q-12

사용자 이름을 입력받아 해당 사용자의 1차 그릅과 2차 그룹을 모두 검색하여 출력하는 프로그램을 작성하시오.

## a-12

###

## q-13

사용자 이름을 입력받아 해당 사용자의 암호 변경 시간을 연, 월, 일 형태로 출력하는 프로그램을 작성하시오.

## a-13

###

## q-14

/var/log/wtmp 파일의 정보를 읽어 로그인명과 터미널 정보, 로그아웃 시각, 원격 접속 정보를 출력하는 프로그램을 작성하시오.

## a-14

###

## q-15

날짜와 시간을 출력하는 명령 mydate를 작성하시오. 이때 mydate의 옵션은 다음과 같다.

    mydate
    -a : 연, 월, 일, 요일, 시, 분, 초 출력
    -y : 연도만 출력
    -m : 월만 출력
    -d : 일만 출력
    -w : 요일만 출력
    -h : 시, 분, 초 출력

## a-15

###
