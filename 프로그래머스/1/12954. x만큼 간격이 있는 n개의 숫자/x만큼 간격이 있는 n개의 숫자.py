def solution(x, n):
    answer = []
    # answer = [x for x in range(x, x+x*(n-1)+1, x)]
    for i in range(n):
        answer.append(x + x*i)
    return answer