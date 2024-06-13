import java.util.*;
import java.io.*;

public class Main {
	
	static int[] my = {-1,1,0,0};
	static int[] mx = {0,0,-1,1};
	
	static int N, M;
	static int[][] arr;
	static boolean[][][] visit;
	static int answer = Integer.MAX_VALUE;
	
	static void bfs() {
		
		LinkedList<int[]> q = new LinkedList<>();
		visit = new boolean[N][M][2];
		
		q.add(new int[] {0, 0, 0, 0}); // y, x, break, cnt
		visit[0][0][0] = true;
		
		while(!q.isEmpty()) {
			
			int[] now = q.poll();
			
			if(now[0] == N-1 && now[1] == M-1) {
				answer = Math.min(answer, now[3] + 1);
				return;
			}
			
			for(int i=0; i<4; i++) {
				int ny = now[0] + my[i];
				int nx = now[1] + mx[i];
				
				if(ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
				
				if(arr[ny][nx] == 1 && now[2] == 0 && !visit[ny][nx][1]) {
					visit[ny][nx][1] = true;
					q.add(new int[] {ny, nx, 1, now[3]+1});
				} else if(arr[ny][nx] == 0 && !visit[ny][nx][now[2]]) {
                    visit[ny][nx][now[2]] = true;
                    q.add(new int[] {ny, nx, now[2], now[3]+1});
                }
			}
			
		}
		
	}
	
	public static void main(String[] args) throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken()); 
		
		arr = new int[N][M];
		
		for(int i=0; i<N; i++) {
			String str = br.readLine();
			for(int j=0; j<M; j++) {
				arr[i][j] = str.charAt(j) - '0';
			}
		}
		
		bfs();
			
		System.out.println(answer == Integer.MAX_VALUE ? -1 : answer);
		
	}
	
}
