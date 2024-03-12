import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;

public class Main {

	public static void main(String[] args) throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		
		ArrayDeque<Integer> dq = new ArrayDeque<>();
		
		for(int i=1; i<=n; i++) {
			dq.add(i);
		}
		
		while(true) {
			if(dq.size()==1) break;
			dq.pollFirst();
			dq.addLast(dq.pollFirst());
		}
		
		System.out.print(dq.peek());
		
	}
}
