import java.util.*;
import java.io.*;


public class Main {

	static char arr[][] = new char[601][601];
	static boolean visit[][] = new boolean[601][601];
	static int n, m, cnt;
	static int[] my = {-1, 1, 0, 0};
	static int[] mx = {0, 0, -1, 1};
	
	static void run(int y, int x) {
		
		if(arr[y][x] == 'P') cnt++;
		
		for(int i=0; i<4; i++) {
			int ny = my[i] + y;
			int nx = mx[i] + x;
			if(ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
			if(visit[ny][nx] == true) continue;
			if(arr[ny][nx] == 'X') continue;
			visit[ny][nx] = true;
			run(ny, nx);
		}
	}
	
	public static void main(String[] args) throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		
		for(int i=0; i<n; i++) {
			String row = br.readLine();
			for(int j=0; j<m; j++) {
				arr[i][j] = row.charAt(j);
			}
		}
				
		for(int i=0; i<n; i++) {
			for(int j=0; j<m; j++) {
				if(arr[i][j] == 'I') {
					visit[i][j] = true;
					run(i, j);
				}
			}
		}
		
		if(cnt == 0) System.out.println("TT");
		else System.out.println(cnt);
	}
}