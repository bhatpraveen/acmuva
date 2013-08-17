/* 11995 - I Can Guess the Data Structure! */
#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main() {
    int n, command, x, i;
    stack<int> s;
    queue<int> q;
    priority_queue<int> pq;
    bool isQ, isS, isPQ;

    while(cin >> n) {
        i = 0;
        isQ = isS = isPQ = true;
            while(n--) {
            cin >> command >> x;
            switch(command) {
            case 1:
                s.push(x);
                q.push(x);
                pq.push(x);
                break;
            case 2:
                if(!s.empty() && s.top() == x) {
                    if (i == 0) isS = true; //i checks that stack property didn't go false in earlier type 2 commands
                    //cout << "likely a stack" << endl;
                }
                else {
                    //cout << "not a stack" << endl;
                    isS = false;
                }
                if(!s.empty()) s.pop();

                if(!q.empty() && q.front() == x) {
                    if (i == 0) isQ = true; //i checks that queue property didn't go false in earlier type 2 commands
                    //cout << "likely a queue" << endl;
                }
                else {
                    isQ = false;
                    //cout << "not a queue" << endl;
                }
                if(!q.empty()) q.pop();

                if(!pq.empty() && pq.top() == x) {
                    if (i == 0) isPQ = true; //i checks that priority queue property didn't go false in earlier type 2 commands
                    //cout << "likely a PQ" << endl;
                }
                else {
                    isPQ = false;
                    //cout << "not a PQ" << endl;
                }
                if(!pq.empty()) pq.pop();

                break;
            default:
                break;
            }
            ++i;
        }
        if (isS)
            if (isQ || isPQ) cout << "not sure" << endl;
            else cout << "stack" << endl;
        else if (isQ)
            if (isPQ) cout << "not sure" << endl;
            else cout << "queue" << endl;
        else if (isPQ) cout << "priority queue" << endl;
        else cout << "impossible" << endl;

        s = stack<int>();
        q = queue<int>();
        pq = priority_queue<int>();
    }

    return 0;
}
