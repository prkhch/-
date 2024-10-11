#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>

using namespace std;

static unordered_map<string, char> morse = {
    {".-", 'a'}, {"-...", 'b'}, {"-.-.", 'c'}, {"-..", 'd'},
    {".", 'e'}, {"..-.", 'f'}, {"--.", 'g'}, {"....", 'h'},
    {"..", 'i'}, {".---", 'j'}, {"-.-", 'k'}, {".-..", 'l'},
    {"--", 'm'}, {"-.", 'n'}, {"---", 'o'}, {".--.", 'p'},
    {"--.-", 'q'}, {".-.", 'r'}, {"...", 's'}, {"-", 't'},
    {"..-", 'u'}, {"...-", 'v'}, {".--", 'w'}, {"-..-", 'x'},
    {"-.--", 'y'}, {"--..", 'z'}
};

string solution(string letter) {
    string answer = "";
    
    stringstream ss(letter);
    string words;

    while(getline(ss, words, ' ')) {
        answer+=morse[words];
    }

    
    return answer;
}