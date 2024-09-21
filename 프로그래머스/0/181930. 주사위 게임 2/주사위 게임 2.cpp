#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int a, int b, int c) {
    if(a != b && b != c && a != c) {
        return a+b+c;
    } else if (a == b && b == c) {
        return (a+b+c) * (a*a + b*b + c*c) * (pow(a,3) + pow(b,3) + pow(c,3));
    } else {
        return (a+b+c) * (a*a + b*b + c*c);
    }
}