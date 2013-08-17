/* UVa 572 Oil Deposits http://uva.onlinejudge.org/external/5/572.html */
#include <cstdio>
#include <iostream>
#include <string.h>
using namespace std;

static int m, n;
//static string grid[101] = {};
static bool grid[101][101] = {};
static bool visited[101][101] = {};

bool CheckNeighbours(int i, int j) {
    if(visited[i][j] == true)
        return false;

    visited[i][j] = true;

    if (j > 0 && grid[i][j-1]) CheckNeighbours(i, j-1); //left
    if (j+1 < n && grid[i][j+1]) CheckNeighbours(i, j+1); //right
    if (i > 0 && grid[i-1][j]) CheckNeighbours(i-1, j); //up
    if (i+1 < m && j < n && grid[i+1][j]) CheckNeighbours(i+1, j); //down
    if (i > 0 && j > 0 && grid[i-1][j-1]) CheckNeighbours(i-1, j-1); //diagonal left
    if (i+1 < m && j > 0 && grid[i+1][j-1]) CheckNeighbours(i+1, j-1); //diagonal left down
    if (i+1 < m && j+1 < n && grid[i+1][j+1]) CheckNeighbours(i+1, j+1); //diagonal right down
    if (i > 0 && j+1 < n && grid[i-1][j+1]) CheckNeighbours(i-1, j+1); //diagonal right up

    grid[i][j] = false;
    visited[i][j] = false;

    return true;
}

int main() {
    while(scanf("%d %d", &m, &n) == 2) {
        if(m == 0) break;
        int deposits = 0;
        string s;
        for(int i = 0; i < m; ++i) {
            cin >> s;
            for (int j = 0; j < n; ++j) {
                if(s[j] == '@') grid[i][j] = true;
                else grid[i][j] = false;
            }
        }

        memset(visited, false, m*n*sizeof(bool));

        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(grid[i][j]) {
                    CheckNeighbours(i, j);
                    deposits++;
                }
            }
        }
        printf("%d\n", deposits);
    }
    return 0;
}
