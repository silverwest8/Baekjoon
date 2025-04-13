def solution(n):
    """n을 x로 나눈 나머지가 1이 되도록 하는 가장 작은 자연수 x를 반환"""
    for x in range(2, int(n**0.5) + 1):  # x는 2부터 √n까지
        if n % x == 1:
            return x
    return n - 1  # √n까지 없으면 n-1이 답