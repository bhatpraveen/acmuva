/* UVa 401 Palindromes */
#include <iostream>
#include <map>
#include <string>
#include <string.h>
using namespace std;

map<char, char> mirror;

inline string ReverseString(string s) {
    string r = s;
    for(int i = 0, j = s.size() - 1; i < s.size(); ++i, --j)
        r[j] = s[i];
    r[s.size()] = '\n';
    return r;
}

inline bool IsPalindrome(string s) {
    string r = ReverseString(s);
    //cout << s << " " << r << endl;
    //return (!strcmp(s.c_str(), r.c_str()));
    return (s == r);
}

inline bool IsMirroredString(string s) {
    string m = s;
    for (int i = 0; i < s.size(); ++i)
        m[i] = mirror[s[i]];
    m[s.size()] = '\n';
    //cout << s << " " << m << endl;
    m = ReverseString(m);
    //return (!strcmp(s.c_str(), m.c_str()));
    return (s == m);
}

int main() {
    mirror['A'] = 'A'; mirror['M'] = 'M'; mirror['Y'] = 'Y'; mirror['Z'] = '5'; mirror['O'] = 'O'; mirror['J'] = 'L'; mirror['V'] = 'V';
    mirror['1'] = '1'; mirror['2'] = 'S'; mirror['E'] = '3'; mirror['3'] = 'E'; mirror['S'] = '2'; mirror['5'] = 'Z'; mirror['H'] = 'H';
    mirror['T'] = 'T'; mirror['I'] = 'I'; mirror['U'] = 'U'; mirror['8'] = '8'; mirror['W'] = 'W'; mirror['L'] = 'J'; mirror['X'] = 'X';

    string s;
    bool rp, ms;
    while(cin >> s) {
        rp = ms = false;

        rp = IsPalindrome(s);
        ms = IsMirroredString(s);

        cout << s << " -- is ";
        if(ms)
            if(rp)
                cout << "a mirrored palindrome." << endl;
            else
                cout << "a mirrored string." << endl;
        else if(rp)
                cout << "a regular palindrome." << endl;
        else
            cout << "not a palindrome." << endl;
        cout << endl;
    }
    return 0;
}
