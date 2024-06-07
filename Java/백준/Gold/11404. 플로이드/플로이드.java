import java.util.*;
import java.io.*;


public class Main {
	
	
	public static void main(String[] args) throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int N = Integer.parseInt(br.readLine());
		int M = Integer.parseInt(br.readLine());
		
		int[][] dist = new int[N+1][N+1];
		
		
		int INF = 100000001;
		for (int i=1; i<=N; i++) {
            for (int j=1; j<=N; j++) {
            	if(i==j) dist[i][j] = 0;
            	else dist[i][j] = INF;
            }
        }
		
		for(int i=0; i<M; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			int c = Integer.parseInt(st.nextToken());
			 dist[a][b] = Math.min(dist[a][b], c);
		}
		
		for(int k=1; k<=N; k++) {
			for(int i=1; i<=N; i++) {
				for(int j=1; j<=N; j++) {
					dist[i][j] = Math.min(dist[i][j], dist[i][k] + dist[k][j]);
				}
			}
		}
		
		for(int i=1; i<=N; i++) {
			for(int j=1; j<=N; j++) {
				if(dist[i][j] == INF) System.out.print(0 + " ");
				else System.out.print(dist[i][j] + " ");
			}
			System.out.println();
		}
		
	}
}