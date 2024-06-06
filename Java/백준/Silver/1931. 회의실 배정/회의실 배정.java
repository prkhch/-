import java.util.*;
import java.io.*;


public class Main {
	
	public static void main(String[] args) throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int N = Integer.parseInt(br.readLine());
		
		int arr[][] = new int[N][2];
		
		for(int i=0; i<N; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			arr[i][0] = Integer.parseInt(st.nextToken());
			arr[i][1] = Integer.parseInt(st.nextToken());
		}
		
		Arrays.sort(arr, new Comparator<int[]>() {
			@Override
			public int compare(int[] a, int[] b) {
				if(a[1] == b[1]) {
					return a[0] - b[0];
				} else {
					return a[1] - b[1];
				}
			}
		});
		
		int answer = 0;
		int ed = -1;
		
		for(int i=0; i<N; i++) {
			if(arr[i][0] >= ed) {
				answer++;
				ed = arr[i][1];
			}
		}
		System.out.println(answer);
	}
}