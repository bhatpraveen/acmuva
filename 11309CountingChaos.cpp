/* 11309 - Counting Chaos */
#include <iostream>
using namespace std;
const int UC2INT = (const int) '0';

inline void tick(int &h1, int &h2, int &m1, int &m2) {
    int carry = 0;
    if (m2 == 9) {
        m2 = 0;
        if (m1 == 5) {
            m1 = 0;
            if (h2 == 3) {
                if (h1 == 2) {
                    h2 = 0;
                    h1 = 0;
                }
                else {
                    h2++;
                }
            }
            else if(h2 == 9) {
                h2 = 0;
                h1++;
            }
            else {
                h2++;
            }
        }
        else {
            m1++;
        }
    }
    else {
        m2++;
    }
}

inline bool isPalindrome(int &h1, int &h2, int &m1, int &m2) {
    bool isPalindrome = false;
    if(h1 == 0) {
        if(h2 == 0) {
            if(m1 == 0) isPalindrome = true;
            else if(m1 == m2) isPalindrome = true;
            else isPalindrome = false;
        }
        else {
            if(h2 == m2) isPalindrome = true;
            else isPalindrome = false;
        }
    }
    else {
        if(h1 == m2 && h2 == m1) isPalindrome = true;
        else isPalindrome = false;
    }
    return isPalindrome;
}

int main() {
    int n;
    unsigned char uch1, uch2, ucm1, ucm2;
    int h1, h2, m1, m2;
    char c;

    cin >> n;
    while(n--) {
        cin >> uch1 >> uch2 >> c >> ucm1 >> ucm2;

        h1 = (int)uch1 - UC2INT;
        h2 = (int)uch2 - UC2INT;
        m1 = (int)ucm1 - UC2INT;
        m2 = (int)ucm2 - UC2INT;

        do {
            tick(h1, h2, m1, m2);
            //cout << h1 << h2 << c << m1 << m2 << endl;
        } while (!isPalindrome(h1, h2,m1, m2));

        cout << h1 << h2 << c << m1 << m2 << endl;
    }

    return 0;
}
