import java.util.*;
import java.io.*;

class Node implements Comparable<Node> {
	
	int index;
	int weight;
	
	public Node(int index, int weight) {
		this.index = index;
		this.weight = weight;
	}
	
	@Override
	public int compareTo(Node o) {
		return Integer.compare(weight, o.weight);
	}
	
}

public class Main {
	
	static int V, E, K; // 정점, 간선, 시작점
	static ArrayList<Node>[] graph;
	static int dist[];
	static int INF = Integer.MAX_VALUE;
	
	static void dijkstra() {
		
		PriorityQueue<Node> pq = new PriorityQueue<>();
		pq.add(new Node(K, 0));
		dist[K] = 0;
		
		while(!pq.isEmpty()) {
			
			Node now = pq.poll();
			
			if(now.weight > dist[now.index]) continue;
			
			for(Node next : graph[now.index]) {
				if(dist[next.index] > dist[now.index] + next.weight) {
					dist[next.index] = dist[now.index] + next.weight;
					pq.add(new Node(next.index, dist[next.index]));
				}
			}
			
		}
		
	}

	
	public static void main(String[] args) throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		V = Integer.parseInt(st.nextToken());
		E = Integer.parseInt(st.nextToken());
		K = Integer.parseInt(br.readLine());
		
		graph = new ArrayList[V+1];
		for(int i=1; i<=V; i++) graph[i] = new ArrayList<>();
		
		dist = new int[V+1];
		Arrays.fill(dist, INF);
		
		for(int i=0; i<E; i++) {
			st = new StringTokenizer(br.readLine());
			int u = Integer.parseInt(st.nextToken());
			int v = Integer.parseInt(st.nextToken());
			int w = Integer.parseInt(st.nextToken());
			
			graph[u].add(new Node(v, w));
		}
		
		dijkstra();
		
		for(int i=1; i<=V; i++) {
			if(dist[i] == INF) System.out.println("INF");
			else System.out.println(dist[i]);
		}
		
	}
	
}