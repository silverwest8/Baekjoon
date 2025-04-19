def solution(s):
    answer = True
    pp = 0
    yy = 0
    for p in s:
        if p == 'p' or p == 'P':
            pp += 1
        if p == 'y' or p == 'Y':
            yy += 1
    if pp == yy:
        return True

    return False