import java.util.*;
import java.util.stream.*;
class Solution {
    public String solution(String number, int k) {
        Stack<Character> stack = new Stack<>();
        int len = number.length() - k; // 최종 결과 길이

        for (char num : number.toCharArray()) {
            // 현재 숫자가 Stack의 마지막 숫자보다 크면 제거 (앞 숫자가 작으면 뒤 숫자로 대체)
            while (!stack.isEmpty() && k > 0 && stack.peek() < num) {
                stack.pop();
                k--;
            }
            stack.push(num);
        }

        // 정답 문자열 만들기
        StringBuilder result = new StringBuilder();
        for (int i = 0; i < len; i++) {
            result.append(stack.get(i));
        }

        return result.toString();
    }
}
/*
class Solution {
    public String solution(String number, int k) {
        String answer = "";
        int maxIdx = 0;
        int max = 0;
        // 가장 큰 수 index 찾기
        for (int i = 0; i < number.length(); i++) {
            if (number.charAt(i) - '0' > max) {
                max = number.charAt(i) - '0';
                maxIdx = i;
            }
        }
        // 그 앞에 k개 이하로 있으면 가장 작은 숫자들부터 제거.
        if (maxIdx <= k) {
            String front = number.substring(0, maxIdx);
            // int[] num = front.split("").stream().mapToInt(Integer::parseInt).toArray();
            int[] num = front.chars().map(Character::getNumericValue).toArray();
            Arrays.sort(num);
            for (int i = 0; i < maxIdx; i++) {
                // front에서 num[i] 제거
                front = front.replaceFirst(Integer.toString(num[i]), "");
            }
            answer = front;
        }

        
        // k+1개 이상이면 그 앞에것들 제거하고 뒤에것들중에서 가장 작은 숫자들부터 제거.
        else if (maxIdx > k) {
            String back = number.substring(maxIdx);
            // int[] num = back.split("").stream().mapToInt(Integer::parseInt).toArray();
            int[] num = back.chars().map(Character::getNumericValue).toArray();
            Arrays.sort(num);
            for (int i = 0; i < maxIdx-k; i++) {
                // front에서 num[i] 제거
                back = back.replaceFirst(Integer.toString(num[i]), "");
            }
            answer = back;
        }
        
        return answer;
    }
}
*/