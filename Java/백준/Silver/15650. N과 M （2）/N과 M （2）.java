import java.util.*;
import java.io.*;


public class Main {
	
	static int N, M;
	static int[] answer = new int[9];
	
	static void run(int now, int lv) {
		
		if(lv == M) {
			for(int i=0; i<M; i++) {
				System.out.print(answer[i] + " ");
			}
			System.out.println();
			return;
		}
		
		for(int i=now+1; i<=N; i++) {
			answer[lv] = i;
			run(i, lv+1);
		}
		
	}
	
	
	public static void main(String[] args) throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		
		run(0, 0);
	}
}