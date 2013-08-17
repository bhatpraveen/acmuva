/* UVa 10340 All in all: http://isaac.lsu.edu/uva/103/10340.html */
#include <iostream>
using namespace std;

int main() {
    string s, t;
    int ssize, tsize;

    while(cin >> s >> t) {
        ssize = s.size();
        tsize = t.size();
        int j, found;
        j = found = 0;
        for(int i = 0; i < ssize && j < tsize; ++i) {
            while(j < tsize) {
                if (s[i] == t[j++]) {
                    found++;
                    break;
                }
            }
        }
        if(found == ssize) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}
