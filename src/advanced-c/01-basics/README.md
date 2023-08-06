# 01-basics

## little endian

    - 낮은 주소에 데이터의 낮은 바이트(LSB, Least Significant Bit) 부터 저장하는 방식
    - intel cpu 에서 채택한 방식
    - 0x00112233 -> 0x33 0x22 0x11 0x00
    - 네트워크에서는 big endian 통일

## floating point

    - float
        - 단정도
        - 32bit
        - 소수점 이하 6자리
    - double
        - 배정도
        - 64bit
        - 소수점 이하 15자리
    - IEEE 754
        - cpu 레벨의 실수 계산 표준
        - single format
            - 1bit(S) + 8bit(지수) + 23bit(가수)
        - double format
            - 1bit(S) + 11bit(지수) + 52bit(가수)

## string

    - 문자열은 상수화된 문자 배열
    - 문자열 상수는 수정 가능
        - 메모리 영역에서 수정하면 문자열 변경 가능
        - 상수화되어있어 동적할당된 메모리
        - memory
            - data
                - run time
                - heap
                    - malloc
                - stack
                    - 자동변수
            - static
                - compile time
                - R--
                    - string
                - RW-
                    - 정적변수

## point of code

    - compile time
        - 코드 작성 시점
        - 기계어로 번역
        - 목적 파일 생성
    - link time
        - 바이너리 생성
    - run time
        - 실행 시점
