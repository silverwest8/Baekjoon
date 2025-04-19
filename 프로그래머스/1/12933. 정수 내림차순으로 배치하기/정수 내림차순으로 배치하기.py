def solution(n):
    list = [x for x in str(n)]
    list.sort(reverse=True)
    result = "".join(list)
    answer = int(result)
    return answer