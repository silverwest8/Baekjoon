class Solution {
    public String solution(String s) {
        String answer = "";
        boolean flag = true;
        for (int i = 0; i < s.length(); i++) {
            if (s.substring(i, i+1).equals(" ")) {
                answer += " ";
                flag = true;
            } else {
                if (flag) {
                    answer += s.substring(i, i+1).toUpperCase();
                    flag = false;
                } else {
                    answer += s.substring(i, i+1).toLowerCase();
                }
            }
        }
        return answer;
    }
}