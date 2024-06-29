import java.util.*;
import java.io.*;

public class Main {
	
	public static void main(String[] args) throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());
        
        for(int i=0; i<T; i++) {
        	String p = br.readLine();
        	int n = Integer.parseInt(br.readLine());
        	
        	String rawStringArr = br.readLine();
        	
        	String[] stringArr;
        	if(n==0) {
        		rawStringArr = "";
        		stringArr = new String[0];
        	} else {
        		rawStringArr = rawStringArr.substring(1, rawStringArr.length()-1);
        		stringArr = rawStringArr.split(",");
        	}
        	
        	
        	Deque<String> dq = new ArrayDeque<>();
        	for(int j=0; j<stringArr.length; j++) {
        		dq.add(stringArr[j]);
        	}

        	boolean isReverse = false;
        	boolean isError = false;
        	for(int j=0; j<p.length(); j++) {
        		if(p.charAt(j) == 'R') {
        			isReverse = !isReverse;
        		} else if(p.charAt(j) == 'D') {
        			if(dq.isEmpty()) {
        				isError  = true;
        				break;
        			}
        			else if(!isReverse) {
        				dq.pollFirst();
        			} else if (isReverse) {
        				dq.pollLast();
        			}
        		}
        	}
        	
        	if(isError) {
        		System.out.println("error");
        	} else {
        		System.out.print("[");
        		while(!dq.isEmpty()) {
        			if(!isReverse) {
        				System.out.print(dq.pollFirst());
        			} else {
        				System.out.print(dq.pollLast());
        			}
        			if(!dq.isEmpty()) {
        				System.out.print(",");
        			}
        		}
        		System.out.println("]");
        	}
        	
        } // T
        
	}
}
