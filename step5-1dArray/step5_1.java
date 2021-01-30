import java.util.Arrays;
import java.util.Scanner;

public class step5_1 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int[] arr = new int[N];
        for (int i = 0; i < N; i++) {
            arr[i] = sc.nextInt();
        }
        Arrays.sort(arr);
        System.out.format("%d %d", arr[0], arr[N-1]);
        sc.close();
    }
}
// Arrays.sort 안쓰고 풀기