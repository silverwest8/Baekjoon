def solution(s):
    answer = ''
    flag = True;
    for i in s:
        if i == " ":
            flag = True;
            answer = answer + i
            continue;
        if flag:
            answer = answer + i.upper()
        else:
            answer = answer + i.lower()
        flag = False
    # s = s.strip()
    # ss = s.split()
    # print(ss)
    # for i in ss:
    #     if (len(i) > 0):
    #         answer = answer + i[0].upper() + i[1:].lower() + " "
    #     else:
    #         answer = answer + i[0].upper() + " "
    # answer = answer.strip()
    return answer