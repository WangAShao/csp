#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

struct node {
    int x;
    int y;
    node(){}
    node(int a, int b) {
        x = a;
        y = b;
    }
    bool operator <(const node &that) const{
        if (x != that.x) {
            return x < that.x;
        }
        return y < that.y;
    }
} pos[1010];

map <node, bool> mp;
int res[6];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> pos[i].x >> pos[i].y;
        mp[pos[i]] = 1;
    }
    for (int i = 0; i < n; i++) {
        int cnt = 0;
        int x = pos[i].x;
        int y = pos[i].y;
        if (mp[node(x+1, y)] && mp[node(x-1, y)] && mp[node(x, y+1)] && mp[node(x, y-1)]) {
            cnt = mp[node(x+1, y+1)] + mp[node(x+1, y-1)] + mp[node(x-1, y+1)] + mp[node(x-1, y-1)];
            res[cnt]++;
        }
    }

    for (int i = 0; i < 5; i++) {
        cout << res[i] << endl;
    }
    return 0;
}