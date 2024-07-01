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
        
        Arrays.sort(arr);
        
        int startPointer = 0;
        int endPointer = N-1;
        
        int nearestSum = Integer.MAX_VALUE; 
        int answer1 = 0;
        int answer2 = 0;
        
        while(startPointer < endPointer) {
        	int sum = arr[startPointer] + arr[endPointer];
        	
            if(Math.abs(nearestSum) > Math.abs(sum)) {
                nearestSum = sum;
                answer1 = arr[startPointer];
                answer2 = arr[endPointer];
            }
        	
        	if(sum > 0) {
        		endPointer--;
        	} else if(sum < 0) {
        		startPointer++;
        	} else if(sum==0) {
        		break;
        	}
        	
        }
        
        System.out.println(answer1 + " " + answer2);
        
	}
}
