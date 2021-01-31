import java.util.Scanner;

public class step7_6 {
    public static void main(String[] args) {
        // Scanner sc = new Scanner(System.in);
        // String str = sc.nextLine().trim();
        // StringBuilder sb = new StringBuilder(str);
        // sb.append(" ");
        // // System.out.println(sb);
        // int count = 0;
        // for (int i = 0; i < sb.length(); i++) {
        //     if (sb.charAt(i) == ' ') {
        //         count++;
        //     }
        // }
        // System.out.println(count);
        // sc.close();

        Scanner sc = new Scanner(System.in);
        StringBuilder sb = new StringBuilder(sc.nextLine().trim());
        String str = sb.append(" ").toString();
        String[] arr = str.split(" ");
        int count = arr.length;
        System.out.println(count);
        sc.close();
    }
}