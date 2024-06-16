import java.util.*;
import java.io.*;

public class Main {
	
	public static void main(String[] args) throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int N = Integer.parseInt(br.readLine());
		
		int[][] arr = new int[N][3];
		int[][] maxDP = new int[N][3];
		int[][] minDP = new int[N][3];
		
		for(int i=0; i<N; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			for(int j=0; j<3; j++) {
				arr[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		
		for(int i=0; i<3; i++) {
			maxDP[0][i] = arr[0][i]; 
			minDP[0][i] = arr[0][i]; 
		}
		
		for(int i=1; i<N; i++) {
			maxDP[i][0] = Math.max(maxDP[i-1][0] + arr[i][0], maxDP[i-1][1] + arr[i][0]); 
			maxDP[i][1] = Math.max(Math.max(maxDP[i-1][0] + arr[i][1], maxDP[i-1][1] + arr[i][1]), maxDP[i-1][2] + arr[i][1]); 
			maxDP[i][2] = Math.max(maxDP[i-1][1] + arr[i][2], maxDP[i-1][2] + arr[i][2]); 
			
			minDP[i][0] = Math.min(minDP[i-1][0] + arr[i][0], minDP[i-1][1] + arr[i][0]); 
			minDP[i][1] = Math.min(Math.min(minDP[i-1][0] + arr[i][1], minDP[i-1][1] + arr[i][1]), minDP[i-1][2] + arr[i][1]); 
			minDP[i][2] = Math.min(minDP[i-1][1] + arr[i][2], minDP[i-1][2] + arr[i][2]); 
		}
		
		System.out.println(Math.max(Math.max(maxDP[N-1][0], maxDP[N-1][1]), maxDP[N-1][2]) + " " + Math.min(Math.min(minDP[N-1][0], minDP[N-1][1]), minDP[N-1][2]));
		
	}
	
}
