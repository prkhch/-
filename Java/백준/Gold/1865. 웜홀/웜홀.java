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
	
	static int INF = Integer.MAX_VALUE;
	
	static int TC;
	static int N, M, W;
	static ArrayList<Node>[] arr;
	static int[] dist;
	
	static boolean bellmanFord(int start) {
		Arrays.fill(dist, INF);
		dist[start] = 0;
		boolean flag = false;
		
		for(int i=1; i<=N-1; i++) {
			flag = false;
			for(int j=1; j<=N; j++) {
				for(Node next : arr[j]) {
					if(dist[j] != INF && dist[next.index] > dist[j] + next.weight) {
						dist[next.index] = dist[j] + next.weight;
						flag = true;
					}
				}
			}
			if(!flag) break; // 최단거리가 갱신되지 않으면, 음수 사이클이 없음
		}
		
		if(flag) {
			for(int i=1; i<=N; i++) {
				for(Node next : arr[i]) {
					if(dist[i] != INF && dist[next.index] > dist[i] + next.weight) { // N번째 반복에서 갱신된다면 음수 사이클 존재
						return true;
					}
				}
			}
		}
		
		return false;
	}
	
	public static void main(String[] args) throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		TC = Integer.parseInt(br.readLine());
		
		for(int i=0; i<TC; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			
			N = Integer.parseInt(st.nextToken()); // 정점의 수
			M = Integer.parseInt(st.nextToken()); // 도로의 수
			W = Integer.parseInt(st.nextToken()); // 웜홀의 수
			
			arr = new ArrayList[N+1];
			for(int j=1; j<=N; j++) {
				arr[j] = new ArrayList<>();
			}
			
			dist = new int[N+1];
			
			for(int j=0; j<M+W; j++) {
				st = new StringTokenizer(br.readLine());
				int S = Integer.parseInt(st.nextToken()); // 시작 지점
				int E = Integer.parseInt(st.nextToken()); // 도착 지점
				int T = Integer.parseInt(st.nextToken()); // 시간
				
				if(j < M) {
					arr[S].add(new Node(E, T));
					arr[E].add(new Node(S, T));
				} else {
					arr[S].add(new Node(E, -T));
				}
			}
			
			
			boolean isBellmanFord = false;
			for(int j=1; j<=N; j++) {
				if(bellmanFord(j)) {
					System.out.println("YES");
					isBellmanFord = true;
					break;
				}
			}
			if(!isBellmanFord) {
				System.out.println("NO");
			}
			
		}
	
	}
	
}
