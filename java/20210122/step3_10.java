import java.util.Scanner;

public class step3_10 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        for (int i = 1; i <= N ; i++) {
            for(int j = N-i; j > 0; j--) {
                System.out.print(" ");
            }
            for(int k = 1; k <= i; k++) {
                System.out.format("*");
            }
            System.out.println();
        }
        sc.close();
    }
}