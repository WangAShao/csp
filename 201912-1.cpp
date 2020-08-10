#include <iostream>

int n, a[4];

using namespace std;

bool contain7 (int x) {
    int y;
    while (x != 0) {
        y = x % 10;
        if (y == 7) return true;
        x /= 10;
    }
    return false;
}

int main() {
    cin >> n;
    int k = 0;
    int num = 1;
    while (k < n) {
        if (num % 7 == 0 || contain7(num)) {
            a[(num-1)%4] += 1;
            num++;
            continue;
        }
        num++;
        k++;
    }
    cout << a[0] << endl << a[1] << endl << a[2] << endl << a[3] << endl;
    return 0;
}