import java.util.*;
import java.io.*;


public class Main {

	static int[][] arr = new int[128][128];
	static int white = 0;
	static int blue = 0;
	
	static void cut(int stY, int stX, int size) {
		int now = arr[stY][stX];
		
		if(size == 1) {
			if(now == 0) white++;
			else blue++;
			return;
		}
		
		for(int i = stY; i < stY + size; i++) {
			for(int j = stX; j < stX + size; j++) {
				if(now != arr[i][j]) {
					cut(stY, stX, size/2);
					cut(stY, stX + size/2, size/2);
					cut(stY + size/2, stX, size/2);
					cut(stY + size/2, stX + size/2, size/2);
					return;
				}
			}
		}
		
		if(now == 0) white++; 
		else blue++;
		
	}
		
	public static void main(String[] args) throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());
		
		for(int i = 0; i < N; i++) {
			String line = br.readLine();
			StringTokenizer st = new StringTokenizer(line);
			for(int j = 0; j < N; j++) {
				arr[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		
		cut(0, 0, N);
		
		System.out.println(white);
		System.out.println(blue);

	}
}