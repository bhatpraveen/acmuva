/* UVa 543 Goldbach's Conjecture */
#include <iostream>
#include <math.h>

const int MILLION = 1000000;

using namespace std;

int main() {
    int n, a, b, half;
    bool conjecture;
    int square;
    int root = (int) sqrt(MILLION);
    bool primes[MILLION];
    for (int i = 2; i < MILLION; ++i)
        primes[i] = true;

//Sieve of Eratosthenes
    for (int i = 2; i <= root; ++i) {
        if(primes[i]) {
            square = i * i;
            int m = 1;
            for(int j = square; j <= MILLION; j = square + (m * i)) {
                primes[j] = false;
                ++m;
            }
        }
    }

    while(cin >> n) {
        if(n == 0)
            return 0;
        conjecture = false;
        half = n/2;
        for(a = 3; a <= half; ++a) {
            b = n - a;
            if(primes[a] && primes[b]) {
                conjecture = true;
                break;
            }
        }
        if(conjecture)
            cout << n << " = " << a << " + " << b << endl;
        else
            cout << "Goldbach's conjecture is wrong." << endl;
    }
}
