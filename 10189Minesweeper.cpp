/* UVa 10189 - Minesweeper */
#include <iostream>
#include <string.h>
using namespace std;

int main() {
    int m, n;
    char c;
    int x = 0;

    int field[102][102];

    while ((cin >> m >> n)) {
        if (m == 0 && n == 0)
            break;
        if (x > 0)
            cout << endl;
        x++;
        memset(field, 0, 102 * 102 * sizeof(int));
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                cin >> c;
                switch(c){
                case '*':
                    field[i][j] = -10; //mine
                    field[i - 1][j - 1]++; field[i - 1][j]++; field[i - 1][j + 1]++;
                    field[i][j - 1]++; field[i][j + 1]++;
                    field[i + 1][j - 1]++; field[i + 1][j]++; field[i + 1][j + 1]++;
                    break;
                case '.':
                default:
                    break;
                }
            }
            cin.ignore();
        }
        cout << "Field #" << x << ":" << endl;
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if(field[i][j] < 0)
                    cout << '*';
                else
                    cout << field[i][j];
                }
                cout << endl;
            }
    }

    return 0;
}
