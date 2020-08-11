#include <iostream>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int valid[n] = {0};
    int num = 0;
    int index = 0;
    int cnt = n;
    while (true) {
        if (valid[index] == 0) {
            num++;
            if (num % k == 0 || num % 10 == k) {
                // cout << "num:" << num << " index: " << index + 1 << endl;
                valid[index] = 1;
                cnt--;
            }
        }
        if (cnt == 1) break;
        index = (index + 1) % n;
    }
    for (int i = 0; i < n; i++) {
        if (valid[i] == 0) {
            cout << i + 1;
            break;
        }
    }
    return 0;
}