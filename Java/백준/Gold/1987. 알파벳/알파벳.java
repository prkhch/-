import java.util.*;
import java.io.*;

public class Main {
	
	static int R, C;
	static char[][] arr;
	static boolean[] alphabet;
	static boolean[][] visit;
	static int[] my = {-1, 1, 0, 0};
	static int[] mx = {0, 0, -1, 1};
	static int answer;
	
	static void dfs(int y, int x, int cnt) {
		
		answer = Math.max(answer, cnt);

		for(int i=0; i<4; i++) {
			int ny = y + my[i];
			int nx = x + mx[i];
			
			if(ny < 0 || nx < 0 || ny >= R || nx >= C) continue;
			if(visit[ny][nx]) continue;
			
			if(alphabet[arr[ny][nx] - 'A']) {
				answer = Math.max(answer, cnt);
				continue;
			}
			
			alphabet[arr[ny][nx] - 'A'] = true;
			visit[ny][nx] = true;

			dfs(ny, nx, cnt+1);

			alphabet[arr[ny][nx] - 'A'] = false;
			visit[ny][nx] = false;
		}
		
		
	}
	
	public static void main(String[] args) throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		R = Integer.parseInt(st.nextToken());
		C = Integer.parseInt(st.nextToken());
		
		arr = new char[R][C];
		for(int i=0; i<R; i++) {
			String str = br.readLine();
			for(int j=0; j<C; j++) {
				arr[i][j] = str.charAt(j);
			}
		}
		
		visit = new boolean[R][C];
		visit[0][0] = true;
		
		alphabet = new boolean[26];
		alphabet[arr[0][0] - 'A'] = true;
		
		dfs(0, 0, 1);
		
		System.out.println(answer);
	}
	
}
