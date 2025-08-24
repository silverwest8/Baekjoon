def solution(arr):
    answer = []
    before = -1
    for i in arr:
        if before != i:
            answer.append(i)
        before = i
    return answer
    