import java.util.*;
import java.io.*;


public class Main {

	public static void main(String[] args) throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int N = Integer.parseInt(st.nextToken()); 
		int M = Integer.parseInt(st.nextToken());

		HashMap<String, String> memo = new HashMap<String, String>(100001);
		String url = "";
		String pwd = "";
		for(int i=0; i<N; i++) {
			st = new StringTokenizer(br.readLine());
			url = st.nextToken();
			pwd = st.nextToken();
			memo.put(url, pwd);
		}
		
		for(int i=0; i<M; i++) {
			url = br.readLine();
			System.out.println(memo.get(url));
		}
		
	}
}