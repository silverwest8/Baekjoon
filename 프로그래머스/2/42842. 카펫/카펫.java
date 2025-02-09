class Solution {
    public int[] solution(int brown, int yellow) {
        int[] answer = new int[2];
        int r = 0;
        int c = 0;
        // r*2 + c*2 - 4 = brown
        // (r-2) * (c-2) = yellow
        
        for (int i = 3; i < 3000; i++) {
            for (int j = i; j < 2000000; j++) {
                if (j*2 + i*2 == brown + 4 && j*i - 2*j - 2*i + 4 == yellow) {
                    r = j;
                    c = i;
                    answer[0] = r;
                    answer[1] = c;
                    return answer;
                }
            }
        }
        
        answer[0] = r;
        answer[1] = c;
        return answer;
    }
}