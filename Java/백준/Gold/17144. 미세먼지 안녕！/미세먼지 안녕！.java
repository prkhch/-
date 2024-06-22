import java.util.*;
import java.io.*;

public class Main {
	
	static int R, C, T;
	static int[][] arr;
	static int[] my = {-1, 1, 0, 0};
	static int[] mx = {0, 0, -1, 1};
	
	static int upperAirCleaner;
	static int lowerAirCleaner;
 	
	static void circulate() {
		// 위쪽 공기청정기 (반시계방향)
		for(int i = upperAirCleaner - 1; i > 0; i--) {
			arr[i][0] = arr[i-1][0];
		}
		for(int j = 0; j < C - 1; j++) {
			arr[0][j] = arr[0][j+1];
		}
		for(int i = 0; i < upperAirCleaner; i++) {
			arr[i][C-1] = arr[i+1][C-1];
		}
		for(int j = C - 1; j > 1; j--) {
			arr[upperAirCleaner][j] = arr[upperAirCleaner][j-1];
		}
		arr[upperAirCleaner][1] = 0;

		// 아래쪽 공기청정기 (시계방향)
		for(int i = lowerAirCleaner + 1; i < R - 1; i++) {
			arr[i][0] = arr[i+1][0];
		}
		for(int j = 0; j < C - 1; j++) {
			arr[R-1][j] = arr[R-1][j+1];
		}
		for(int i = R - 1; i > lowerAirCleaner; i--) {
			arr[i][C-1] = arr[i-1][C-1];
		}
		for(int j = C - 1; j > 1; j--) {
			arr[lowerAirCleaner][j] = arr[lowerAirCleaner][j-1];
		}
		arr[lowerAirCleaner][1] = 0;
	}
	
	static void simulate() {
		for(int t = 0; t < T; t++) {
			int[][] temp = new int[R][C];
			for(int i = 0; i < R; i++) {
				for(int j = 0; j < C; j++) {
					if(arr[i][j] > 0) {
						int spreadAmount = arr[i][j] / 5;
						int spreadCount = 0;
						for(int k = 0; k < 4; k++) {
							int ny = i + my[k];
							int nx = j + mx[k];
							if(ny >= 0 && ny < R && nx >= 0 && nx < C && arr[ny][nx] != -1) {
								temp[ny][nx] += spreadAmount;
								spreadCount++;
							}
						}
						temp[i][j] += arr[i][j] - spreadAmount * spreadCount;
					} else if(arr[i][j] == -1) {
						temp[i][j] = -1;
					}
				}
			}
			arr = temp;
			circulate();
		}
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		R = Integer.parseInt(st.nextToken());
		C = Integer.parseInt(st.nextToken());
		T = Integer.parseInt(st.nextToken());
		
		arr = new int[R][C];
		boolean firstAC = false;
		for(int i = 0; i < R; i++) {
			st = new StringTokenizer(br.readLine());
			for(int j = 0; j < C; j++) {
				int v = Integer.parseInt(st.nextToken());
				arr[i][j] = v;
				
				if(v == -1) {
					if(!firstAC) {
						upperAirCleaner = i;
						firstAC = true;
					} else {
						lowerAirCleaner = i;
					}
				}
			}
		}
		
		simulate();
		
		int answer = 0;
		for(int i = 0; i < R; i++) {
			for(int j = 0; j < C; j++) {
				if(arr[i][j] > 0) {
					answer += arr[i][j];
				}
			}
		}
		System.out.println(answer);
	}
}
