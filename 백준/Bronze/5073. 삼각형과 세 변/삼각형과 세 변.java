import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);

    String Equilateral = "Equilateral";
    String Isosceles = "Isosceles";
    String Scalene = "Scalene";
    String Invalid = "Invalid";
    while(true) {

      int num1 = sc.nextInt();
      int num2 = sc.nextInt();
      int num3 = sc.nextInt();

      if (num1 == 0 && num2 == 0 && num3 == 0) {
        break;
      }

      // 가장 긴 변의 길이보다 나머지 두 변의 길이의 합이 길지 않으면 삼각형의 조건을 만족하지 못한다.
      if (num1 >= num2 + num3 || num2 >= num1 + num3 || num3 >= num1 + num2) {
        System.out.println(Invalid);
      } else if (num1 == num2 && num2 == num3) {
        System.out.println(Equilateral);
      } else if (num1 == num2 || num2 == num3 || num1 == num3) {
        System.out.println(Isosceles);
      } else if (num1 != num2 && num2 != num3 && num1 != num3) {
        System.out.println(Scalene);
      }
    }
    sc.close();
  }
}