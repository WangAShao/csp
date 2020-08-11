#include <iostream>
#include <stdio.h>

using namespace std;
int num[1000010];

int main() {
    int n;
    cin >> n;
    int maxn, minn;
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
    if (num[0] >= num[n-1]) {
        maxn = num[0];
        minn = num[n-1];
    } else {
        maxn = num[n-1];
        minn = num[0];
    }
    cout << maxn << " ";
    int tmp;
    if (n % 2 == 0) {
        tmp = num[n/2] + num[n/2 - 1];
        if (tmp % 2 == 0) {
            printf("%d ", tmp/2);
        } else {
            printf("%.1lf ", (double)tmp / 2);
        }
    } else {
        printf("%d ", num[n/2]);
    }
    cout << minn << endl;
    return 0; 
}
/*
3
-1 2 4

4
-2 -1 3 4
*/