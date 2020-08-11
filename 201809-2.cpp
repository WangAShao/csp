#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> time_seg;
    int x, y;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        time_seg.emplace_back(make_pair(x, y));
    }
    int i = 0;
    long long ans = 0;
    for (int j = 0; j < n; j++) {
        cin >> x >> y;
        while (i < n) {
            if (y <= time_seg[i].first) {
                break;
            } else if (x >= time_seg[i].second) {
                i++;
            } else {
                int maxx = x <= time_seg[i].first ? time_seg[i].first : x;
                int miny = y <= time_seg[i].second ? y : time_seg[i].second;
                ans += (miny - maxx);
                /* fix bug：一开始提交20分的bug就是因为忽视了可能存在有一个人在广场很久，然后另一个人搬了好几次  */
                if (time_seg[i].second >= y) {
                    break;
                } else {
                    i++;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}