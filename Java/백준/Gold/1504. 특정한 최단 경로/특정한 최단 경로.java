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
		return Integer.compare(weight, o.weight);
	}
}

public class Main {
	
	static int INF = 200000001;
	
	static int N, E;
	static ArrayList<Node>[] graph;
	static int K1, K2; 
	
	static int dist[][];
	
	static void dijkstra(int startPoint, int distOrder) {
		
		PriorityQueue<Node> pq = new PriorityQueue<>();
		
		pq.add(new Node(startPoint, 0));
		dist[distOrder][startPoint] = 0;
		
		while(!pq.isEmpty()) {
			Node now = pq.poll();
			
			if(dist[distOrder][now.index] < now.weight) continue;
			
			for(Node next : graph[now.index]) {
				if(dist[distOrder][next.index] > dist[distOrder][now.index] + next.weight) {
					dist[distOrder][next.index] = dist[distOrder][now.index] + next.weight;
					pq.add(new Node(next.index, dist[distOrder][next.index]));
				}
			}
		}
		
	}
	
	public static void main(String[] args) throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		E = Integer.parseInt(st.nextToken());
		
		graph = new ArrayList[N+1];
		for(int i=1; i<=N; i++) graph[i] = new ArrayList<>();
		
		dist = new int[3][N+1];
		for(int i=0; i<3; i++) Arrays.fill(dist[i], INF);
		
		for(int i=0; i<E; i++) {
			st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			int c = Integer.parseInt(st.nextToken());
			
			graph[a].add(new Node(b, c));
			graph[b].add(new Node(a, c));
		}
		
		st = new StringTokenizer(br.readLine());
		K1 = Integer.parseInt(st.nextToken());
		K2 = Integer.parseInt(st.nextToken());
		
		dijkstra(1, 0);
		dijkstra(K1, 1);
		dijkstra(K2, 2);
		
		int route1 = dist[0][K1] + dist[1][K2] + dist[2][N];
        int route2 = dist[0][K2] + dist[2][K1] + dist[1][N];
			
		if(route1 >= INF && route2 >= INF) 
			System.out.println(-1);
		else {
			System.out.println(Math.min(route1, route2));
		}
		
	}
	
}
