#include <iostream>

using namespace std;

int main() {
    int r, y, g;
    cin >> r >> y >> g;
    int n;
    cin >> n;
    int res = 0;
    int k, t;
    for (int i = 0; i < n; i++) {
        cin >> k >> t;
        switch (k) {
            case 0:
                res += t;
                break;
            case 1:
                res += t;
                break;
            case 2:
                res += (t+r);
                break;
            default:
                break;
        }
    }
    cout << res << endl;
}