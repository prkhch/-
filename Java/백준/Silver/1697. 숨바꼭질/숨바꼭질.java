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
		
		int[] dp = new int[K+1];
		
		
		
		if(N >= K) {
			System.out.println(N-K);
		} else {
			
			for(int i=0; i<N; i++) {
				dp[i] = N-i;
			}
			
			for(int i=N+1; i<=K; i++) {
				
				if(i%2 == 0) {
					dp[i] = Math.min(dp[i/2] + 1, dp[i-1] + 1);
				} else {
					dp[i] = Math.min(Math.min(dp[(i-1)/2] + 2, dp[(i+1)/2] + 2), dp[i-1] + 1);
				}
			}
			
			System.out.println(dp[K]);
		}
		
	}
	
}
