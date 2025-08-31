def solution(s):
    answer = ''
    temp = s.split(" ")
    temp2 = []
    for i in temp:
        s = ""
        for j in range(len(i)):
            if j % 2 == 0:
                s += i[j].upper()
            else:
                s += i[j].lower()
        temp2.append(s)
    answer = " ".join(temp2)
    return answer