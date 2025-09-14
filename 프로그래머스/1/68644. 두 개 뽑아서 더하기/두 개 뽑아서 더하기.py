from itertools import combinations
def solution(numbers):
    answer = []
    combi = list(combinations(numbers, 2))
    for i in combi:
        answer.append(sum(i))
    print(combi)
    answer = list(set(answer))
    answer.sort()
    
    return answer

