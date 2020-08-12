#include <iostream>
#include <stack>

using namespace std;

int main() {
    int n;
    cin >> n;
    int m;
    cin >> m;
    int p, q;
    /* 这一题我想了一下，可以用两个栈来模拟，我他娘的真是个天才 */
    stack<int> s1;
    stack<int> s2;
    for (int i = 0; i < n; i++) {
        s1.push(i+1);
    }
    for (int i = 0; i < m; i++) {
        int tmp;
        cin >> p >> q;
        while (s1.top() != p) {
            tmp = s1.top();
            s2.push(tmp);
            s1.pop();
        }
        s1.pop();
        if (q > 0) {
            while(q--) {
                tmp = s2.top();
                s1.push(tmp);
                s2.pop();
            }
            s1.push(p);
            while (!s2.empty()) {
                tmp = s2.top();
                s1.push(tmp);
                s2.pop();
            }
        } else {
            q = -q;
            while (q--) {
                tmp = s1.top();
                s2.push(tmp);
                s1.pop();
            }
            s1.push(p);
            while (!s2.empty()) {
                tmp = s2.top();
                s1.push(tmp);
                s2.pop();
            }
        }
    }
    /* 注意目前顺序是个反的 */
    while (!s1.empty()) {
        int tmp = s1.top();
        s2.push(tmp);
        s1.pop();
    }
    while (!s2.empty()) {
        int tmp = s2.top();
        s2.pop();
        cout << tmp << " ";
    }
    return 0;
}