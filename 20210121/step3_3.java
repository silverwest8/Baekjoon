import java.util.Scanner;

public class step3_3 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int rst = 0;
        for (int i = 1; i <= n; i++) {
            rst += i;
        }
        System.out.println(rst);
        sc.close();
    }   
}
