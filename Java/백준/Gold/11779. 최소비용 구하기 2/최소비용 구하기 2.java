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
		return Integer.compare(index, o.index);
	}
}

public class Main {
	
	static int INF = Integer.MAX_VALUE;
	static int N, M;
	static int startPoint, endPoint;
	static ArrayList<Node>[] graph;
	static int dist[];
	static boolean visit[];
	static LinkedList<Integer> dq;
	static int prev[];

	static void dijkstra() {
		
		dq = new LinkedList<>();
		PriorityQueue<Node> pq = new PriorityQueue<>();
//		visit = new boolean[N+1];
		
		dist = new int[N+1];
		Arrays.fill(dist, INF);

		dist[startPoint] = 0;
		pq.add(new Node(startPoint, 0));
		
		while(!pq.isEmpty()) {
			
			Node now = pq.poll();
			
			if(now.weight > dist[now.index]) continue;
//			if(now.index == endPoint) return;
			
//			if(visit[now.index]) continue;
//			visit[now.index] = true;
			
			for(Node next : graph[now.index]) {
				if(dist[next.index] > dist[now.index] + next.weight) {
					dist[next.index] =  dist[now.index] + next.weight;
					prev[next.index] = now.index;
					pq.add(new Node(next.index, dist[next.index]));
				}
			}
			
		}
		
	}
	
	public static void main(String[] args) throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		N = Integer.parseInt(br.readLine());
		M = Integer.parseInt(br.readLine());
		
		prev = new int[N+1];
		
		graph = new ArrayList[N+1];
		for(int i=1; i<=N; i++) graph[i] = new ArrayList<>();
		
		for(int i=0; i<M; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			int start = Integer.parseInt(st.nextToken());
			int end = Integer.parseInt(st.nextToken());
			int cost = Integer.parseInt(st.nextToken());
			graph[start].add(new Node(end, cost));
		}
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		startPoint = Integer.parseInt(st.nextToken());
		endPoint = Integer.parseInt(st.nextToken());
		
		dijkstra();
		
		System.out.println(dist[endPoint]);
		
		LinkedList<Integer> q = new LinkedList<>();
		int pathPoint = endPoint;
		while(true) {
			q.add(pathPoint);
			if(pathPoint == startPoint) break;
			pathPoint = prev[pathPoint];
		}
		
		System.out.println(q.size());
		while(!q.isEmpty()) System.out.print(q.pollLast() + " ");

		
	}
	
}