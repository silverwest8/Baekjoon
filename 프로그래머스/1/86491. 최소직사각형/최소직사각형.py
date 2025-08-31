def solution(sizes):
    answer = 0
    xmax = 0
    ymax = 0
    for i in sizes:
        if i[0] < i[1]:
            temp = i[0]
            i[0] = i[1]
            i[1] = temp
        if i[0] > xmax:
            xmax = i[0]
        if i[1] > ymax:
            ymax = i[1]
    return xmax * ymax