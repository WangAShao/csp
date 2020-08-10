#include <iostream>
//#include <stdlib.h>
#include <vector>

using namespace std;

/* 60 score */
// typedef struct node {
//     int index;
//     int val; 
// } node;

// int main() {
//     int n, a, b;
//     cin >> n >> a >> b;
//     node* v1 = (node*) malloc (sizeof(node) * a);
//     // node* v2 = (node*) malloc (sizeof(node) * b);
//     for (int i = 0; i < a; i++) {
//         cin >> v1[i].index >> v1[i].val;
//     }
//     int ans = 0;
//     int i = 0;
//     int index, val;
//     for (int k = 0; k < b; k++) {
//         cin >> index >> val;
//         while (i < a) {
//             if (index < v1[i].index) {
//                 break;
//             } else if (index > v1[i].index) {
//                 i++;
//             } else {
//                 ans += val * v1[i].val;
//                 i++;
//             }
//         }
//     }
//     cout << ans;
//     return 0;
// }
/*
10 3 4
4 5
7 -3
10 1
1 10
4 20
5 30
7 40

output: -20
*/

int main() {
    int n, a, b, x, y;
    long long product = 0;
    cin >> n >> a >> b;
    vector<pair<int, int>> v1;
    for (int i = 0; i < a; i++) {
        cin >> x >> y;
        v1.emplace_back(make_pair(x, y));
    }
    int i=0, x1, y1;
    for (int j = 0; j < b; j++) {
        cin >> x1 >> y1;
        while (i < a) {
            if (x1 < v1[i].first) {
                break;
            } else if (x1 > v1[i].first) {
                i++;
            } else {
                product += y1 * v1[i].second;
                i++;
            }
        }  
    }
    cout << product << endl;
    return 0;
}