def solution(nums):
    answer = len(nums)/2
    arr = {}
    for num in nums:
        if num in arr:
            arr[num] = arr[num]+1
        else:
            arr[num] = 0
    if len(arr) < len(nums)/2:
        answer = len(arr)
    return answer