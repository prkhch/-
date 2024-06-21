import java.util.*;
import java.io.*;

class Node implements Comparable<Node> {
	
	int index;
	int weight;
	
	Node(int index, int weight) {
		this.index = index;
		this.weight = weight;
 	}
	
	@Override
	public int compareTo(Node o) {
		return Integer.compare(this.weight, o.weight);
	}
	
}

public class Main {
	
	public static void main(String[] args) throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		int N = Integer.parseInt(st.nextToken());
		int K = Integer.parseInt(st.nextToken());
		
		int[][] items = new int[N+1][2];
		for(int i=1; i<=N; i++) {
			st = new StringTokenizer(br.readLine());
			items[i][0] = Integer.parseInt(st.nextToken()); // weight
			items[i][1] = Integer.parseInt(st.nextToken()); // value
		}
		
		int[][] dp = new int[N+1][K+1];
		
		for(int i=1; i<=N; i++) {
			for(int j=1; j<=K; j++) {
				if(j >= items[i][0]) {
					dp[i][j] = Math.max(dp[i-1][j], dp[i-1][j-items[i][0]] + items[i][1]);
				} else {
					dp[i][j] = dp[i-1][j];
				}
			}
		}
		
		System.out.println(dp[N][K]);
		
	}
	
}
