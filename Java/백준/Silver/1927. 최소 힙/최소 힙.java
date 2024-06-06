import java.util.*;
import java.io.*;


public class Main {
	
	public static void main(String[] args) throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		PriorityQueue<Integer> minQ = new PriorityQueue<>();
		
		int N = Integer.parseInt(br.readLine());
		for(int i=0; i<N; i++) {
			int x = Integer.parseInt(br.readLine());
			
			if(x == 0) {
				if(minQ.isEmpty()) System.out.println("0");
				else {
					System.out.println(minQ.peek());
					minQ.poll();
				}
			} else {
				minQ.add(x);
			}
			
		}
		
	}
}