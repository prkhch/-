import java.util.*;
import java.io.*;

public class Main {
	
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	
	static void top(int n, int st, int md, int ed) throws IOException {
		
		if(n==1) {
			bw.write(st + " " + ed);
			bw.newLine();
		}
		
		else {
			top(n-1, st, ed, md);
			
			bw.write(st+ " " + ed);
			bw.newLine();
			
			top(n-1, md, st, ed);
		}
		
	}
	
	public static void main(String[] args) throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int n = Integer.parseInt(br.readLine());
		bw.write(String.valueOf((int) Math.pow(2, n) -1));
		bw.newLine();
		top(n, 1, 2, 3);
		bw.flush();
	}
}
