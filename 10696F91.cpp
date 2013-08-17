/* 10696 - f91 */
#include <iostream>
using namespace std;

/*
No need for this function, it does after several recursions what main does in a statement! :)
int f91(int n) {
    //cout << n << " ";
    if (n <= 100)
        return (f91(f91(n + 11)));
    else
        return n - 10;
}
*/

int main() {
    int n;
    while(1) {
        cin >> n;
        if (n < 1)
            return 0;

        //cout << "f91(" << n << ") = " << f91(n) << endl;
        cout << "f91(" << n << ") = ";
        if (n <= 100) cout << 91;
        else cout << n - 10;
        cout << endl;
    }

    return 0;
}
