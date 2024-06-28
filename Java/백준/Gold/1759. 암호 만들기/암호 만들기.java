import java.util.*;
import java.io.*;

public class Main {
	
	static int L, C;
	static char pathNote[];
	static char charGroup[];
	
	public static boolean isCorrect() {
		int vowelCnt = 0;
		int consoCnt = 0;
		for(int i=0; i<L; i++) {
			if(pathNote[i] == 'a' || pathNote[i] == 'e' || pathNote[i] == 'i' || pathNote[i] == 'o' || pathNote[i] == 'u') {
				vowelCnt++;
			} else {
				consoCnt++;
			}
		}
		
		return vowelCnt >= 1 && consoCnt >= 2;
	}
	
	public static void search(int lv, int st) {
		
		if(lv == L) {
			if(isCorrect()) {
				for(int i=0; i<L; i++) {
					System.out.print(pathNote[i]);
				}
				System.out.println();
			}
			return;
		}
		
		for(int i=st; i<C; i++) {
			pathNote[lv] = charGroup[i];
			search(lv+1, i+1);
		}
		
	}
	
	public static void main(String[] args) throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		L = Integer.parseInt(st.nextToken());
		C = Integer.parseInt(st.nextToken());
		
		charGroup = new char[C];
		pathNote = new char[L];
		
		st = new StringTokenizer(br.readLine());
		for(int i=0; i<C; i++) {
			charGroup[i] = st.nextToken().charAt(0);
		}
		
		Arrays.sort(charGroup);
		
		search(0, 0);
		
	}
}
