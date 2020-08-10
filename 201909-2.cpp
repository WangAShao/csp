#include <iostream>
#include <cstring>

using namespace std;

int main() {
    int n;
    cin >> n;
    int* a = (int*) malloc (sizeof(int) * n);
    int* b = (int*) malloc (sizeof(int) * n);
    memset(a, 0, sizeof(int)*n);
    memset(b, 0, sizeof(int)*n);
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        int x;
        cin >> x;
        a[i] = x;
        for (int j = 1; j < k; j++) {
            cin >> x;
            if (x <= 0) {
                a[i] += x;
            } else {
                if (a[i] != x) {
                    b[i] = 1;
                }
                a[i] = x;
            }
        }
    }
    int t = 0, d = 0;
    for (int i = 0; i < n; i++) {
        t += a[i];
        d += b[i];
    }
    int e = 0;
    for (int i = 0; i < n; i++) {
        if (b[i] && b[(i+1)%n] && b[(i-1+n)%n]) {
            e += 1;
        }
    }
    cout << t << " " << d << " " << e << endl;
    return 0;
}
/*
4
4 74 -7 -12 -5
5 73 -8 -6 59 -4
5 76 -5 -10 60 -2
5 80 -6 -15 59 0
*/