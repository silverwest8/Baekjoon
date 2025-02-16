class Solution {
    public boolean checkgo(boolean[] check) {
        for (int i = 1; i < check.length; i++) {
            if (check[i]) {
                return true;
            }
        }
        return false;
    }
    public int solution(String name) {
        int answer = 0;
        int n = name.length();
        boolean[] check = new boolean[n];
        
        for (int i = 0; i < name.length(); i++) {
            int temp1 = name.charAt(i)-'A';
            int temp2 = 'Z'-name.charAt(i)+1;
            answer+=Math.min(temp1, temp2);
            if (temp1 != 0) {
                check[i] = true;
            }
        }
        // 2. 커서 이동 최소화
        int minMove = n - 1; // 기본적으로 끝까지 가는 경우 (→ 방향)

        for (int i = 0; i < n; i++) {
            int next = i + 1;

            // 연속된 'A' 구간 찾기
            while (next < n && name.charAt(next) == 'A') {
                next++;
            }

            // 왼쪽으로 갔다가 다시 돌아오는 경우 고려
            int leftRightMove = (i * 2) + (n - next);
            int rightLeftMove = (n - next) * 2 + i;

            // 최소 이동 횟수 갱신
            minMove = Math.min(minMove, Math.min(leftRightMove, rightLeftMove));
        }

        answer += minMove;
            
        return answer;
    }
}