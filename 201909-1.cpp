#include <iostream>
#include <stdlib.h>
#include <cstring>
using namespace std;

int main() {
    int n, m, T = 0, total = 0;
    cin >> n >> m;
    int* a = (int*) malloc (sizeof(int) * n);
    memset(a, 0, sizeof(int) * n);
    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        total += x;
        for (int j = 1; j <= m; j++) {
            cin >> x;
            a[i] += -x;
        }
    }
    T = total;
    for (int i = 0; i < n; i++) {
        T -= a[i];
    }
    int maxi = -1;
    int index = -1;
    for (int i = 0; i < n; i++) {
        if (a[i] > maxi) {
            maxi = a[i];
            index = i;
        }
    }
    cout << T << " " << index+1 << " " << maxi << endl;
    return 0;
}
/*
3 3
73 -8 -6 -4
76 -5 -10 -8
80 -6 -15 0
*/