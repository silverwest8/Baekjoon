import java.util.Scanner;

public class step5_6 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int num = Integer.parseInt(sc.nextLine());
        for (int i = 0; i < num; i++) { //num 번 반복
            String ox = sc.nextLine();  //ox 문자열 선언, 입력
            int[] points = new int[ox.length()];    //점수 저장할 배열 선언
            for (int j = 0; j < ox.length(); j++) {
                int point = 1;
                while ( ox.charAt(j) == 'O') {
                    points[j] = point;
                    j++;
                    point++;
                    if (j == ox.length()) {
                        break;
                    }
                }
            }
            int total = 0;
            for (int j = 0; j < ox.length(); j++) {
                total += points[j];
            }
            System.out.println(total);
        }
        sc.close();
    }
}
