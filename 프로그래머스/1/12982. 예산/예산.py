def solution(d, budget):
    answer = 0
    d.sort()
    for i in d:
        if (budget - i >= 0):
            budget = budget - i
            answer = answer+1
    return answer