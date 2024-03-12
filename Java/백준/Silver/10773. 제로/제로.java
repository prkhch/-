import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;

public class Main {

	public static void main(String[] args) throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int K = Integer.parseInt(br.readLine());
		
		int[] arr = new int[100001];
		
		int num;
		int idx = 0;
		
		for(int i=0; i<K; i++) {
			num = Integer.parseInt(br.readLine());
			if(num == 0) {
				arr[idx] = 0;
				idx--;
			}
			else {
				arr[idx] = num;
				idx++;
			}
		}
		
		int sum = 0;
		for(int i=0; i<idx; i++) {
			sum += arr[i];
		}
		
		System.out.print(sum);

	}
}
