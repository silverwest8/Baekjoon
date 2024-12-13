class Solution {
    public long solution(long n) {
        long answer = 0;
        double a = Math.sqrt((double)n);
        long b = Math.round(a);
        if(a != (double)b) {
            answer = -1;
        } else {
            answer = (b+1)*(b+1);
        }
        return answer;
    }
}