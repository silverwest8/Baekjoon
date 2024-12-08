class Solution {
    public int[] solution(long n) {
        int[] answer = {};
        Long N = n;
        String s = N.toString();
        answer = new int[s.length()];
        for (int i = 0; i < s.length(); i++) {
            answer[s.length()-1-i] = s.charAt(i) - '0';
        }
        return answer;
    }
}