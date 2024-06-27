import java.util.*;
import java.io.*;

public class Main {
	
	static char arr[][];
	
	static void search(int y, int x, int size) {
		
		if(size == 1) {
			arr[y][x] = '*';
			return;
		}
		
		int nextSize = size/3;
		int cnt = 0;
		for(int i=y; i<y+size; i+=nextSize) {
			for(int j=x; j<x+size; j+=nextSize) {
				cnt++;
				if(cnt == 5) continue;
				search(i, j, nextSize);
			}
		}
		
	}
	
	public static void main(String[] args) throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());
		arr = new char[N][N];
		
		for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                arr[i][j] = ' ';
            }
        }
		
		search(0, 0, N);
		 StringBuilder sb = new StringBuilder();
		for(int i=0; i<N; i++) {
			for(int j=0; j<N; j++) {
				 sb.append(arr[i][j]);
            }
            sb.append('\n');
        }
        System.out.print(sb);
		
	}
}
