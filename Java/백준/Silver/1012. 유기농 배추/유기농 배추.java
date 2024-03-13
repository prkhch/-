import java.io.BufferedReader;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	
	static int M, N, K;
	static int[][] arr = new int[51][51];
	static int[][] visited = new int[51][51];
	static int cnt;
	
	static int[] dir_x = {-1,1,0,0};
	static int[] dir_y = {0,0,-1,1};
	
	static void dfs(int X, int Y) {
		if(arr[X][Y] == 0) return;
		if(visited[X][Y] == 1) return;
		visited[X][Y] = 1;
		
		for(int i=0; i<4; i++) {
			int move_x = dir_x[i] + X;
			int move_y = dir_y[i] + Y;
			if(move_x >= M || move_y >= N || move_x < 0 || move_y < 0) continue;
			dfs(move_x, move_y);
		}
		
	}
	
	public static void main(String[] args) throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());
		
		int X, Y;
		for(int i=0; i<T; i++) {
			
			StringTokenizer st = new StringTokenizer(br.readLine());
			M = Integer.parseInt(st.nextToken());
			N = Integer.parseInt(st.nextToken());
			K = Integer.parseInt(st.nextToken());
			
			cnt = 0;
			for(int j=0; j<M; j++) {
				for(int k=0; k<N; k++) {
					arr[j][k] = 0;
					visited[j][k] = 0;
				}
			}
			
			for(int j=0; j<K; j++) {
				st = new StringTokenizer(br.readLine());
				X = Integer.parseInt(st.nextToken());
				Y = Integer.parseInt(st.nextToken());
				arr[X][Y] = 1;
			}
			
			
			for(int j=0; j<M; j++) {
				for(int k=0; k<N; k++) {
					if(arr[j][k] == 1 && visited[j][k] == 0) {
						cnt++;
						dfs(j, k);
					}
				}
			}
			
			System.out.println(cnt);
				
		}
	
	}
}
