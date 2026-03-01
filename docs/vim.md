# vim

- johyukjun, 20250302

## explanation

- VI iMproved
- vim [OPTION] [files...]

## options

- -t TAG
  - TAG 로 jump 하여 에디터 시작
- -o files...
  - 여러 파일을 split 모드로 열기
- -R files...
  - read only mode 로 열기
- -d files...
  - diff mode

## mode

|mode|description|
|----|-----------|
|normal mode|vim 시작 시의 모드|
|insert mode|i, a, o 등의 명령어로 삽입 모드 진입|
|visual mode|visual line/block 을 지정해서 동작하는 모드|
|select mode|선택 ㅇ영역을 바로 수정|
|command line mode|':', '/', '?', '!' 으로 명령 수행|
|ex mode|ex mode|
|terminal job mode|:terminal 명령으로 vim 창에서 터미널 명령 실행|

## move

- h, j, k, l :좌, 하, 상, 우 
- w :단어 단위 앞으로 이동(단어 시작)
- e :단어 단위 앞으로 이동(단어 끝)
- b :단어 단위 뒤로 이동
- 0 :라인 시작으로 이동
- $ :라인 끝으로 이동
- f(CHAR) :앞쪽으로 가장 먼저 발견되는 CHAR 로 이동
- F(CHAR) :뒤쪽으로 가장 먼저 발견되는 CHAR 로 이동
- } :앞쪽으로 단락 단위 이동
- { :뒤쪽으로 단락 단위 이동
- G :파일의 마지막 줄로 이동
- gg :파일의 첫 줄로 이동
- H, M, L :현재 화면 기준 상단/중단/하단으로 이동
- ctrl + f :한 페이지 앞으로 이동
- ctrl + b :한 페이지 뒤로 이동
- ctrl + d :반 페이지 앞으로 이동
- ctrl + u :반 페이지 뒤로 이동
- ctrl + e :화면 한 줄씩 앞으로(커서 유지)
- ctrl + y :화면 한줄씩 뒤로(커서 유지)

## edit

- i :현재 위치에서 입력 모드 시작
- I : 현재 라인의 시작에서 입력 모드 시작
- a :현재 위치 다음 칸에서 입력 모드 시작
- A :현재 라인의 끝에서 입력 모드 시작
- o :현재 라인의 다음 줄에서 입력 모드 시작
- O :현재 라인을 다음 줄로 밀고 입력 모드 시작
- cc :현재 라인 삭제 후 입력 모드 시작
- C :현재 위치부터 라인 끝까지 삭제 후 입력 모드 시작
- yy :현재 라인 복사
- yw :현재 word의 끝까지 복사
- p :현재 위치 다음에 붙여넣기
- P :현재 위치에 붙여넣기
- x :현재 캐릭터 잘라내기
- dd :현재 라인 잘라내기
- dw :현재 word의 끝까지 잘라내기
- r :현재 위치 한글자 덮어쓰기
- R :현재 위치부터 계속 덮어쓰기
- u :undo
- ctrl-r :redo
- . :마지막 행동 반복

## search

- /keyword
  - 아래쪽으로 검색
- ?keyword
  - 위쪽으로 검색
- /\<keyword\>
  - 단어 단위 검색
- n
  - 정방향 검색 반복
- N
  - 역방향 검색 반복
- '*'
  - 커서 위치의 키워드 아래쪽으로 검색
- '#'
  - 커서 위치의 키워드 위쪽으로 검색
- /abc\|xyz
  - abc 혹은 xyz
- :set ic
  - 대소문자 구분안함
- :set noic
  - 대소문자 구분함
- :set hlsearch
  - search highlight on
- :set nohlsearch
  - search highlight off
- :set incsearch
  - 타이핑 시 화면에 표시함
- :set noincsearch
  - 타이핑 시 화면에 표시안함

## string

- :%s/str/replace
  - 전체 문서에서 str->replace 로 치환
- :%s/str/replace/g
  - 다중 검색시에도 적용
- :%s/str/replace/gc
  - 치환 시 사용자에게 묻기
- :%s/\<str\>/replace/gc
  - "str"을 단어 단위로 검색
- .
  - 현재 라인
- 1
  - 라인 1
- $
  - 문서의 마지막 라인

## regex

- . :newline 제외한 모든 문자
- ^ :문장의 시작
- $ :문장의 끝
- \* :zero or more
- \\+ :one or more
- \\= : zero or one
- \\{n} :n회 반복
- \\{n,m} :n~m회 반복
- \\{n,} :최소 n회 반복
- \\{,m} :최대 m회 반복
- [0-9] :0~9 사이의 문자
- [a-z] :a~z 사이의 문자
- [abc] :a,b,c 중 하나와 매치되는 문자
- [^0-9] :0~9를 제외한 문자

## multi-window

- 가로 분할
  - vim -o hashlib.c hashlib.h
  - :split n
  - ctrl + s
  - ctrl + w n
- 세로 분할
  - vim -O hashlib.c hashlib.h
  - vsplit
  - ctrl + w v
- 현재 창 닫기
  - :q
  - ctrl + w q
- 현재 창만 남기기
  - :only
  - ctrl + w o
- ctrl + w w :다음 창으로 이동
- ctrl + w k :윗 창으로 이동
- ctrl + w j :아래 창으로 이동
- ctrl + w h :왼쪽 창으로 이동
- ctrl + w l :오른쪽 창으로 이동
- ctrl + w t :최상단 창으로 이동
- ctrl + w b :최하단 창으로 이동
