import java.util.Scanner;

public class step3_1 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        for (int i = 1; i < 10; i++) {
            System.out.format("%d * %d = %d\n", N, i, N*i);
        }
        sc.close();
    }
}
