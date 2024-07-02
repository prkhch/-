import java.util.*;
import java.io.*;

public class Main {
	
	public static void main(String[] args) throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        
        long arr[] = new long[N];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i=0; i<N; i++) {
        	arr[i] = Integer.parseInt(st.nextToken());
        }
        
        Arrays.sort(arr);
        
        int answer = 0;
        for(int i=0; i<N; i++) {
        	
        	int start = 0;
        	int end = N-1;
        	long nowNumber = arr[i];
        	
        	while(start < end) {
        		long sum = arr[start] + arr[end];
        		
        		if(i == start) {
        			start++; continue;
        		}
        		if(i == end) {
        			end--; continue;
        		}
        		
        		if(sum < nowNumber) {
        			start++;
        		} else if(sum > nowNumber) {
        			end--;
        		} else {
        			answer++; break;
        		}
        	}
        	
        }
        
        System.out.println(answer);
        
	}
}
