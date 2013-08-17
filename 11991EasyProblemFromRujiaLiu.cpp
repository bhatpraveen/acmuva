/* 11991 - Easy Problem from Rujia Liu? */
#include <cstdio>
#include <vector>
using namespace std;

#define MAXN 1000001
vector<int> arr[MAXN];

int main() {
    int n, m, k, v, num;

    while(scanf("%d %d", &n, &m) == 2) {
        for (int i = 1; i < MAXN; ++i) {
            arr[i].clear();
        }

        for (int i = 1; i <= n; ++i) {
            scanf("%d", &num);
            arr[num].push_back(i);
        }

        while(m--) {
            scanf("%d %d", &k, &v);
            //find kth occurrence of v
            if(arr[v].size() < k) printf("%d\n", 0);
            else printf("%d\n", arr[v][k-1]);
        }
    }
    return 0;
}

