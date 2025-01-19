class Solution {
    public String solution(String s) {
        String answer = "";
        String[] temp = s.split(" ");
        int min = Integer.parseInt(temp[0]);
        int max = Integer.parseInt(temp[0]);
        for (String str : temp) {
            int num = Integer.parseInt(str);
            if (min > num) {
                min = num;
            }
            if (max < num) {
                max = num;
            }
        }
        answer = Integer.toString(min) + " " + Integer.toString(max);
        return answer;
    }
}