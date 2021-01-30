import java.util.Scanner;

public class step5_7 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int C = sc.nextInt();
        for (int i = 0; i < C; i++) {
            int N = sc.nextInt();
            int[] points = new int[N];
            int total = 0;
            for (int j = 0; j < N; j++) {
                points[j] = sc.nextInt();
                total += points[j];
            }

            double avg = (double)total / N;
            int count = 0;
            for (int j = 0; j < N; j++) {
                if (points[j] > avg) {
                    count++;
                }
            }
            double rst = (double)count / N * 100;
            System.out.println(String.format("%.3f", rst) + "%");
        }
        sc.close();
    }
}
