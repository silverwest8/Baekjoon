ans = 0
def dfs(i, sum, n):
    global ans
    if sum == n:
        ans = ans + 1
    elif sum < n:
        dfs(i+1, sum+i+1, n)

def solution(n):
    answer = 0
    for i in range(1, n+1):
        dfs(i, i, n)
        
    return ans