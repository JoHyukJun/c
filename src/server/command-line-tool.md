# command-line-tool

- johyukjun, 20250301

## head

### explanation

- 문서 내용의 앞부분 출력

### options

- -c, --bytes=[-]NUM
  - NUM byte 출력
- -n, --lines=[-]NUM
  - NUM line 출력
- NUM
  - byte 입력 시 K, M, G, T 입력 가능
  - '-' 입력 시 문서의 마지막 NUM byte/line 을 제외 하고 출력

### examples

- head /etc/hosts
- head -n 1 /etc/hosts
- cat /etc/hosts | head -n 10
- cat /etc/hosts | head -n -10

## tail

### explanation

- 문서 내용의 뒷부분 출력

### options

- -c, --bytes=[+]NUM
  - NUM byte 출력
- -n, --lines=[+]NUM
  - NUM line 출력
- -f, --follow[={name|descr}]
  - 추가되는 내용 대기
  - 추가되는 내용 append 출력
- -F
  - 파일이 truncate 되는 경우 re-open 하여 follow(log trace)
- NUM
  - byte 입력 시 K, M, G, T 입력 가능
  - '+' 입력 시 문서 시작의 NUM byte/line 지점에서 출력 시작

### examples

- tail /etc/hosts -n 1
- tail /etc/hosts -n +3
- cat /etc/hosts | tail -n 10
- cat /etc/hosts | tail -n +10

## wc

### explanation

- line/word/byte count 출력

### options

- -l
  - 라인수 만 출력

### examples

- wc /etc/hosts
- wc -l /etc/hosts
- cat /etc/hosts | wc -l
- wc -l /etc/hosts | cut -d ' ' -f 1
- wc -l /etc/hosts | awk '{ print $1 }'
- wc *

## nl

### explanation

- 파일 내용을 라인 넘버와 함께 출력

### options

- -ba
  - 모든 라인에 넘버링
- -v N
  - 시작 라인 넘버를 N 으로 지정
- -s
  - 라인 넘버 출력 후 출력할 separator 지정

### examples

- cat /etc/hosts
- nl /etc/hosts
- nl -ba /etc/hosts
- nl -ba -s ":" /etc/hosts
- nl -ba -s ":" /etc/hosts | tail

## sort

### explanation

- 정렬하여 출력

### options

- -k, --key=KEYDEF
  - key 에 의한 정렬 수행
- -t, --filed-separator
  - 필드 구분자(기본값은 공백 문자)
- -f, --ignore-case
- -g, --general-numeric-sort
- -n, --numeric-sort
- -r, --reverse
- -u, --unique

### examples

- cat /etc/hosts | sort
- cat /etc/hosts | sort -t: -k 3
- cat /etc/hosts | sort -t. -k 3 -n

## uniq

### explanation

- 중복된 내용 제거하고 출력

### options

- -d, --repeated
  - 중복된 내용만 출력
- -u, --unique
  - 중복되지 않은 내용만 출력
- -i, --ignore-case
  - 대소문자 무시

### examples

- uniq /etc/hosts | nl

## cut

### explanation

- 컬럼 잘라서 출력

### options

- -b, --bytes=LIST
  - byte 선택
- -c, --characters=LIST
  - character 선택
- -f, --fields=LIST
  - 필드(컬럼) 선택
- -d, --delimiter=DELIM
  - tab 대신 사용할 구분자 지정
- --complement
  - 선택 반전
- --output-delimiter=STRING
  - 출력시 사용할 구분자 지정

### examples

- head /etc/hosts | cut -d '.' -f 1,3
- head /etc/hosts | cut -b 10

## tr

### explanation

- 내용을 변환하여 출력

### options

- -c, -C, --complement
- -d, --delete

### examples

- head /etc/hosts | tr -d '.'
- head /etc/hosts | tr '.' '#'

## sed

### explanation

- stream editor

### options

- {RANGE}p
  - range 라인 출력
- {RANGE}d
  - range 라인 삭제 출력
- /SEARCHPATTERN/p
  - SEARCHPATTERN 과 매치되는 라인 출력 
- /SEARCHPATTERN/d
  - SEARCHPATTERN 과 매치되는 라인 삭제 출력
- s/REGEX/REPLACE/
  - REGEX 에 매치되는 부분을 REPLACE 로 교체 출력

### examples

- head /etc/hosts | sed -n '1,4p'
- head /etc/hosts | sed '1,4d'
- head /etc/hosts | sed -n '/Host/p'
- head /etc/hosts | 's/Host/KING'

## awk

### explanation

- 텍스트 처리 script language
- awk options 'selection _criteria {action}' input-file

### options

- -F
  - field separator 지정
- $1, $2, ...
  - Nth filed
- NR
  - Number of records
- NF
  - Number of fileds
- FS
  - Filed separator
- RS
  - Record separator
- OFS
  - Output field separator
- ORS
  - Ouput record separator

### examples

- wc /etc/hosts | awk '{ print $1 }'
- head /etc/hosts | awk '{ print $1 }'
'
- head /etc/hosts | awk -F. '/host/ {print}'

## find

### explanation

- 조건에 맞는 파일을 찾아 명령 수행

### options

- -name
  - 이름으로 검색
- -regex
  - regex 로 검색
- -empty
  - 빈 디렉터리 혹은 빈 검색
- size
  - -N :이하
  - +N :이상
- -type
  - d :directory
  - p :named pipe
  - f :regular file
  - l :softlink
  - s :socket
- -perm
  - mode :정확히 일치하는 파일
  - +mode :모든 flag가 포함된 파일
  - /mode :어떤 flag라도 포함된 파일
- -delete
  파일 삭제
- -ls
  - ls -dils 명령 수행
- -print
  - 파일 이름 출력
- -printf
  - 파일 이름을 포맷에 맞게 출력
- -exec
  - 명령 수행
- execdir
  - 해당 디렉터리로 이동하여 명령 수행
- -ok
  - 사용자에게 확인 후 exec
- -okdir
  - 사용자에게 확인 후 execdir

### examples

- find . | wc -l
- find . -name "*.py"
- find `pwd` -name "*.c"
- find `pwd` -regex '.*t.*.c$'
- find . -empty
- find . -type f
- find . -perm 0777
- find . -name "*.py" -print
- find . -name "*.py" -exec stat {} \;
- find . -name "*.py" -execdir stat {} \;
- find . -name "*.py" -ok rm -f {} \;

## grep

### explanation

- 파일 내용 중 원하는 내용을 찾아 출력
- grep [OPTIONS] PATTERN [FILE...]

### options

- -r :recursive
- -i :ignore case
- -v :invert match
- -q :quite mode

### examples

- grep fork *.c
- grep fork *.c -q
- grep "\<for\>" *.c
- grep "^static.*(void)" *.c

## apropos

### explanation

- man page 이름과 설명을 검색

### options

- -s, --sections=LIST, --section=LIST
  - 탐색할 섹션을 colon 으로 구분하여 입력

### examples

- apropos pthread
- apropos pthread -s 7
- apropos '^sem_'
- apropos '.*'

## locate

### explanation

- 파일의 위치를 찾아 출력
- updatedb 가 저장해놓은 db 파일 내에서 검색하여 누락 파일 존재 가능성 있음
- locate [OPTION]... PATTERN...

### options

- -i, --ignore-case
  - 대소문자 구분없이 검색
- -l, --limit, -n LIMIT
  - 출력 결과를 LIMIT 만큼 출력
- --regex
  - PATTERN 을 regex 로 해석

### examples

- locate main.c
- locate main.c -n 10
- locate --regex "./src/.*<main.c$"

## which

### explanation

- 실행 파일의 위치를 출력

### options

- NONE

### examples

- which ls
- which chmod

## ps

### explanation

- process status 출력
 
|code|output header|meaning|
|----|-------------|-------|
|user|UID/USER|Username|
|pid|PID|Process ID|
|tty|TT|실행 terminal|
|cputime|TIME|누적 CPU 소모 시간|
|args|CMD|실행 커맨드 라인|
|stime|STIME|프로세스 시작 시간|
|c|C|CPU utilization|
|%cpu|%CPU|CPU utilization|
|%mem|%MEM|Memory utilization|
|rss|RSS|메모리 사용량|

### options

- -e
  - 모든 프로세스
- -f
  - full format
- -L
  - thread 출력
- --forest
  - 프로세스를 tree 형태로 출력
- -o
  - output formatting
- --sort
  - sorting

### examples

- ps -ef
- ps -p 97174 -f
- ps -ef --forest
- ps -ef --sort-=-%ppid | head
- ps -eo pid,args

## top

### explanation

- 프로세스를 어떤 기준으로 정렬하여 n개의 프로세스를 모니터링

### options

- space :업데이트
- q :종료
- c :full command line 조회
- l :모든 cpu 상태 조회
- M :memory usage
- P :CPU usage
- N :process Id
- T :running time
- R :역순 정렬

### examples

- top

## lsof

### explanation

- 열려있는 파일(파일, 소켓, 디바이스 등) 목록 조회

### options

- -U :Unix domain socket
- -i :Internet domain socket
- -p :특정 pid 가 열어놓은 파일
- -u :User Id 지정

### examples

- lsof
- lsof -U
- lsof -i 4
- lsof -i tcp
- lsof -u `whoami`

## netstat

### explanation

- 네트워크/소켓 상태를 조회

### options

- -a :All type of port
- -n :Numeric address 변환
- -t :TCP socket only
- -u :UDP socket only
- -x :Unix domain socket only
- -l :Listening socket only
- -p :소켓을 열고 있는 프로그램과 PID 조회
- -r :Routing table 조회
- -s :Network statistics 조회

### examples

- netstat
- netstat -an

## sysctl

### explanation

- 시스템 설정 조회/설정

### options

- -a, --all
  - 모든 변수 출력
- -w, --write
  - 지정된 변수에 값 설정
- -r, --pattern
  - 변수 search pattern 입력
- -N, --names
  - 변수 이름만 출력
- -n, --values
  - 변수 값만 출력

### examples

- sysctl -a
- sudo sysctl -w kernel.domainname="johyukjun.com"
- cat /proc/sys/kernel/domainname
- sysctl -a --pattern 'for'

## df

### explanation

- disk 사용량 조회

### options

- -a, --all
  - 모든 내용 출력
- -h, --human-readable
  - 사람이 보기 편한 형태로 출력
- -t, --type=TYPE
  - 지정된 파일 시스템에 대해서만 출력

### examples

- df
- df -h
- df FILE

## du

### explanation

- 특정 파일/디렉터리가 점유하고 있는 disk usage 조회

### options

- -a, --all
  - 디렉터리 포함 모든 파일 출력
- -b, --bytes
  - byte 단위로 출력
- -h, --human-readable
  - 사람이 읽기 편한 포맷으로 출력
- -d, --max-depth=N
  - 디렉터리 최대 깊이
- -c, --total
  - 총 합계 출력
- -s, --summarize
  - 항목 별 요약 출력

### examples

- du
- du /etc -s -c -h
- du -sh *

## dmidecode

### explanation

- SMBIOS 조회
- DMI(Desktop Management Interface)
- SMBIOS(System Management BIOS)
  - BIOS 가 생성한 시스템 하드웨어 정보

### options

- -t, --type
  - 지정된 type 만 출력
- -s, --string
  - 지정된 keyword 만 출력

### examples

- dmidecode
- dmidecode -t bios
- dmidecode -s system-uuid

## lscpu

### explanation

- CPU 구조 정보 출력

### options

- -e, --extended[=<list>]
  - Extended readable format
- -p, --parse[=<list>]
  - Parsable format

### examples

- lscpu
- lscpu -e
- lscpu -e=SOCKET,CORE,CPU
- lscpu -p=SOCKET,CORE,CPU

## free

### explanation

- 메모리 사용량 조회
  - total :총 메모리
  - used :사용 중인 메모리
  - free :free 메모리
  - shared :tmpfs 등에서 사용하는 메모리
  - buffers : kernel buffers
  - cache :page cache, slabs

### options

- -h, --human
  - human readable output
- -s N, --seconds N
  - N 초마다 반복 출력
- -c N, --count N
  - N 회 출력 후 종료

### examples

- free -w -h
- free -s 1 -c 10 -h

## man

### explanation


### options


### examples

## diff

### explanation


### options


### examples

## patch

### explanation


### options


### examples

## ctags

### explanation


### options


### examples

## cscope

### explanation


### options


### examples

## strace

### explanation


### options


### examples