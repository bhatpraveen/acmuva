/* 10098 - Generating Fast http://uva.onlinejudge.org/external/100/10098.pdf */
#include <iostream>
#include <algorithm>
#include <ctype.h>
#include <string.h>
using namespace std;

int main() {
    int n, len;
    string s;

    cin >> n;
    while(n--) {
        cin >> s;

        len = s.size();
        std::sort(s.begin(), s.begin() + len);

        do {
            cout << s << endl;
        } while (std::next_permutation(s.begin(), s.begin() + len));
        cout << endl;
    }

    return 0;
}
