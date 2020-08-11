#include <iostream>

using namespace std;

int main() {
    int n, L, t;
    cin >> n >> L >> t;
    int pos[n+1];
    int v[n+1];
    for (int i = 1; i <= n; i++) {
        cin >> pos[i];
        v[i] =  1;
    } 
    int k = 0;
    while (k < t) {
        // for (int i = 1; i <= n; i++) {
        //     cout << pos[i] << " ";
        // }
        // cout << endl;
        int flag[L+1] = {0};
        for (int i = 1; i <= n; i++) {
            pos[i] += v[i];
            if (flag[pos[i]] != 0) {
                v[flag[pos[i]]] = -v[flag[pos[i]]];
                v[i] = -v[i];
            } else {
                flag[pos[i]] = i;
            }
            if (pos[i] == 0 && v[i] == -1) {
                v[i] = 1;
            } else if (pos[i] == L && v[i] == 1) {
                v[i] = -1;
            }
        }
        k++;
    }
    for (int i = 1; i <= n; i++) {
        cout << pos[i] << " ";
    }
    // cout << "hello";
    return 0;
}