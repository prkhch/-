import java.util.*;
import java.io.*;


public class Main {
	static int my[] = {-1, 1, 0 ,0};
	static int mx[] = {0, 0, -1, 1};
	static int M, N;
	static Queue<int[]> q = new LinkedList<>();
	static int[][] arr;
	static int[][] visit;
	static int answer = 1;
	
	static void bfs() {
		while(!q.isEmpty()) {
			int[] tmt = q.poll();
			int y = tmt[0]; 
			int x = tmt[1];
			
			for(int i=0; i<4; i++) {
				int ny = y + my[i]; 
				int nx = x + mx[i];
				
				if(ny >= N || nx >= M || ny < 0 || nx < 0) continue;
				if(arr[ny][nx] == -1) continue;
				if(visit[ny][nx] > 0) continue;
				
				visit[ny][nx] = visit[y][x] + 1;
				if(visit[ny][nx] > answer) answer = visit[ny][nx];
				q.add(new int[] {ny, nx});
			}
			
		}
		
	}
	
	public static void main(String[] args) throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		M = Integer.parseInt(st.nextToken());
		N = Integer.parseInt(st.nextToken());
		arr = new int[N][M];
        visit = new int[N][M];
		
		for(int i=0; i<N; i++) {
			st = new StringTokenizer(br.readLine());
			for(int j=0; j<M; j++) {
				arr[i][j] = Integer.parseInt(st.nextToken());
				if(arr[i][j] == 1) {
					q.add(new int[] {i, j});
					visit[i][j] = 1;
				}
			}
		}
		
		bfs();
		
		boolean check = false;
		for(int i=0; i<N; i++) {
			for(int j=0; j<M; j++) {
				if(arr[i][j] == 0 && visit[i][j] == 0) {
					check = true;
					break;
				}
			}
			if(check) break;
		}
		
		if(check) System.out.println("-1");
		else System.out.println(answer-1);
		
	}
}