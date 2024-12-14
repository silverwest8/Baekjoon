class Solution {
    public int solution(int num) {
        int answer = 0;
        if (num == 1) {
            return 0;
        }
        long n = num;
        int i = 0;
        while (i < 500 && n != 1) {
            if (n % 2 == 0) {
                n /= 2;
            } else {
                n = n * 3 + 1;
            }
            i++;
        }
        answer = n == 1 ? i : -1;
        return answer;
    }
}