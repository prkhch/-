import java.util.*;
import java.io.*;

public class Main {
	
	public static void main(String[] args) throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        
        int arr[] = new int[N];
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        for(int i=0; i<N; i++) {
        	arr[i] = Integer.parseInt(st.nextToken());
        }
        
        int start = 0;
        int end = N-1;
        
        int sumCloseZero = Integer.MAX_VALUE;
        int answerStart = 0;
        int answerEnd = 0;
        
        while(start < end) {
        	int sum = arr[start] + arr[end];
        	
        	if(sumCloseZero > Math.abs(sum)) {
        		sumCloseZero = Math.abs(sum);
        		answerStart = start;
        		answerEnd = end;
        	}
        	
        	if(sum < 0) {
        		start++;
        	} else if(sum > 0) {
        		end--;
        	} else {
        		break;
        	}
        }
        
        System.out.println(arr[answerStart] + " " + arr[answerEnd]);
        
	}
}
