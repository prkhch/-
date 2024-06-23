import java.util.*;
import java.io.*;

class Node implements Comparable<Node> {
	int y;
	int x;
	int dist;
	
	Node(int y, int x, int dist) {
		this.y = y;
		this.x = x;
		this.dist = dist;
	}
	
	@Override
	public int compareTo(Node o) {
		if(this.dist == o.dist) {
			if(this.y == o.y) {
				return Integer.compare(this.x, o.x);
			}
			return Integer.compare(this.y, o.y);
		}
		return Integer.compare(this.dist, o.dist);
	}
}

public class Main {
	
	static int N;
	static int[][] arr;
	static boolean[][] visit;
	
	static int[] my = {-1, 0, 0, 1};
	static int[] mx = {0, -1, 1, 0};
	
	static int answer;

	static void bfs(int stY, int stX) {
		PriorityQueue<Node> pq = new PriorityQueue<>();
		pq.add(new Node(stY, stX, 0));
		visit = new boolean[N][N];
		visit[stY][stX] = true;
		
		int babySize = 2;
		int eatCnt = 0;
		
		while(!pq.isEmpty()) {
			Node now = pq.poll();
			
			if(0 != arr[now.y][now.x] && arr[now.y][now.x] < babySize) {
				arr[now.y][now.x] = 0;
				eatCnt++; 
				if(eatCnt == babySize) {
					babySize++;
					eatCnt = 0;
				}
				pq.clear();
				visit = new boolean[N][N];
				visit[now.y][now.x] = true;
				answer += now.dist;
				now.dist = 0;
			}
			
			for(int i=0; i<4; i++) {
				int ny = now.y + my[i];
				int nx = now.x + mx[i];
				if(ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
				if(visit[ny][nx]) continue;
				if(babySize < arr[ny][nx]) continue;
				visit[ny][nx] = true;
				pq.add(new Node(ny, nx, now.dist+1));
			}
			
		}
	}
	
	public static void main(String[] args) throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		N = Integer.parseInt(st.nextToken());
		
		arr = new int[N][N];
		
		for(int i=0; i<N; i++) {
			st = new StringTokenizer(br.readLine());
			for(int j=0; j<N; j++) {
				arr[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		
		for(int i=0; i<N; i++) {
			for(int j=0; j<N; j++) {
				if(arr[i][j] == 9)  {
					arr[i][j] = 0;
					bfs(i, j);
				}
			}
		}
		
		System.out.println(answer);
		
	}
	
}
