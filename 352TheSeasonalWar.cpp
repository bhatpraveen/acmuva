/* UVa 352 The Seasonal War http://uva.onlinejudge.org/external/3/352.html */
#include <cstdio>
#include <iostream>
using namespace std;

static int n;
static string pix[26] = {};
static bool visited[25][25] = {};

bool CheckNeighbours(int i, int j) {
    if(visited[i][j] == true)
        return false;

    visited[i][j] = true;

    if (j > 0 && pix[i][j-1] == '1') CheckNeighbours(i, j-1); //left, not needed?
    if (j+1 < n && pix[i][j+1] == '1') CheckNeighbours(i, j+1); //right
    if (i > 0 && pix[i-1][j] == '1') CheckNeighbours(i-1, j); //up, not needed?
    if (i+1 < n && j < n && pix[i+1][j] == '1') CheckNeighbours(i+1, j); //down
    if (i > 0 && j > 0 && pix[i-1][j-1] == '1') CheckNeighbours(i-1, j-1); //diagonal left up, not needed?
    if (i+1 < n && j > 0 && pix[i+1][j-1] == '1') CheckNeighbours(i+1, j-1); //diagonal left down
    if (i+1 < n && j+1 < n && pix[i+1][j+1] == '1') CheckNeighbours(i+1, j+1); //diagonal right down
    if (i > 0 && j+1 < n && pix[i-1][j+1] == '1') CheckNeighbours(i-1, j+1); //diagonal right up

    pix[i][j] = '0';
    visited[i][j] = false;

    return true;
}

int main() {
    int image = 0;

    while(scanf("%d", &n) == 1) {
        int eagles = 0;
        image++;

        for(int i = 0; i < n; ++i) cin >> pix[i];

        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j)
                visited[i][j] = false;

        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                if(pix[i][j] == '1') {
                    CheckNeighbours(i, j);
                    eagles++;
                }
            }
        }
        printf("Image number %d contains %d war eagles.\n", image, eagles);
    }
    return 0;
}
