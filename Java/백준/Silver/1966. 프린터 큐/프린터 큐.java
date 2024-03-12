import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int T;
		T = Integer.parseInt(st.nextToken());
		
		for(int i=0; i<T; i++) {
			int out_cnt = 0; 
			
			st = new StringTokenizer(br.readLine());
			int N = Integer.parseInt(st.nextToken());
			int M = Integer.parseInt(st.nextToken());
			
			Queue<int[]> q = new LinkedList<>();
			st = new StringTokenizer(br.readLine());
			for(int j=0; j<N; j++) {
				q.add(new int[] {Integer.parseInt(st.nextToken()), j});
			}
			
			int cnt = 0;
			boolean chk;
			
			while(!q.isEmpty()) {
				int[] cur = q.poll();
				chk = true;
				
				for(int[] item : q) {
					if(item[0] > cur[0]) {
						q.add(cur);
						chk = false;
						break;
					}
				}
				
				if(chk==true) {
					cnt++;
					if(cur[1] == M) {
						System.out.println(cnt);
						break;
					}
					
				}
				
			}
		}
	}
}
