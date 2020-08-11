#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int price[1010];
    int tomorrow[1010];
    for (int i = 0; i < n; i++) {
        cin >> price[i];
    }
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            tomorrow[0] = (price[0] + price[1]) / 2;
        } else if (i == n-1) {
            tomorrow[n-1] = (price[n-2] + price[n-1]) / 2;
        } else {
            tomorrow[i] = (price[i-1] + price[i] + price[i+1]) / 3;
        }
    } 
    for (int i = 0; i < n; i++) {
        cout << tomorrow[i] << " ";
    }
    return 0;
}