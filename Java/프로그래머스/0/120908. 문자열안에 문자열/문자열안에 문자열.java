class Solution {
    public int solution(String str1, String str2) {
        int answer = 2;
        boolean in = false;
        
        for(int i=0; i<str1.length()-str2.length() + 1; i++) {
            if(str1.charAt(i)==str2.charAt(0)) {
                for(int j=0; j<str2.length(); j++) {
                    if(str1.charAt(i+j) != str2.charAt(j)) {
                        break;
                    }
                    if(j==str2.length()-1) {
                        in = true;
                    }
                }
            }
            
            if(in == true) {
                break;
            }
        }
        
        if(in == true) {
            answer = 1;
        }
        
        return answer;
    }
}