import java.util.*;
import java.io.*;


public class Main {
	static int N,r,c;
	static int cnt = 0;
	
 	static void run(int size, int r, int c) {
 		if(size==1) {
 			return;
 		}
 		
 		if(r < size/2 && c < size/2) {
 			run(size/2, r, c);
 		}
 		else if(r < size/2 && c >= size/2) {
 			cnt += (size * size) / 4;
 			run(size/2, r, c-(size/2));
 		}
 		else if(r >= size/2 && c < size/2) {
 			cnt += ((size * size) / 4) * 2;
 			run(size/2, r-(size/2), c);
 		}
 		else if(r >= size/2 && c >= size/2) {
 			cnt += ((size * size) / 4) * 3;
 			run(size/2, r-(size/2), c-(size/2));
 		}
 	}
 	
	public static void main(String[] args) throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
			 	
	 	StringTokenizer st = new StringTokenizer(br.readLine());
	 	N = Integer.parseInt(st.nextToken());
	 	r = Integer.parseInt(st.nextToken());
	 	c = Integer.parseInt(st.nextToken());
	 	
	 	int size = (int)Math.pow(2, N);
	 	
	 	run(size, r, c);
	 	
	 	System.out.print(cnt);
	 	
	}
}