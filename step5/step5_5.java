import java.util.Scanner;

public class step5_5 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int subjectNum = sc.nextInt();
        int[] points = new int[subjectNum];
        double[] newPoints = new double[subjectNum];

        for (int i = 0; i < subjectNum; i++) {
            points[i] = sc.nextInt();
        }
        sc.close();

        int max = 0;
        for (int point : points) {
            if (point > max) {
                max = point;
            }
        }

        double total = 0;
        for (int i = 0; i < subjectNum; i++) {
            newPoints[i] = (double)points[i] / max * 100;
            total += newPoints[i];
        }

        double avg = total / subjectNum;
        System.out.println(avg);
    }
}
