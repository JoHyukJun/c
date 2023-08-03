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

## 추상 구문 트리

    - 특정 프로그래밍 언어로 작성된 프로그램 소스 코드를 각각 의미별로 분리하여 구조화

## 의미 분석 및 중간 표현(IR) 생성

    - 예약어 등 코드의 의미에 따라 더 필요한 정보를 유추하거나 분석
    - 자료형 검사 과정 표함
    - 항, 표현식, 구문 그리고 평가
    - 특정 언어에 종속되지 않는 중간언어로 변환해 기계어 생성 준비
    - 경우에 따라 다른 언어로 변환도 가능
