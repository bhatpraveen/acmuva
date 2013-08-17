/* 10954 Add all */
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
    int n, num;
    int sum, prev1, prev2;
    priority_queue< int, vector<int>, greater<int> > pq;

    while(cin >> n) {
        if (n == 0)
            break;
        sum = 0;
        for(int i = 0; i < n; ++i) {
            cin >> num;
            pq.push(num);
        }

        while(1) {
            prev1 = pq.top();
            pq.pop();
            if(!pq.empty()) {
                prev2 = pq.top();
                pq.pop();
                sum += prev1 + prev2;
                pq.push(prev1 + prev2);
            }
            else {
                cout << sum << endl;
            break;
            }
        }
    }

    return 0;
}

