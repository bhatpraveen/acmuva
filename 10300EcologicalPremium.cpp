/* UVa 10300 - Ecological Premium */
#include <iostream>
using namespace std;

int main() {
    int n, f;
    long long int landsize, animals, ecopremium;
    long long int budget = 0;
    cin >> n;
    while(n--) {
        cin >> f;
        budget = 0;
        while(f--) {
            cin >> landsize >> animals >> ecopremium;
            budget += landsize * ecopremium;
        }
        cout << budget << endl;
    }

    return 0;
}
