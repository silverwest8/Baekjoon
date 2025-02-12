import java.util.*;

class Solution {
    static String[] vowels = {"A", "E", "I", "O", "U"};
    static List<String> dictionary = new ArrayList<>();

    public int solution(String word) {
        // 1. 모든 단어를 DFS로 생성
        generateWords("", 0);
        // 2. 단어 리스트에서 word의 위치 찾기
        return dictionary.indexOf(word);
    }

    private void generateWords(String current, int length) {
        if (length > 5) return;
        
        dictionary.add(current); // 단어 저장
        
        for (String v : vowels) {
            generateWords(current + v, length + 1);
        }
    }
}
/*
class Solution {
    public int solution(String word) {
        int[] weight = {781, 156, 31, 6, 1}; // 자리별 가중치
        String vowels = "AEIOU";
        int answer = 0;

        for (int i = 0; i < word.length(); i++) {
            int index = vowels.indexOf(word.charAt(i));
            answer += index * weight[i] + 1;
        }
        return answer;
    }
}
*/