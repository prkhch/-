import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int sugar = Integer.parseInt(st.nextToken());
		
		int five = 0, three = 0, remain = 0;
		five = sugar/5;
		remain = sugar - (five * 5);
		
		while(true) {
			if(remain % 3 == 0) {
				three = remain/3;
				System.out.print(five + three);
				break;
			} else {
				five --;
				remain += 5;
			}
			
			if(five < 0) {
				System.out.print(-1);
				break;
			}
		}

	}

}
