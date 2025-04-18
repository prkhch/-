#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    string str;
    while(true) {
        cin >> str;
        if(str == "end") break;

        bool isApt = false;

        for(char c : str) {
            if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                isApt = true;
                break;
            }
        }


        if(str.size() >= 2) {
            for(int i=1; i<str.size(); i++) {
                if(str[i] != 'e' && str[i] != 'o' && str[i-1] == str[i]) {
                    isApt = false;
                    break;
                }
            }
        }
        

        if(str.size() >= 3) {
        
            for(int i=0; i<str.size()-2; i++) {
                if(str[i] != 'a' && str[i] != 'e' && str[i] != 'i' && str[i] != 'o' && str[i] != 'u') {
                    if(str[i+1] != 'a' && str[i+1] != 'e' && str[i+1] != 'i' && str[i+1] != 'o' && str[i+1] != 'u') {
                        if(str[i+2] != 'a' && str[i+2] != 'e' && str[i+2] != 'i' && str[i+2] != 'o' && str[i+2] != 'u') {
                            isApt = false;
                            break;
                        }
                    } 
                }
                
                if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u') {
                    if(str[i+1] == 'a' || str[i+1] == 'e' || str[i+1] == 'i' || str[i+1] == 'o' || str[i+1] == 'u') {
                        if(str[i+2] == 'a' || str[i+2] == 'e' || str[i+2] == 'i' || str[i+2] == 'o' || str[i+2] == 'u') {
                            isApt = false;
                            break;
                        }
                    } 
                }
            }
        }

        if(isApt) cout << "<" << str << "> is acceptable." << "\n";
        else cout << "<" << str << "> is not acceptable." << "\n";

    }

}
