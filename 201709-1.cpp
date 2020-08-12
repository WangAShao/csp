#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int ans = 0;
    while (true) {
        if (n >= 50) {
            n -= 50;
            ans += 7;
        } else if (n >= 30) {
            n -= 30;
            ans += 4;
        } else if (n != 0) {
            ans += n/10;
            break;
        } else if (n == 0) {
            break;
        }
    }
    cout << ans;
    return 0;
}