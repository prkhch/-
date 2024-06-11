import java.util.*;
import java.io.*;

public class Main {
	
	static int N, M;
	static int arr[][];
	static boolean usedWall[][];
	
	static int[] my = {-1, 1, 0, 0};
	static int[] mx = {0, 0, -1, 1};
	
	static int answer = -1;
	
	static void bfs() {
		
		LinkedList<int[]> q = new LinkedList<>();
		
		for(int i=0; i<N; i++) {
			for(int j=0; j<M; j++) {
				if(arr[i][j] == 2) {
					q.add(new int[] {i, j});
				}
			}
		}
		
		while(!q.isEmpty()) {
			int[] now = q.poll();
			
			for(int i=0; i<4; i++) {
				int ny = now[0] + my[i];
				int nx = now[1] + mx[i];
				
				if(ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
				if(arr[ny][nx] != 0) continue;
				if(usedWall[ny][nx] == true) continue;
				arr[ny][nx] = 2;
				q.add(new int[] {ny, nx});
			}
		}
		
	}
	
	static void dfs(int wallCount) {
		
		if(wallCount == 3) {
			int[][] copyArr = new int[N][M];
			
			for(int i=0; i<N; i++) {
				for(int j=0; j<M; j++) {
					copyArr[i][j] = arr[i][j];
				}
			}
			
			bfs();
			int cnt = 0;
			for(int i=0; i<N; i++) {
				for(int j=0; j<M; j++ ) {
					if(arr[i][j] == 0) cnt++;
				}
			}
			
			answer = Integer.max(answer, cnt);
			
			for(int i=0; i<N; i++) {
				for(int j=0; j<M; j++) {
					arr[i][j] = copyArr[i][j];
				}
			}
			
			return;
		}
		
		for(int i=0; i<N; i++) {
			for(int j=0; j<M; j++) {
				if(usedWall[i][j] == true) continue;
				if(arr[i][j] == 1 || arr[i][j] == 2) continue;
				usedWall[i][j] = true;
				dfs(wallCount+1);
				usedWall[i][j] = false;
			}
		}
	}
	
	public static void main(String[] args) throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		
		arr = new int[N][M];
		usedWall = new boolean[N][M];
		
		for(int i=0; i<N; i++) {
			st = new StringTokenizer(br.readLine());
			for(int j=0; j<M; j++) {
				arr[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		
		dfs(0);
		
		System.out.println(answer-3);
		
	}
	
}
