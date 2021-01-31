import java.util.Scanner;

public class step7_5 {
    public static char print(int[] arr, int max, char mod) {
        char rst;
        for(int i = 0; i < arr.length; i++) {
            if (arr[i] == max && (int)mod-65 != i) {
                rst = '?';
                return rst;
            }
        }
        rst = mod;
        return rst;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        //알파벳 개수대로 싹 돌려보는 방법(좀 무식하게 일일이)
        String words = sc.nextLine().toUpperCase();
        int[] arr = new int[26];
        for (int i = 0; i < words.length(); i++) {
            arr[(int)words.charAt(i)-65]++;
        }
        // System.out.println(words);
        int max = 0;
        char mod = '?';
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] > max) {
                max = arr[i];
                mod = (char)(i+65);
            }
        }
        // System.out.println(mod);
        char rst = print(arr, max, mod);
        System.out.println(rst);
        sc.close();
    }
}
