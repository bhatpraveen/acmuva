/* 12442 - Forwarding Emails */
#include <iostream>

using namespace std;
const int MAX = 50000 + 1;

int sendsTo[MAX];
bool visited[MAX];
int chain[MAX];

int DFS(int v) {
    if (visited[v] == true)
        return 0;

    //cout << "DFS: " << v << endl;

    visited[v] = true;
    chain[v] = 1 + DFS(sendsTo[v]); //cost = 1
    visited[v] = false;

    return chain[v];
}

int main() {
    int t, n, u, v;

    int source, longest;

    cin >> t;
    for (int c = 1; c <= t; ++c) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> u >> v;
            sendsTo[u] = v;

            visited[i] = false;
            chain[i] = 0;
        }

        longest = 0;
        for (int i = 1; i <= n; ++i) {
            if (chain[i] == 0) {
                //cout << "DFS: " << i << " " << DFS(i) << endl;
                chain[i] = DFS(i);
            }
            if (chain[i] > longest) {
                longest = chain[i];
                source = i;
            }
        }

        //for (int i = 1; i <= n; ++i)
                //cout << "DEBUG: chain[" << i << "] = " << chain[i] << endl;
        cout << "Case " << c << ": " << source << endl;
    }

    return 0;
}
