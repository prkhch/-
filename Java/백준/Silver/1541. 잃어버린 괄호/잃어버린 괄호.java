import java.util.*;
import java.io.*;

public class Main {
		
	public static void main(String[] args) throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String fomula = br.readLine();
		
		boolean minusFlag = false;
		String nowNumber = ""; 
		int result = 0;
		
		for(int i=0; i<fomula.length(); i++) {
			char nowChar = fomula.charAt(i);
			
			if(i == fomula.length()-1) {
				nowNumber += nowChar;
				if(minusFlag == true) {
					result -= Integer.parseInt(nowNumber);
				} else {
					result += Integer.parseInt(nowNumber);
				}
				break;
			}
			
			if(nowChar != '+' && nowChar != '-') {
				nowNumber += nowChar;
			} else if(minusFlag == true) {
				result -= Integer.parseInt(nowNumber);
				nowNumber = "";
			} else {
				result += Integer.parseInt(nowNumber);
				nowNumber = "";
				if(nowChar == '-') minusFlag = true;
			}
		}
		
		System.out.println(result);
		
	}
}