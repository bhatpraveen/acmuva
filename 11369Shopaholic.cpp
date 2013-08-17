/* 11369 - Shopaholic */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t, n, p;
    vector<int> prices;
    cin >> t;

    while(t--) {
        int discount = 0;

        cin >> n;
        if (n < 3) {
            cin.ignore();
            cout << discount << endl;
            continue;
        }

        while(n--) {
            cin >> p;
            prices.push_back(p);
        }

        sort(prices.begin(), prices.end());

        for (int i = prices.size() - 1, j = 1; i >= 0; --i, ++j) {
            if(j%3 == 0) discount += prices[i];
        }
        cout << discount << endl;
        prices.clear();
    }

    return 0;
}
