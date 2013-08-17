/* UVa 10038 Problem E: Jolly Jumpers */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    vector<int> diff;
    int n, no, prev = 0;
    string skip;
    while(cin >> n) {

        bool jj = true;

        if(n <= 1) {
            cout << "Jolly" << endl;
            getline(cin, skip);
            continue;
        }
        cin >> no;
        prev = no;
        for(int i = 1; i < n; ++i) {
            cin >> no;

            diff.push_back(abs(prev-no));
            //cout << "Pushing back " << abs(prev-no) << endl;

            prev = no;
        }
        //for(vector<int>::iterator it = diff.begin(); it != diff.end(); ++it)
            //cout << *it << endl;
        //cout << endl;

        std::sort(diff.begin(), diff.end());
        int i = 1;
        for(vector<int>::iterator it = diff.begin(); it != diff.end(); ++it) {
            //cout << *it << endl;

            if(*it != i) {
                jj = false;
                break;
            }
            ++i;
        }
        if(jj)
            cout << "Jolly" << endl;
        else
            cout << "Not jolly" << endl;
        diff.clear();
    }

    return 0;
}
