import java.util.Scanner;

public class step7_7 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String A_str = Integer.toString(sc.nextInt());
        String B_str = Integer.toString(sc.nextInt());
        int A_rvs = Integer.parseInt(new StringBuilder(A_str).reverse().toString());
        int B_rvs = Integer.parseInt(new StringBuilder(B_str).reverse().toString());
        System.out.println(A_rvs > B_rvs ? A_rvs : B_rvs);
        sc.close();
    }
}
