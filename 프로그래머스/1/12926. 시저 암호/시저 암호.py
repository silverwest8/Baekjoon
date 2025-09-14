def solution(s, n):
    
    
    answer = ''
    for i in s:
        if i == " ":
            answer = answer + " "
            continue;
#        print(i)
#        print(ord(i))
        if ord(i) >= 65 and ord(i) <= 90:
            print(ord(i)+n)
            print((ord(i)+n)%90)
            answer = answer + chr((ord(i)+n-65)%26+65)
        else: # 97 122
            print(ord(i)+n)
            print((ord(i)+n)%122)
            answer = answer + chr((ord(i)+n-97)%26+97)
    return answer
    
