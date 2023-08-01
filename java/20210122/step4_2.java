import java.util.Scanner;

public class step4_2 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println(sc.hasNextInt());
        while ( sc.hasNextInt() ) {
            int A = sc.nextInt();
            int B = sc.nextInt();
            System.out.println(A+B);
        }
        sc.close();
    }
}