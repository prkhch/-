import java.util.*;
import java.io.*;


public class Main {
	
	static int n, answer;
	
	static void dfs(int now) {
		
		if(now == n) {
			answer++;
			return;
		}
		
		if(now > n) return;
		
		for(int i=1; i<=3; i++) {
			dfs(now+i);
		}
	}

	public static void main(String[] args) throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int T = Integer.parseInt(br.readLine());
		
		for(int i=0; i<T; i++) {
			n = Integer.parseInt(br.readLine());
			answer = 0;
			dfs(0);
			System.out.println(answer);
		}
		
	}
}