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
        
        int M = Integer.parseInt(br.readLine());
        st = new StringTokenizer(br.readLine());
        
        for(int i=0; i<M; i++) {
        	int number = Integer.parseInt(st.nextToken());
        	int start = 0;
        	int end = N-1;
        	
        	boolean isExist = false;
        	
        	while(start <= end) {
        		int mid = (start + end) / 2;
        		
        		if(arr[mid] < number) {
        			start = mid + 1;
        		} else if(arr[mid] > number) {
        			end = mid - 1;
        		} else {
        			isExist = true;
        			break;
        		}
        	}
        	
        	if(isExist) {
        		System.out.print(1 + " ");
        	} else {
        		System.out.print(0 + " ");
        	}
        }
        
	}
}
