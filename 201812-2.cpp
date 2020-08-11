#include <iostream>

using namespace std;
/* 我也是醉了， 得60分是因为int不够用， 得换成long long */
long long now = 0;
int r, y, g;
/* r - g - y */
/* 1   3   2 */
void update_state(int* k, int* t) {
    int cur;
    switch (*k) {
        case 0:
            return;
        case 1:
            cur = r - *t;
            break;
        case 2:
            cur = r + g + y - *t;
            break;
        case 3:
            cur = r + g - *t;
            break;
        default:
            break;
    }
    int a = (cur + now) % (r+y+g); 
    if (a >= r) {
        if (a >= r + g) {
            *k = 2;
            *t = r + g + y - a;
        } else {
            *k = 3;
            *t = r + g - a;
        }
    } else { 
        *k = 1;
        *t = r - a;
    }
}   

int main() {
    cin >> r >> y >> g;
    int n;
    cin >> n;
    int k, t;
    for (int i = 0; i < n; i++) {
        cin >> k >> t;
        update_state(&k, &t);
        // cout << "debug: " << " now: " << now << " k: " << k << " t: " << t << endl;
        switch (k) {
            case 0:
                now += t;
                break;
            case 1:
                now += t;
                break;
            case 2:
                now += (t+r);
                break;
            default:
                break;
        }
    }
    cout << now << endl;
    return 0;
}