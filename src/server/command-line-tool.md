# command-line-tool

- johyukjun

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
