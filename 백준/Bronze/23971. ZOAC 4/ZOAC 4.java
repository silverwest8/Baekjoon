import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int answer = 0;
    int H = sc.nextInt();
    int W = sc.nextInt();
    int N = sc.nextInt();
    int M = sc.nextInt();

    for (int i = 0; i < H; i+=(N+1)) {
      for (int j = 0; j < W; j+=(M+1)) {
        answer++;
      }
    }
    System.out.println(answer);
    sc.close();
  }
}