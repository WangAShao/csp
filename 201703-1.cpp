#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int weight[n];
    for (int i = 0; i < n; i++) {
        cin >> weight[i];
    }
    /* 靠， 看错题目了，我以为是先将手中重量最小的分给它 */
    // sort(weight, weight+n);
    int ans = 0;
    int per = 0;
    for (int i = 0; i < n; i++) {
        per += weight[i];
        if (per >= k) {
            per = 0;
            ans += 1;
        }
    }
    if (per != 0) ans += 1;
    cout << ans;
    return 0;
}