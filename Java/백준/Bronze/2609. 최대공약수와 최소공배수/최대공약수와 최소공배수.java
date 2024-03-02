import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int A = 0, B = 0;
		
		A = Integer.parseInt(st.nextToken());
		B = Integer.parseInt(st.nextToken());
		
		int AB = A * B;
		
		if(B > A) {
			int tmp = 0;
			tmp = A;
			A = B;
			B = tmp;
		}
		
		int r = 0;
		while(B != 0) {
			r = A % B;
			A = B;
			B = r;
		}
		
		System.out.println(A);
		System.out.println(AB / A);
		
	}

}
