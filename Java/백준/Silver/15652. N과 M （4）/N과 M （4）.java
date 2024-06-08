import java.util.*;
import java.io.*;

public class Main {
	
	static int N, M;
	static int answer[];
	
	static void run(int num, int lv) {
		
		if(lv > M) {
			for(int i=1; i<=M; i++) {
				System.out.print(answer[i] + " ");
			}
			System.out.println();
			return;
		}
		
		for(int i=num; i<=N; i++) {
			answer[lv] = i;
			run(i, lv+1);
		}
	}
	
	public static void main(String[] args) throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		
		answer = new int[M+1];
		
		run(1, 1);
		
	}
	
}