#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a+n);
    int minres = 0x7fffffff;
    for (int i = 0; i < n-1; i++) {
        if (abs(a[i+1]-a[i]) < minres) {
            minres = abs(a[i+1]-a[i]);
        }
    }
    cout << minres;
    return 0;
}