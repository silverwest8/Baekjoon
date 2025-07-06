def solution(s):
    answer = ''
    list = s.split(" ")
    for i in range(len(list)):
        list[i] = int(list[i])
    list.sort()
    answer = str(list[0])
    answer += " "
    answer += str(list[len(list) -1])
    return answer