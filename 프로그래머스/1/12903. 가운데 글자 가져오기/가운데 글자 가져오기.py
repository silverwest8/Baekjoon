def solution(s):
    idx = int((len(s)-1)/2)
    if len(s) % 2 != 0:
        return s[idx]
    else:
        return s[idx:idx+2]
