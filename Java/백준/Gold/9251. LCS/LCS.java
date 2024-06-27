import java.util.*;
import java.io.*;

public class Main {
	
	public static void main(String[] args) throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		
		String str1 = br.readLine();
		String str2 = br.readLine();
		int str1Length = str1.length();
		int str2Length = str2.length();
		
		int arr[][] = new int[str1Length+1][str2Length+1];
		
		for(int i=1; i<=str1Length; i++) {
			for(int j=1; j<=str2Length; j++) {
				if(str1.charAt(i-1) == str2.charAt(j-1)) {
					arr[i][j] = arr[i-1][j-1]+1;
				} else {
					arr[i][j] = Math.max(arr[i][j-1], arr[i-1][j]);
				}
			}
		}
		
		int maxValue = 0;
		for(int i=0; i<=str1Length; i++) {
			for(int j=0; j<=str2Length; j++) {
				maxValue = Math.max(arr[i][j], maxValue);
			}
		}
		
		System.out.println(maxValue);
		
	}
}
