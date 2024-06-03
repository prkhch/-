import java.util.*;
import java.io.*;


public class Main {

	static int[][] graph = new int[101][101];
	static int[][] answer = new int[101][101];
	static boolean[] visit = new boolean[101];
	static int n;
	
	static void dfs(int START, int now) {
		
		for(int i=0; i<n; i++) {
			if(graph[now][i] == 1 && visit[i] == false) {
				answer[START][i] = 1;
				visit[i] = true;
				dfs(START, i);
			}
		}
		
	}
	
	public static void main(String[] args) throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		n = Integer.parseInt(br.readLine());
		for(int i=0; i<n; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			for(int j=0; j<n; j++) {
				graph[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		for(int i=0; i<n; i++) {
			visit = new boolean[n];
			dfs(i, i);
		}
		
		for(int i=0; i<n; i++) {
			for(int j=0; j<n; j++) {
				System.out.print(answer[i][j] + " ");
			}
			System.out.println();
		}
		
	}
}