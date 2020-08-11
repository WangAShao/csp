#include <iostream>
#include <stack>
#include <queue>
#include <cstdio>
using namespace std;
/* 利用栈实现四则运算 */
/* 唉， 这样写太麻烦了， 我突然想到了一种更好的写法 */
// int main() {
//     int n;
//     cin >> n;
//     char str[8];
//     stack<char> op;
//     queue<char> expr;
//     stack<int> num;
//     for (int i = 0; i < n; i++) {
//         // fgets(str, 8, stdin);
//         cin >> str;
//         cout << str<< endl;
//         /* 首先将中缀表达式变为后缀表达式 */
//         for (int j = 0; j < 7; j++) {
//             switch (str[j]) {
//                 case 'x':
//                 case '/':
//                     op.push(str[j]);
//                     break;
//                 case '+':
//                 case '-':
//                     if (op.empty()) {
//                         // cout << "debug: " << str[j] << endl;
//                         op.push(str[j]);
//                     } else {
//                         while (!op.empty()) {
//                             if (op.top() == 'x' || op.top() == '/') {
//                                 expr.push(op.top());
//                                 op.pop();
//                                 continue;
//                             } else {
//                                 break;
//                             }
//                         }
//                         op.push(str[j]);
//                     }
//                     break;
//                 default:
//                     expr.push(str[j]);
//             }
//         }
//         while (!op.empty()) {
//             expr.push(op.top());
//             op.pop();
//         }
//         int val1;
//         int val2;
//         /* 现在的expr就是后缀表达式 */
//         while (!expr.empty()) {
//             cout << expr.front() << " ";
//             switch(expr.front()) {
//                 case '+':
//                     val1 = num.top();
//                     num.pop();
//                     val2 = num.top();
//                     num.pop();
//                     num.push((val1 + val2));
//                     break;
//                 case '-':
//                     val1 = num.top();
//                     num.pop();
//                     val2 = num.top();
//                     num.pop();
//                     num.push(val2 - val1);
//                     break;
//                 case 'x':
//                     val1 = num.top();
//                     num.pop();
//                     val2 = num.top();
//                     num.pop();
//                     num.push(val1*val2);
//                     break;
//                 case '/':
//                     val1 = num.top();
//                     num.pop();
//                     val2 = num.top();
//                     num.pop();
//                     num.push(val2/val1);
//                     break;
//                 default:
//                     num.push(expr.front() - '0');
//             }
//             expr.pop();
//         }
//         if (num.top() != 24) {
//             cout << "No" << endl;
//         } else {
//             cout << "Yes" << endl;
//         }
//     }
// }
/*
10
9+3+4x3
5+4x5x5
7-9-9+8
5x6/5x4
3+5+7+9
1x1+9-9
1x9-5/9
8/5+6x9
6x7-3x6
6x4+4/5
*/
char str[8] = {0};
stack<int> num;
queue<char> op;
stack<int> num2;
int main() {
    int n;
    cin >> n;
    int val1, val2;
    for (int i = 0; i < n; i++) {
        cin >> str;
        for (int j = 0; j < 7; j++) {
            switch(str[j]) {
                case 'x':
                    val1 = num.top();
                    num.pop();
                    val2 = str[j+1]-'0';
                    num.push(val1*val2);
                    j++;
                    break;
                case '/':
                    val1 = num.top();
                    num.pop();
                    val2 = str[j+1]-'0';
                    num.push(val1/val2);
                    // cout << "debug:" << num.top() << endl;
                    j++;
                    break;
                case '+':
                case '-':
                    op.push(str[j]);
                    break;
                default:
                    num.push(str[j] - '0');
            }
        }
        /* fix bug: 8+9-1+8, 还是要注意运算顺序哒 */
        while (!num.empty()) {
            num2.push(num.top());
            num.pop();
        }
        while (!op.empty()) {
            char o = op.front();
            op.pop();
            val1 = num2.top();
            num2.pop();
            val2 = num2.top();
            num2.pop();
            switch (o) {
                case '+':
                    num2.push(val1 + val2);
                    break;
                case '-':
                    num2.push(val1-val2);
                    break;
            }
        }
        if (num2.top() != 24) {
            cout << "No" << endl;
        }  else {
            cout << "Yes" << endl;
        }
        num2.pop();
    }
    return 0;
}