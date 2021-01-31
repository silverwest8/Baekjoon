import java.util.Scanner;

public class step7_3 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String word = sc.nextLine();
        sc.close();
        for (int i = 97; i < 97+26; i++) {
            char C = (char)i;
            System.out.print(word.indexOf(C)+" "); 
        }
    }
}
