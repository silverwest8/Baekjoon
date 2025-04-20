def solution(absolutes, signs):
    answer = 0
    for x in range(0, len(absolutes)):
        if (signs[x]):
            answer += absolutes[x]
        else:
            answer -= absolutes[x]
    return answer