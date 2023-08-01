import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

//숫자의 개수
public class step5_3 {
    public static void main(String[] args) throws NumberFormatException, IOException {
        // Scanner sc = new Scanner(System.in);
        // int A = sc.nextInt();
        // int B = sc.nextInt();
        // int C = sc.nextInt();
        // sc.close();
        // int rst = A*B*C;
        // String nums = Integer.toString(rst);
        // // System.out.println(nums);
        // for (int j = 0; j < 10; j++) {
        //     int count = 0;
        //     for (int i = 0; i < nums.length(); i++) {
        //         if (nums.charAt(i) - '0' == j) {
        //             count++;
        //         }
        //     }
        //     System.out.println(count);
        // }
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int A = Integer.parseInt(br.readLine());
        int B = Integer.parseInt(br.readLine());
        int C = Integer.parseInt(br.readLine());
        int rst = A*B*C;
        int[] arr = new int[10];
        String nums = String.valueOf(rst);
        for (int i = 0; i < nums.length(); i++) {
            arr[nums.charAt(i)-'0']++;
        }
        for(int i = 0; i < 10; i++) {
            System.out.println(arr[i]);
        }
    }
}
