class Solution {
    public String solution(String s) {
        String answer = "";
        int temp = (s.length()-1) / 2;
        int temp2 = temp+1;
        if (s.length() % 2 == 0) {
            temp2++;
        }
        answer = s.substring(temp, temp2);
        return answer;
    }
}