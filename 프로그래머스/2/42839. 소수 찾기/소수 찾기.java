import java.util.*;

class Solution {
    static Set<Integer> numberSet = new HashSet<>();
    public int solution(String numbers) {
        int answer = 0;
        
        // 1. 모든 숫자 조합 생성
        boolean[] visited = new boolean[numbers.length()];
        generateNumbers(numbers, "", visited);

        // 2. 소수 판별 후 개수 세기
        int count = 0;
        for (int num : numberSet) {
            if (isPrime(num)) count++;
        }

        return count;
    }
    
    // 모든 조합을 만드는 재귀 함수
    private void generateNumbers(String numbers, String current, boolean[] visited) {
        if (!current.isEmpty()) {
            numberSet.add(Integer.parseInt(current)); // 만들어진 숫자를 Set에 추가
        }

        for (int i = 0; i < numbers.length(); i++) {
            if (!visited[i]) {
                visited[i] = true;
                generateNumbers(numbers, current + numbers.charAt(i), visited);
                visited[i] = false;
            }
        }
    }
    
    public boolean isPrime(int num) {
        if (num < 2) return false;
        for (int i = 2; i * i <= num; i++) {
            if (num % i == 0) return false;
        }
        return true;
    }
}