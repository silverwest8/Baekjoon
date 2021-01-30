import java.util.Scanner;

public class step3_8 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        for (int i = 1; i <= N ; i++) {
            int A = sc.nextInt();
            int B = sc.nextInt();
            System.out.format("Case #%d: %d + %d = %d\n", i, A, B, A+B);
        }
        sc.close();
    }
}