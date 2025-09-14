def solution(s):
    answer = []
    arr = [-1] * 28
    print(ord('a')-97)
    for i in range(len(s)):
        memo = arr[ord(s[i])-97]
        if memo == -1:
            answer.append(memo)
        else:
            answer.append(i-memo)
        arr[ord(s[i])-97] = i
        
    return answer