def solution(num):
    count = 0;
    while count < 500 and num != 1:
        if num % 2 == 0:
            num /= 2
        else:
            num = num*3+1
        count += 1
    if count == 500:
        return -1
    else:
        return count