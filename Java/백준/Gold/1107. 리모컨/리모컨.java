import java.util.*;
import java.io.*;

public class Main {
	
	static int N;
	static int m;
	static boolean[] broken = new boolean[10];
	
	public static boolean isPush(int ch) {
		String s = Integer.toString(ch);
		for(int i=0; i<s.length(); i++) {
			if(broken[s.charAt(i) - '0']) {
				return false;
			}
		}
		return true;
	}
 	
	public static void main(String[] args) throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));	 	
	 	
	 	N = Integer.parseInt(br.readLine());
	 	m = Integer.parseInt(br.readLine());
	 	
	 	if(m != 0) {	 		
	 		StringTokenizer st = new StringTokenizer(br.readLine());
	 		for(int i=0; i<m; i++) {
	 			broken[Integer.parseInt(st.nextToken())] = true;
	 		}
	 	}
	 	
	 	int cnt;
	 	int min_cnt = Integer.MAX_VALUE;
	 	for(int i=0; i<=1000000; i++) {
	 		
	 		int pmcnt = Math.abs(100-N);
	 		if(isPush(i)) {
	 			cnt = Integer.toString(i).length() + Math.abs(i-N);
	 			cnt = Math.min(cnt, pmcnt);
	 			min_cnt = Math.min(cnt, min_cnt);
	 		}
	 		min_cnt = Math.min(min_cnt, pmcnt);
	 		
	 	}
	 	
	 	System.out.print(min_cnt);
	}
}