import java.util.*;
import java.io.*;

public class Main {
	
	static int N, M;
	static int[] arr;
	static int[] answer;
	static boolean[] visit;
	
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out)); 
	
	static void run(int lv) throws IOException {
		
		if(lv == M) {
			for(int i=0; i<M; i++) {
				bw.write(answer[i] + " ");
			}
			bw.newLine();
			return;
		}
		
		for(int i=0; i<N; i++) {
			answer[lv] = arr[i];
			if(visit[i] == true) continue;
			visit[i] = true;
			run(lv+1);
			visit[i] = false;
		}
	}
	
	public static void main(String[] args) throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
				
		arr = new int[N];
		answer = new int[N];
		visit = new boolean[N];
		st = new StringTokenizer(br.readLine());
		for(int i=0; i<N; i++) {
			arr[i] = Integer.parseInt(st.nextToken());
		}
		
		Arrays.sort(arr);
		
		run(0);
		bw.flush();
	}
	
}