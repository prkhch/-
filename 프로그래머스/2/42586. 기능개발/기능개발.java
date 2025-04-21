import java.util.*;

class Solution {
    public int[] solution(int[] progresses, int[] speeds) {
        
        int[] arr = new int[progresses.length];
        for(int i=0; i<progresses.length; i++) {
            arr[i] = (int)Math.ceil((100.0-progresses[i]) / speeds[i]);
        }
        
        List<Integer> result = new ArrayList<>();
        int mx = arr[0]; int cnt = 1;
        for(int i=1; i<arr.length; i++) {
            if(arr[i] <= mx) {
                cnt++;
            } else {
                mx = arr[i];
                result.add(cnt);
                cnt = 1;
            }
        }
        result.add(cnt);
        
        int[] answer = new int[result.size()];
        for(int i=0; i<result.size(); i++) {
            answer[i] = result.get(i);
        }
        
        return answer;
    }
}