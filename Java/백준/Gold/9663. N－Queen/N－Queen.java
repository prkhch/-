import java.util.*;
import java.io.*;

public class Main {
	
	static int[] arr;
	static int N;
	static int answer;
	
	static boolean check(int col) {
		
		for(int i=0; i<col; i++) {
			if(arr[i] == arr[col]) return false;
			if(Math.abs(arr[col]-arr[i]) == Math.abs(col-i)) return false;
		}
		
		return true;
		
	}
	
	static void dfs(int lv) {
		
		
		if(lv == N) {
			answer++;
			return;
		}
		
		for(int i=0; i<N; i++) {
			arr[lv] = i;
			if(check(lv)) dfs(lv+1);
		}

		
	}
	
	public static void main(String[] args) throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		N = Integer.parseInt(br.readLine());
		
		arr = new int[N];
		
		dfs(0);
		
		System.out.println(answer);
		
	}
	
}
