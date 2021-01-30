import java.util.Scanner;

public class step4_3 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int origin, num, plus, cycle;
        String num_str, plus_str;

        origin = sc.nextInt(); //26
        num = origin; // 26
        cycle = 0;

        do {
            if ( num < 10 ) {
                num_str = "0" + Integer.toString(num);
            } else {
                num_str = Integer.toString(num); //"26"
            }
            // System.out.format("num_str : %s\n", num_str);

            //plus = 2 + 6 = 8
            plus = Integer.parseInt(num_str.substring(0, 1)) + Integer.parseInt(num_str.substring(1, 2));
            // System.out.format("plus : %d\n", plus);
            
            if ( plus < 10 ) {
                plus_str = "0" + Integer.toString(plus);
            } else {
                plus_str = Integer.toString(plus); //"26"
            }
            // System.out.format("plus_str : %s\n", plus_str);

            num_str = num_str.substring(1, 2) + plus_str.substring(1,2);
            num = Integer.parseInt(num_str);
            cycle++;
            
        } while (num != origin);

        System.out.println(cycle);
        sc.close();
    }
}