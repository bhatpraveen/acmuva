/* 195 - Anagram http://uva.onlinejudge.org/external/1/195.pdf */
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

bool cmp(char c1, char c2) {
    char lc1 = c1 < 'a'? c1 + 32: c1; //tolower
    char lc2 = c2 < 'a'? c2 + 32: c2; //tolower
    if (lc1 == lc2) return c1 < c2;
    return lc1 < lc2;
}

int main() {
    int n, len;
    string s;

    cin >> n;
    while(n--) {
        cin >> s;

        len = s.size();
        std::sort(s.begin(), s.begin() + len, cmp);

        do {
            cout << s << endl;
        } while (std::next_permutation(s.begin(), s.begin() + len, cmp));
    }

    return 0;
}
