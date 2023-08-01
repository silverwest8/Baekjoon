import java.util.Scanner;

public class step2_3 {
    public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
        int year = sc.nextInt();
        int isLeap = 0;
        if (year%4 == 0 && year %100 != 0) {
            isLeap = 1;
        }
        else if (year % 400 == 0) {
            isLeap = 1;
        }
        System.out.format("%d", isLeap);
        sc.close();
    }
}
