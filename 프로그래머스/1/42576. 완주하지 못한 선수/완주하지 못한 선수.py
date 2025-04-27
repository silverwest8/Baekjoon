def solution(participant, completion):
    answer = ''
    dic = {}
    for part in participant:
        dic[part] = dic.get(part, 0) + 1
    for com in completion:
        dic[com] -= 1
    for key in dic:
        if dic[key] > 0:
            answer = key
            break
    return answer