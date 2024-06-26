import java.util.*;
import java.io.*;

public class Main {
	
	static int N;
	static char arr[][];
	static boolean visit[][];
	
	static int my[] = {-1,1,0,0};	
	static int mx[] = {0,0,-1,1};
	
	static void dfs(int y, int x, char color) {
		
		for(int i=0; i<4; i++) {
			int ny = y + my[i];
			int nx = x + mx[i];
			
			if(ny < 0 || nx < 0 || nx >= N || ny >= N) continue;
			if(visit[ny][nx]) continue;
			if(arr[ny][nx] != color) continue;
			visit[ny][nx] = true;
			dfs(ny, nx, color);
		}
		
	}
	
	public static void main(String[] args) throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		N = Integer.parseInt(br.readLine());
		
		arr = new char[N][N];
		visit = new boolean[N][N];
		
		for(int i=0; i<N; i++) {
			String st = br.readLine();
			for(int j=0; j<N; j++) {
				arr[i][j] = st.charAt(j);
			}
		}
		
		int answer1 = 0;
		
		for(int i=0; i<N; i++) {
			for(int j=0; j<N; j++) {
				if(visit[i][j]) continue;
				visit[i][j] = true;
				answer1++;
				dfs(i, j, arr[i][j]);
			}
		}
		
		
		int answer2 = 0;
		visit = new boolean[N][N];
		
		for(int i=0; i<N; i++) {
			for(int j=0; j<N; j++) {
				if(arr[i][j] == 'R' || arr[i][j] == 'G') {
					arr[i][j] = 'Y';
				}
			}
		}
		
		for(int i=0; i<N; i++) {
			for(int j=0; j<N; j++) {
				if(visit[i][j]) continue;
				visit[i][j] = true;
				answer2++;
				dfs(i, j, arr[i][j]);
			}
		}
		
		System.out.println(answer1 + " " + answer2);
		
	}
	
}
