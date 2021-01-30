import java.util.Scanner;

public class step3_11 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int X = sc.nextInt();
        for (int i = 0; i < N; i++) {
            int a = sc.nextInt();
            if (a < X) {
                System.out.format("%d ", a);
            }
        }
        sc.close();
    }
}