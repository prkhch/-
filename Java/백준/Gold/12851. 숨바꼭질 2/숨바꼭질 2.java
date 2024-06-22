import java.util.*;
import java.io.*;

public class Main {
	
	static int N, K;
	static boolean[] visit; 
	static int answer = Integer.MAX_VALUE;
	static int cnt;
	
	static void bfs() {
		
		Queue<int[]> q = new LinkedList<>();
		
		q.add(new int[] {N, 0});
		
		while(!q.isEmpty()) {
			
			int[] now = q.poll();
			visit[now[0]] = true;
			
			if(now[0] == K) {
				if(answer == now[1]) {
					cnt += 1;
				} else if(answer > now[1]) {
					answer = now[1];
					cnt = 1;
				}
			}
			
			if(now[0]*2 <= 100000 && visit[now[0]*2] == false) {
				q.add(new int[] {now[0]*2, now[1] + 1});
			}
			
			if(now[0]+1 <= 100000 && visit[now[0]+1] == false) {
				q.add(new int[] {now[0]+1, now[1] + 1});
			}
			
			if(now[0]-1 > 0 && visit[now[0]-1] == false) {
				q.add(new int[] {now[0]-1, now[1] + 1});
			}
			
		}
		
	}
	
	public static void main(String[] args) throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		K = Integer.parseInt(st.nextToken());
		
		visit = new boolean[100001];
		if(N >= K) {
			System.out.println(N-K);
			System.out.println(1);
		} else {
			bfs();
			System.out.println(answer);
			System.out.println(cnt);
		}
		
	}
	
}
