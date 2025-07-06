def solution(s):
    answer = True
    x = 0
    for i in s:
        if (i == "("):
            x = x+1
        elif (i == ")"):
            x = x-1
            if x < 0:
                answer = False
    if x != 0:
        answer = False
    return answer