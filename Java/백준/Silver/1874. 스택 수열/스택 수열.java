import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
				
		int num;
		int start = 1;
		ArrayDeque<Integer> dq = new ArrayDeque<>();
		char[] result = new char[200002];
		int rs_idx = 0;
		
		for(int i=0; i<n; i++) {
			num = Integer.parseInt(br.readLine());
			
			if(num >= start) {
				for(int j=start; j<=num; j++) {
					dq.add(j);
					result[rs_idx] = '+';
					rs_idx++;
				}
				start = num+1;
			}
			
			else if(!dq.isEmpty() && num != dq.peekLast()) {
				System.out.print("NO");
				return;
			}
			
			dq.pollLast();
			result[rs_idx] = '-';
			rs_idx++;
		}
		
		for(int i=0; i<rs_idx; i++) {
			System.out.println(result[i]);
		}
		
	}
}
