import java.util.Scanner;

public class step2_4 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int x = sc.nextInt();
        int y = sc.nextInt();
        int quad;
        if (x > 0 && y > 0) {
            quad = 1;
        }
        else if (x < 0 && y > 0) {
            quad = 2;
        }
        else if (x < 0 && y < 0) {
            quad = 3;
        }
        else {
            quad = 4;
        }
        System.out.println(quad);
        sc.close();
    }
}
