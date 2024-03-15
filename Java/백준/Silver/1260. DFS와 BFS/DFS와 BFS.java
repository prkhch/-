import java.util.*;
import java.io.*;

public class Main {
	
	static int N, M, V;
	static int[][] arr = new int[1001][1001];
	static boolean[] visited = new boolean[1001];
	
	static void init() {
		for(int i=1; i<=N; i++) {
			visited[i] = false;
		}
	}
	
	static void dfs(int node) {
		System.out.print(node + " ");
		
		for(int i=1; i<=N; i++) {
			if(arr[node][i] == 0) continue; 
			if(visited[i]) continue;
			visited[i] = true;
			dfs(i);
		}
	}
	
	static void bfs(int V) {
		ArrayDeque<Integer> dq = new ArrayDeque<>();
		dq.add(V);
		
		while(!dq.isEmpty()) {
			
			int node = dq.pollFirst();
			System.out.print(node + " ");
			
			for(int i=1; i<=N; i++) {
				if(arr[node][i] == 0) continue; 
				if(visited[i]) continue;
				visited[i] = true;
				dq.add(i);
			}
		}
	}
	
	public static void main(String[] args) throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		V = Integer.parseInt(st.nextToken());
		
		int a, b;
		for(int i=0; i<M; i++) {
			st = new StringTokenizer(br.readLine());
			a = Integer.parseInt(st.nextToken());
			b = Integer.parseInt(st.nextToken());
			arr[a][b] = 1;
			arr[b][a] = 1;
		}
		
		visited[V] = true;
		dfs(V);
		
		System.out.println();
		
		init();
		visited[V] = true;
		bfs(V);
		
	}
}