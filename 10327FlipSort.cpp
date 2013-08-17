/* 10327 Flip Sort */
#include <iostream>

using namespace std;

int main() {
    int n;
    while(cin >> n) {
        int count = 0, i, j, temp,arr[1000];

        for( i = 0; i < n; i++ ) {
            cin >> arr[i];
        }
        for( i = 0; i < n; i++ ) {
            for( j = 0; j < n - 1; j++ ) {
                if( arr[j] > arr[j+1] ) {
                    temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;

                    count++;
                }
            }
        }
        cout << "Minimum exchange operations : " << count << endl;
    }
    return 0;
}
