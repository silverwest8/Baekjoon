import java.util.Scanner;

public class step2_5 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int H = sc.nextInt(); int M = sc.nextInt();
        int alarm_H = H; int alarm_M = M;
        if (alarm_M >= 45) {
            alarm_M -= 45;
        }
        else {
            alarm_M += 15;
            if (alarm_H != 0) {
                alarm_H -= 1;
            }
            else {
                alarm_H = 23;
            }
        }
        System.out.format("%d %d", alarm_H, alarm_M);
        sc.close();
    }
}
