import java.util.Scanner;

public class step7_2 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        sc.nextLine();
        String num_str = sc.nextLine();
        sc.close();
        int total = 0;
        for (int i = 0; i < N; i++) {
            total += num_str.charAt(i) - '0';
        }
        System.out.println(total);
    }
}
