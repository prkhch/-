import java.util.*;
import java.io.*;


public class Main {
	
	static int N, M;
	static ArrayList<Node>[] graph;
	static int[] dist;
	static int INF = Integer.MAX_VALUE;
	
	static class Node implements Comparable<Node> {
		
		int index; 
		int weight;
		
		public Node(int index, int weight) {
			this.index = index;
			this.weight = weight;
		}
		
		@Override 
		public int compareTo(Node o) {
			return Integer.compare(this.weight, o.weight);
		}
		
	}
	
	static void dijkstra(int sp, int ep) {
		
		PriorityQueue<Node> pq = new PriorityQueue<>();
		boolean[] visit = new boolean[N+1]; 
		
		pq.add(new Node(sp, 0));
		dist[sp] = 0;
		
		while(!pq.isEmpty()) {
			Node node = pq.poll();
			int index = node.index; // index
			int weight = node.weight; // weight
			
			visit[index] = true;
			
			if(index == ep) {
				return;
			}
			
			for(Node next : graph[index]) {
				if(visit[next.index] == true) continue;
				
				if(dist[next.index] > weight + next.weight) {
					dist[next.index] = weight + next.weight;
					pq.add(new Node(next.index, dist[next.index]));
				}
			}
			
		}
		
	}
	
	public static void main(String[] args) throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		N = Integer.parseInt(br.readLine());
		M = Integer.parseInt(br.readLine());
		
		dist = new int[N+1];
		Arrays.fill(dist, INF);
		
		graph = new ArrayList[N+1];
		for(int i=0; i<=N; i++) graph[i] = new ArrayList<>();
		
		for(int i=0; i<M; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			int start = Integer.parseInt(st.nextToken());
			int end = Integer.parseInt(st.nextToken());
			int cost = Integer.parseInt(st.nextToken());
			
			graph[start].add(new Node(end, cost));
		}
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		int sp = Integer.parseInt(st.nextToken()); // start point
		int ep = Integer.parseInt(st.nextToken()); // end point
		
		dijkstra(sp, ep);
		
		System.out.println(dist[ep]);

	}
}