public class step6_2 {
    public static int selfNum(int constructor) {
        int total = constructor;
        String constructor_str = Integer.toString(constructor);
        for (int i = 0; i < constructor_str.length();i++) {
            total += constructor_str.charAt(i) - '0';
        }
        return total;
    }
    public static void main(String[] args) {
        //d(n)의 생성자 : n , 생성자가 없는 숫자 : 셀프 넘버
        //10000보다 작거나 같은 셀프 넘버 출력
        int i = 1;
        int[] arr = new int[10000+1];
        while (selfNum(i) <= 10000) {
            arr[selfNum(i)]++;
            i++;
        }
        for (int j = 1; j < arr.length-6; j++) {
            if (arr[j] == 0) {
                System.out.println(j);
            }
        }
    }
}
