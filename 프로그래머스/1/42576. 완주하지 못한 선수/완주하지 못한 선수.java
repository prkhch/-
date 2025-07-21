import java.util.HashMap;

class Solution {
    public String solution(String[] participant, String[] completion) {
        
        String answer = "";
        HashMap<String, Integer> m = new HashMap<>();
        
        for(String s : participant) {
            m.put(s, m.getOrDefault(s, 0)+1);
        }
        
        for(String s : completion) {
             m.put(s, m.get(s) - 1);    
        }

        for (String key : m.keySet()) {
            if (m.get(key) > 0) return key;
        }
        
        return "";
        
    }
}