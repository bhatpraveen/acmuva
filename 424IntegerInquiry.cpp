/* UVa 424 - Integer Inquiry */
#include <iostream>
#include <string>
using namespace std;

int main() {
    int n = 0;
    string nums[101];
    int lens[101];
    int sum[101]= {};
    int si = 0; //sum index
    int carry = 0;
    int maxlen = 0;
    int digit = 0;

    while(cin >> nums[n]) {
        //cout << nums[n] << endl;
        if(!nums[n].compare("0"))
            break;
        lens[n] = nums[n].size();
        //cout << lens[n] << endl;
        if(lens[n] > maxlen) maxlen = lens[n];
        n++;
    }
    if(n == 0) return 0;
    //cout << "n= " << n << endl;
    //cout << "maxlen= " << maxlen << endl;

    for(int l = 0; l < maxlen; ++l) {
        for (int i = 0; i < n; ++i) {
            if (lens[i]) {
                carry += nums[i][lens[i] - 1] - '0';
                lens[i]--;
            }
        }
        sum[si++] = (carry % 10);
        carry = carry/10;
        //cout << l << ": digit sum= " << sum[si-1] << " & carry= " << carry << endl;
    }
    if(carry) {
        sum[si] = carry;
        maxlen++;
    }

    //while(maxlen >= 0 && sum[maxlen] == 0) maxlen--; //skip leading zeroes (works well, but not needed, crosschecked with UVa toolkit)
    //maxlen++;
    while(maxlen--) cout << sum[maxlen];
    cout << endl;

    return 0;
}
