import java.util.*;
import java.io.*;


public class Main {
	static int my[] = {-1, 1, 0 ,0, 0, 0};
	static int mx[] = {0, 0, -1, 1, 0, 0};
	static int mz[] = {0, 0, 0, 0, -1, 1};
	static int M, N, H;
	static Queue<int[]> q = new LinkedList<>();
	static int[][][] arr, visit;
	static int answer = 1;
	
	static void bfs() {
		while(!q.isEmpty()) {
			int[] tmt = q.poll();
			int z = tmt[0];
			int y = tmt[1]; 
			int x = tmt[2];
			
			for(int i=0; i<6; i++) {
				int nz = z + mz[i];
				int ny = y + my[i]; 
				int nx = x + mx[i];
				
				if(nz >= H || ny >= N || nx >= M || nz < 0 || ny < 0 || nx < 0) continue;
				if(arr[nz][ny][nx] == -1) continue;
				if(visit[nz][ny][nx] > 0) continue;
				
				visit[nz][ny][nx] = visit[z][y][x] + 1;
				if(visit[nz][ny][nx] > answer) answer = visit[nz][ny][nx];
				q.add(new int[] {nz, ny, nx});
			}
			
		}
		
	}
	
	public static void main(String[] args) throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		M = Integer.parseInt(st.nextToken());
		N = Integer.parseInt(st.nextToken());
		H = Integer.parseInt(st.nextToken());
		arr = new int[H][N][M];
        visit = new int[H][N][M];
		
		for(int i=0; i<H; i++) {
			for(int j=0; j<N; j++) {
				st = new StringTokenizer(br.readLine());
				for(int k=0; k<M; k++) {
					arr[i][j][k] = Integer.parseInt(st.nextToken());
					if(arr[i][j][k] == 1) {
						q.add(new int[] {i, j, k});
						visit[i][j][k] = 1;
					}
				}
			}
		}
		
		bfs();
		
		boolean check = false;
		for(int i=0; i<H; i++) {
			for(int j=0; j<N; j++) {
				for(int k=0; k<M; k++) {
					if(arr[i][j][k] == 0 && visit[i][j][k] == 0) {
						check = true;
						break;
					}
				}
				if(check) break;
			}
			if(check) break;
		}
		
		if(check) System.out.println("-1");
		else System.out.println(answer-1);
		
	}
}