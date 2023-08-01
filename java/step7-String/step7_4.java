import java.util.Scanner;

public class step7_4 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int testNum = sc.nextInt();
        for (int i = 0; i < testNum; i++) {
            int repeat = sc.nextInt();
            // System.out.format("repeat : %d\n", repeat);
            String words = sc.nextLine().trim();
            // System.out.format("words : %s\n", words);
            StringBuilder new_words = new StringBuilder("");
            for (int j = 0; j < words.length(); j++) {
                // System.out.format("sysout wrods.charAt(%d) : %c\n", j, words.charAt(j));
                for (int k = 0; k < repeat; k++) {
                    new_words.append(words.charAt(j));
                }
            }
            System.out.println(new_words);
        }
        sc.close();
    }
}
