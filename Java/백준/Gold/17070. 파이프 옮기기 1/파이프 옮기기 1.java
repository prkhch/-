import java.util.*;
import java.io.*;

public class Main {
	
	static int N;
	static int[][] arr;
	static int answer;
	
	static void dfs(int r, int c, int dir) {
		
		// return
		if(r == N && c == N) {
			answer++;
			return;
		}
		
		// 가로
		if(dir == 0) {
			if(c+1 <= N && arr[r][c+1] != 1) {
				dfs(r, c+1, 0); // 가로 옮기기
			}
			
			if(r+1 <= N && c+1 <= N && arr[r][c+1] != 1 && arr[r+1][c+1] != 1 && arr[r+1][c] != 1) {
				dfs(r+1, c+1, 2); // 대각 옮기기
			}
			
		}
		
		// 세로
		else if(dir == 1) {
			if(r+1 <= N && arr[r+1][c] != 1) {
				dfs(r+1, c, 1); // 세로 옮기기
			}
			
			if(r+1 <= N && c+1 <= N && arr[r][c+1] != 1 && arr[r+1][c+1] != 1 && arr[r+1][c] != 1) {
				dfs(r+1, c+1, 2); // 대각 옮기기
			}
		}
		
		// 대각
		else if(dir == 2) {
			if(c+1 <= N && arr[r][c+1] != 1) {
				dfs(r, c+1, 0); // 가로 옮기기
			}
			
			if(r+1 <= N && arr[r+1][c] != 1) {
				dfs(r+1, c, 1); // 세로 옮기기
			}
			
			if(r+1 <= N && c+1 <= N && arr[r][c+1] != 1 && arr[r+1][c+1] != 1 && arr[r+1][c] != 1) {
				dfs(r+1, c+1, 2); // 대각 옮기기
			}
		}
		
	}
	
	public static void main(String[] args) throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		N = Integer.parseInt(st.nextToken());
		
		arr = new int[N+1][N+1];
		for(int i=1; i<=N; i++) {
			st = new StringTokenizer(br.readLine());
			for(int j=1; j<=N; j++) {
				arr[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		
		dfs(1, 2, 0);
		
		System.out.println(answer);
	}
	
}
