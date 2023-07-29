# 02-compiler

## complier components

    - front end
        - lexical analyzer
            - 어휘 분석기
            - token
        - syntax analyzer
            - 구문 분석기
            - syntax tree
        - semantic analyzer
            - 의미 분석기
            - intermediate representation
    - back end
        - code generator
            - 코드 생성기
            - asseble code + optimization
        - assembler
            - 어셈블러
            - machine code

## 어희, 구문 분석

    - 문자열 형태로 존재하는 소스코드를 의미 있는 문자 혹은 문자열 조각(토큰)으로 변환(예약어, 상수, 변수, 연산자 등)
    - 각 토큰을 구문 트리(syntax tree)로 변환하며 이 과정에서 문법 오류 검출
