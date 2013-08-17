#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>

using namespace std;

int main() {
    int t, n;
    string phone;
    vector<string> phoneList;

    cin >> t;
    while (t--) {
        bool consistent = true;
        cin >> n;
        if(n == 1) {
            cin.ignore();
            cout << "YES" << endl;
            continue;
        }
        while(n--) {
            cin >> phone;
            phoneList.push_back(phone);
        }
        sort(phoneList.begin(), phoneList.end());

        int sz = phoneList.size() - 1;
        for (int i = 0; i < sz; ++i) {
            string phone1 = phoneList[i];
            int len1 = phone1.size();
            string phone2 = phoneList[i + 1];
            int len2 = phone2.size();
            int len = len1 < len2? len1: len2;


            if (!strncmp(phone1.c_str(), phone2.c_str(), len)) {
                consistent = false;
                break;
            }
        }
        consistent? cout << "YES" << endl: cout << "NO" << endl;
        phoneList.clear();
    }

    return 0;
}
