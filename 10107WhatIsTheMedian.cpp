/*  UVa 10107 What is the Median? */

#include <iostream>
#include <map>

using namespace std;

int main() {
    std::map<long, int> numset;
    std::map<long, int>::iterator iter;

    long X;
    long median;
    int N = 1;
    while(cin >> X) {
        numset[X] = N;
        //cout << "Value of N is: " << N << endl;
        //cout << "Value of X is: " << X << endl;

        int tmp = (N+1)/2;
        iter = numset.begin();
        std::advance(iter, tmp-1);

        if(N%2) {
            //cout << "Median is at index: " << tmp << endl;
            median = iter->first;
        }
        else {
            //cout << "Median is at indices: " << tmp << " and " << tmp + 1 << endl;
            median = iter->first;
            ++iter;
            median += iter->first;
            median /= 2;
        }

        cout << median << endl;
/*
        for(iter = numset.begin(); iter != numset.end(); ++iter) {
            cout << iter->first << " : " << iter->second << endl;
        }
*/
    ++N;
    }

    return 0;
}
