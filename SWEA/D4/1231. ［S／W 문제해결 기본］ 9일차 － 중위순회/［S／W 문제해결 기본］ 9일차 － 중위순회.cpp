#include <iostream>
#include <string>

using namespace std;

char* arr;
int n;
int tmp;
string result;

void dfs(int cur) {
    if (cur > n) return;

    dfs(cur * 2);
    cout << arr[cur];
    dfs(cur * 2 + 1);
}

int main() {

    for (int tc = 1; tc <= 10; tc++) {
        cout << "#" << tc << " ";

        cin >> n;
        cin.ignore();
        arr = new char[n + 1];

        for (int i = 1; i <= n; i++) {
            string input;
            cin >> tmp;
            getline(cin, input);
            arr[i] = input[1];
        }

        dfs(1);
        cout << "\n";

        delete[] arr;
    }

    cout << result;

    return 0;
}
