#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
/* 借钥匙与还钥匙看作两个事件 */
struct key {
    int id;
    int time;
    int borrow;
};

int cmp(const key &a, const key &b) {
    if (a.time != b.time) {
        return a.time < b.time;
    } else if (a.borrow != b.borrow) {
        return a.borrow < b.borrow;
    } else {
        return a.id < b.id;
    }
}

vector<key> v;
int main() {
    int n, k;
    cin >> n >> k;
    int order[n];
    for (int i = 0; i < n; i++) {
        order[i] = i+1;
    }
    int end = -1;
    for (int i = 0; i < k; i++) {
        int w, s, c;
        cin >> w >> s >> c;
        key key1 = {
            .id = w,
            .time = s,
            .borrow = 1
        };
        key key2 = {
            .id = w,
            .time = s + c,
            .borrow = 0
        };
        v.emplace_back(key1);
        v.emplace_back(key2);
    }
    sort(v.begin(), v.end(), cmp);
    for (int i = 0; i < v.size(); i++) {
        if(v[i].borrow) {
            /* 借 */
            for (int j = 0; j < n; j++) {
                if (order[j] == v[i].id) {
                    order[j] = 0;
                    break;
                }
            }
        } else {
            /* 还 */
            for (int j = 0; j < n; j++) {
                if (order[j] == 0) {
                    order[j] = v[i].id;
                    break;
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << order[i] << " ";
    }
    return 0;
}