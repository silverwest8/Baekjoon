def solution(phone_number):
    idx = len(phone_number) - 4
    answer = "*"*idx + phone_number[idx:idx+4]
    return answer
    