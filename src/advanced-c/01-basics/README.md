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
