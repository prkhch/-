import java.util.*;
import java.io.*;

public class Main {
	
	static int N, M;
	
	static ArrayList<int[]> house;
	static ArrayList<int[]> chicken;
	
	static int answer = Integer.MAX_VALUE;
	
	static void check(int[] path) {
		
		int sumDist = 0;
		
		for(int[] hs : house) {
			int minDist = Integer.MAX_VALUE;
			for(int j=0; j<M; j++) {
				int[] ch = chicken.get(path[j]);
				minDist = Math.min(minDist, Math.abs(hs[0] - ch[0]) + Math.abs(hs[1] - ch[1]));
			}
			
			sumDist += minDist;
		}
		
		answer = Math.min(answer, sumDist);
	}
	
	static void dfs(int lv, int start, int[] path) {
		
		if(lv == M) {
			check(path);
			return;
		}
		
		for(int i = start; i < chicken.size(); i++) {
			path[lv] = i;
			dfs(lv+1, i+1, path);
		}
		
	}
	
	public static void main(String[] args) throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		
		house = new ArrayList<>();
		chicken = new ArrayList<>();
		
		for(int i=0; i<N; i++) {
			st = new StringTokenizer(br.readLine());
			for(int j=0; j<N; j++) {
				int v = Integer.parseInt(st.nextToken());
				if(v==1) house.add(new int[] {i, j});
				else if(v==2) chicken.add(new int[] {i, j});
			}
		}
		
		int path[] = new int[M];
		
		dfs(0, 0, path);
		
		System.out.println(answer);
		
	}
	
}
