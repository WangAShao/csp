#include <iostream>

using namespace std;

int main() {
    int x;
    int cur_level = 0;
    int score = 0;
    while (true) {
        cin >> x;
        if (x == 0) break;
        if (x == 1) {
            cur_level = 1;
            score += cur_level;
        }
        if (x == 2) {
            if (cur_level == 0 || cur_level == 1) {
                /* 第一跳 */
                cur_level = 2;
            } else {
                cur_level += 2;
            }
            score += cur_level;
        }
    }
    cout << score << endl;
    return 0;
}