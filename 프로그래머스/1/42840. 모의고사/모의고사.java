import java.util.*;

class Solution {
    public int[] solution(int[] answers) {
        // 점수 초기화
        int[] a_ = {1, 2, 3, 4, 5};
        int[] b_ = {2, 1, 2, 3, 2, 4, 2, 5};
        int[] c_ = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
        
        int a = 0, b = 0, c = 0;
        
        // 답안 체크
        for (int i = 0; i < answers.length; i++) {
            if (answers[i] == a_[i % 5]) a++;
            if (answers[i] == b_[i % 8]) b++;
            if (answers[i] == c_[i % 10]) c++;
        }
        
        // 최댓값 구하기
        int max = Math.max(a, Math.max(b, c));
        
        // 최댓값을 가진 사람들 수 확인
        List<Integer> result = new ArrayList<>();
        if (a == max) result.add(1);
        if (b == max) result.add(2);
        if (c == max) result.add(3);
        
        // 결과 리스트를 배열로 변환
        return result.stream().mapToInt(i -> i).toArray();
    }
}