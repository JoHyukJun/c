# 04-file-io

## qna

## q-01

open() 함수를 사용해 jo.txt 파일을 생성하고, 이미 파일이 있으면 오류 메시지를 출력하려고 한다. 올바르게 작성한 것은?

    1. open("jo.txt", O_CREAT, 0644)
    2. open("jo.txt", O_CREAT | O_EXCL, 0644)
    3. open("jo.txt", O_CREAT | O_TRUNC, 0644)
    4. open("jo.txt", O_CREAT | O_APPEND, 0644)

## a-01

### 2. open("jo.txt", O_CREAT | O_EXCL, 0644)

    - O_RDONLY
        - 파일을 읽기 전용으로 open
    - O_WRONLY
        - 파일을 쓰기 전용으로 open
    - O_RDWR
        - 파일을 읽기/쓰기용으로 open
    - O_CREAT
        - 파일이 없으면 생성
    - O_EXCL
        - O_CREEAT 옵션과 함께 사용할 경우 기존에 없는 파일이면 파일 생성
        - 이미 파일이 있을 경우 오류 메시지 출력
    - O_APPEND
        - 파일의 맨 끝에 내용 추가
    - O_TRUNC
        - 파일을 생성할 때 이미 있는 파일이고 쓰기 옵션으로 열었을 경우 내용을 모두 지우고 파일 길이를 0으로 변경
    - O_SYNC/O_DSYNC
        - 저장 장치에 쓰기를 마쳐야 쓰기 동작을 완료
        - O_SYNC 플래그는 파일의 수정 시각 속성도 수정할 때까지 대기

## q-02

lseek() 함수를 사용해 파일 오프셋의 현재 위치를 검색하려고 한다. 맞게 사용한 것은?

    1. lseek(fd, 0, SEEK_SET)
    2. lseek(fd, 0, SEEK_END)
    3. lseek(fd, 1, SEEK_CUR)
    4. lseek(fd, 0, SEEK_CUR)

## a-02

### 4. lseek(fd, 0, SEEK_CUR)

    - 파일의 내용을 읽거나 쓰면 현재 읽을 위치나 쓸 위치를 알려주는 오프셋이 자동으로 변경
    - 오프셋은 파일의 시작 지점에서 현재 위치까지의 바이트 수
    - 한 파일에서 파일 오프셋은 하나
    - off_t lseek(int fd, off_t offset, int whence)
    - whence
        - SEEK_SET
            - 파일의 시작을 기준으로 계산
        - SEEK_CUR
            - 현재 위치를 기준으로 계산
        - SEEK_END
            - 파일의 끝을 기준으로 계산

## q-03

고수준 파일 입출력에서 한 번에 한 문자씩 읽어옭 때 사용하는 함수는?

    1. read()
    2. fputc()
    3. fgetc()
    4. fgets()

## a-03

### 3. fgetc()

    - fgetc()
        - int fgetc(FILE *stream)
        - 파일 포인터가 가리키는 파일로부터 문자 한 개를 unsigned char 형태로 읽어옴
    - fputc()
        - int fputc(int c, FILE *stream)
        - 인자로 받은 int형 데이터 c 를 unsigned char 로 변환해 파일에 씀
    - fgets()
        - char *fgets(char *s, int size, FILE *stream)
        - 파일 포인터가 가리키는 파일에서 변수 size에 지정한 길이보다 하나 적게 문자열을 읽어 s에 저장

## q-04

파일 기술자 fd를 파일 포인터로 변환하려고 한다. 맞게 사용한 것은?

    1. fdopen(fd, "r")
    2. fileno(fd)
    3. fopen(fd)
    4. ftell(fd)

## a-04

### 1. fdopen(fd, "r")

    - 파일 기술자와 파일 포인터는 상호 변환 가능
    - FILE *fdopen(int fd, const char *mode)
        - 파일 기술자와 모드(읽기, 쓰기)를 인자로 받아 파일 포인터 생성
        - mode 값에는 파일 기술자를 열 때와 같은 종류의 값으로 지정
    - int fileno(FILE *stream)

## q-05

/tmp 디렉터리에 접두어로 "jo"을 지정해 임시 파일을 생성하려고 한다. 맞게 사용한 것은?

    1. tmpnam("jo")
    2. tmpnam("/tmp", "jo")
    3. tempnam("/tmp", "jo")
    4. tempnam("jo")

## a-05

### 1. tmpnam("jo")

    - char *tmpnam(char *s)
        - 임시 파일명을 시스템이 알아서 지정
        - 인자가 있을 경우 해당 인자가 가리키는 곳에 임시 파일명을 저장
        - 인자가 NULL 이면 임시 파일명 리턴

## q-06

저수준 파일 입출력을 이용해 'newcat' 프로그램을 작성하시오. 이때 행 번호를 붙여서 출력하고 파일명은 명령행 인자로 받는다.

    newcat jo.c

## a-06

### ./newcat

## q-07

저수준 파일 입출력을 이용해 파일을 복사하는 프로그램을 작성하시오. 이떄 파일명은 명령행 인자로 받는다.

    newcp jo.c hj.c

## a-07

### ./newcp

## q-08

저수준 파일 입출력을 이용해 현재 디렉터리 아래에 새로운 디렉터리를 생성하고 파일을 이동시키는 프로그램을 작성하시오. 이때 생성할 디렉터리명과 파일명은 명령행 인자로 받는다.

    newmv 디렉터리명 파일명

## a-08

### ./newmv

## q-09

파일의 내용을 읽고 세 글자씩 분리해 출력하는 프로그램을 작성하시오.

    파일 내용 123456789
    출력 형태 123 456 789

## a-09

### ./jo_file_div.c

## q-10

lseek() 함수를 이용해 다음 데이터 파일을 읽어 출력 형태와 같이 출력하는 프로그램을 작성하시오.

    데이터 파일 abcdefghijklmnopqrstuvwxyz
    출력 형태 acegikmoqsuwy

## a-10

### ./jo_lseek.c

## q-11

10번 문제를 fseek() 함수를 이용해 구현하시오.

## a-11

### ./jo_fseek.c

## q-12

10번 문제를 fread()와 fwrite() 함수를 사용해 동일한 결과가 출력되도록 작성하시오.

## a-12

### ./jo_frw.c

## q-13

fgetc() 함수를 사용해 특정 문자가 해당 파일에 있는지 확인하는 프로그램을 작성하시오.

## a-13

### ./jo_fgetc.c

## q-14

고수준 파일 입출력을 이용해 파일명을 바꾸는 프로그램을 작성하시오. 이때 파일명은 명령행 인자로 받는다.

    newname jo.txt hj.txt

## a-14

### ./newname.c

## q-15

다음 데이터 파일을 읽고 학번과 평균을 출력하는 프로그램을 작성하시오. 데이터 입력은 저수준 파일 입출력을 이용하고, 형식 기반의 고수준 입출력을 사용할 때와 달리 추가로 필요한 작업은 무엇인지 적으시오.

    학번    철학    음악    미술
    2021001 98      99      97
    2021002 88      90      89

## a-15

### ./jo_scanf.c

## q-16

임시 파일을 생성해 파일명을 출력하고 이 파일에 학번과 학생 이름을 출력하는 프로그램을 작성하시오.

## a-16

### ./jo_tmp.c
