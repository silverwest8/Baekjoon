class Solution {
    public int solution(String t, String p) {
        int answer = 0;
        // p의 길이를 저장합니다.
        int pLength = p.length();
        
        // t에서 p의 길이만큼 부분 문자열을 추출하고 비교합니다.
        for (int i = 0; i <= t.length() - pLength; i++) {
            // t에서 시작 인덱스 i부터 p의 길이만큼 부분 문자열 추출
            String substring = t.substring(i, i + pLength);
            
            // 추출한 부분 문자열이 p보다 작거나 같은지 비교
            if (Long.parseLong(substring) <= Long.parseLong(p)) {
                answer++;
            }
        }
        return answer;
    }
}
