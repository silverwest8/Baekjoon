def solution(n):
    answer = 0
    binary = bin(n)[2:].count("1")
    
    n = n+1
    while n <= 1000000:
        if bin(n)[2:].count("1") == binary:
            return n
        n = n+1
        
