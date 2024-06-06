import java.util.*;
import java.io.*;


public class Main {
	
	static int N, M;
	static boolean visit[] = new boolean[101];
	static HashMap<Integer, Integer> map = new HashMap<>();
	static int answer = Integer.MAX_VALUE;
	static Queue<int[]> q = new LinkedList<>();
	
	static void bfs() {
		q.add(new int[] {1, 0}); // position, cnt
		
		while(!q.isEmpty()) {
			int[] now = q.poll();
			visit[now[0]] = true;
			
			if(now[0] == 100) {
				System.out.println(now[1]);
				return;
			}
			
			for(int i=1; i<=6; i++) {
				int nx = now[0] + i;
				
				if(nx > 100) continue;
				if(visit[nx]) continue;
				
				if(map.get(nx) != null) {
					q.add(new int[] {map.get(nx), now[1] + 1});
				} else {
					q.add(new int[] {nx, now[1] + 1});
				}
			}
			
		}
		
	}
	
	public static void main(String[] args) throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		
		for(int i=0; i<N; i++) {
			st = new StringTokenizer(br.readLine());
			int start = Integer.parseInt(st.nextToken());
			int end = Integer.parseInt(st.nextToken());
			map.put(start, end);
		}
		
		for(int i=0; i<M; i++) {
			st = new StringTokenizer(br.readLine());
			int start = Integer.parseInt(st.nextToken());
			int end = Integer.parseInt(st.nextToken());
			map.put(start, end);
		}
		
		bfs();
		
	}
}