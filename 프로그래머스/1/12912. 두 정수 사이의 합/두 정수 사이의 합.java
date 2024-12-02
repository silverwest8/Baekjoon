class Solution {
    public long solution(int a, int b) {
        long answer = 0;
        if (a==b) return a;
        double answer2 = (double)(a+b) * (Math.abs(a-b)+1) / 2;
        answer = (long)answer2;
        return answer;
    }
}