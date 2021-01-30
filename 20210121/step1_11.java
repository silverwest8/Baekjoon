import java.util.Scanner;

public class step1_11 {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int i = sc.nextInt();
    int j = sc.nextInt(); // 300 + 80 + 5
    int a, b, c, rst;
    a = i * (j%10); j = (j - j%10)/10; //j = 38
    b = i * (j%10); j = (j - j%10)/10; // j = 3
    c = i * (j%10); j = (j - j%10)/10; // j = 0
    rst = a + b*10 + c*100;
    System.out.format("%d\n%d\n%d\n%d", a, b, c, rst);
    sc.close();
  }
}