import java.util.*;

class Solution {
    public int solution(String s) {
        int answer = 0;

        Map<String, String> map = new HashMap<>();
        map.put("zero", "0");
        map.put("one", "1");
        map.put("two", "2");
        map.put("three", "3");
        map.put("four", "4");
        map.put("five", "5");
        map.put("six", "6");
        map.put("seven", "7");
        map.put("eight", "8");
        map.put("nine", "9");
        
//         String tmp = "";
//         String result = "";
        
//         for(int i=0; i<s.length(); i++) {
//             if('0' <= s.charAt(i) && s.charAt(i) <= '9') {
//                 result += s.charAt(i);
//                 continue;
//             }
//             else {
//                 tmp += s.charAt(i);
//                 if(map.getOrDefault(tmp, "").equals("")) {
//                     continue;
//                 }
//                 else {
//                     result += map.get(tmp);
//                     tmp = "";
//                 }
//             }
//         }
        
        for(String key : map.keySet()) {
            s = s.replaceAll(key, map.get(key));
        }
        

        return Integer.parseInt(s);
    }
}