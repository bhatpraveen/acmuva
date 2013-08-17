/* 11389 - The Bus Driver Problem */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, d, r;
    int rl, sum;
    vector<int> morning;
    vector<int> evening;

    while (cin >> n >> d >> r) {
        //cout << n << d << r << endl;
        if (n == 0 && d == 0 && r == 0)
            return 0;

        sum = 0;
        for (int i = 0; i < n; ++i) {
            cin >> rl;
            morning.push_back(rl);
        }

        for (int i = 0; i < n; ++i) {
            cin >> rl;
            evening.push_back(rl);
        }

        sort(morning.begin(), morning.end());
        sort(evening.begin(), evening.end());

        for(int i = 0, j = n - 1; i < n; ++i, --j) {
            //cout << "m= " << morning[i] << " e= " << evening[j] << endl;
            if (morning[i] + evening[j] > d)
                sum += morning[i] + evening[j] - d;
        }

        cout << sum * r << endl;

        morning.clear();
        evening.clear();
    }
}
