# def trans(count):
#     while count
def solution(s):
    answer = []
    total = 0;
    b = 0;
    while s != "1":
        b = b+1;
        count = 0;
        for i in s:
            if i == "1":
                count = count + 1
            else:
                total = total+1
        # count를 2진법으로 바꾸어 s에 넣기
        s = format(count, 'b')
    answer.append(b)
    answer.append(total)
    return answer