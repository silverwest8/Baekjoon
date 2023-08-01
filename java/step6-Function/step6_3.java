import java.util.Scanner;

public class step6_3 {
    public static boolean Hansu(int num) {
        String num_str = Integer.toString(num);
        if (num_str.length() == 1 || num_str.length() == 2) {
            return true;
        }
        else {
            for (int i = 0; i+1 < num_str.length(); i++) {
                int difference = (num_str.charAt(0)-'0') - (num_str.charAt(1)-'0');
                if ((num_str.charAt(i)-'0') - (num_str.charAt(i+1)-'0') != difference) {
                    return false;
                }
            }
            return true;
        }
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int count = 0;
        for (int i = 1; i <= N; i++) {
            if (Hansu(i)) {
                count++;
            }
        }
        System.out.println(count);
        sc.close();
    }
}
