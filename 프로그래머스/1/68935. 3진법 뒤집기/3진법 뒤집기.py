def solution(n):
    answer = 0
    # n을 3진법으로 바꾸기
    digit = []
    while n > 0:
        digit.append(str(n % 3))  # LSB부터 쌓임 = 이미 '뒤집힌' 3진수
        n //= 3
    
    rev3 = ''.join(digit)         # 뒤집힌 3진수 문자열
    return int(rev3, 3)
