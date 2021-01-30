import java.util.Scanner;

public class step7_1 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        byte[] C = sc.nextLine().getBytes();
        System.out.println(C[0]);
        sc.close();
    }
}