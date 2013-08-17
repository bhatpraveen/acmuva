/* UVa 469 Wetlands of Florida http://uva.onlinejudge.org/external/4/469.html */
#include <cstdio>
#include <iostream>
#include <string.h>
using namespace std;

static int m, n;
static bool grid[100][100] = {};
static bool gridBkup[100][100] = {};
static int area[100][100] = {};
static bool visited[100][100] = {};

int CheckNeighbours(int i, int j) {
    int area = 0;
    if(visited[i][j] == true)
        return 0;

    visited[i][j] = true;

    if (j > 0 && grid[i][j-1]) area += CheckNeighbours(i, j-1); //left
    if (j+1 < n && grid[i][j+1]) area += CheckNeighbours(i, j+1); //right
    if (i > 0 && grid[i-1][j]) area += CheckNeighbours(i-1, j); //up
    if (i+1 < m && j < n && grid[i+1][j]) area += CheckNeighbours(i+1, j); //down
    if (i > 0 && j > 0 && grid[i-1][j-1]) area += CheckNeighbours(i-1, j-1); //diagonal left
    if (i+1 < m && j > 0 && grid[i+1][j-1]) area += CheckNeighbours(i+1, j-1); //diagonal left down
    if (i+1 < m && j+1 < n && grid[i+1][j+1]) area += CheckNeighbours(i+1, j+1); //diagonal right down
    if (i > 0 && j+1 < n && grid[i-1][j+1]) area += CheckNeighbours(i-1, j+1); //diagonal right up

    grid[i][j] = false;
    visited[i][j] = false;

    return 1 + area;
}

int main() {
    int t, r, c, waterArea;
    char peek;
    if(scanf("%d", &t) == EOF)
        return 0;
    while(t--) {
        string s;
        //cin >> s; //blank line
        m = n = 0;
        while(1) {
            cin >> peek;
            if(peek < 'L') {
                cin.unget();
                break; //end of grid input
            }
            cin.unget();
            cin >> s;
            n = s.size();
            for (int j = 0; j < n; ++j) {
                if(s[j] == 'W') grid[m][j] = true;
                else grid[m][j] = false;
            }
            //cout << s << " ";
            m++;
            //cout << m << endl;
        }
        //cout << "m=" << m << " n= " << n << endl;

        memcpy(gridBkup, grid, 10000*sizeof(bool));
        while(cin >> peek) {
            if(peek < '0' || peek > '9') {
                cin.unget();
                break;
            }
            cin.unget();
            cin >> r >> c;

            r--; c--; //index 1 based input

            waterArea = 0;
            memcpy(grid, gridBkup, 10000*sizeof(bool));
            if(grid[r][c]) waterArea = CheckNeighbours(r, c);
            printf("%d\n", waterArea);
        }

        if (t > 0) {
            printf("\n"); //blank between tests
        }
    }
    return 0;
}
