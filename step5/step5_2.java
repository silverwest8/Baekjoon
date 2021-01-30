import java.util.Scanner;

public class step5_2 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int num = 9;
		int[] arr = new int[9];
		for (int i = 0; i < num; i++) {
			arr[i] = sc.nextInt();
		}
		sc.close();
		int max = 0;
		int index = 0;
		
		for(int i = 0; i < num; i++) {
			if (arr[i] > max) {
				max = arr[i];
				index = i;
			}
		}
		System.out.format("%d\n%d", max, index+1);
	}
}