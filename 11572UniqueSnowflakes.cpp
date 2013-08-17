/* 11872 UVa Problem A: Unique Snowflakes */
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
    map<int,int> package;
    vector<int> contents;

    int largest = 0;
    int nTestCases, n, id, sz, i, clashed, erased;

    cin >> nTestCases;

    while(nTestCases > 0) {
        cin >> n;
        i = 0;
        erased = 0;

        while(n > 0) {
            cin >> id;
            i++;
            contents.push_back(id);
            std::pair<map<int, int>::iterator, bool> err = package.insert(std::make_pair(id, i));
            if (!err.second ) {
                //not unique
                clashed = (err.first)->second;
                package.erase(err.first);
                package[id] = i;

                //cout << "clashed= " << clashed << " erased= " << erased << endl;
                if (clashed > erased) {
                    sz = contents.size() - 1;
                    largest = largest < sz? sz: largest;
                    //cout << "largest so far: " << sz << endl;
                    //cout << "Erasing till: " << clashed - erased << endl;
                    contents.erase(contents.begin(), contents.begin() + clashed - erased);
                    erased = clashed > erased? clashed: erased;;
/*
                    cout << "Contents: ";
                    for (vector<int>::iterator it = contents.begin(); it != contents.end(); ++it) {
                        cout << *it << " ";
                    }
                    cout << endl;
*/
                }

            }
            --n;
        }
        sz = contents.size();
        largest = largest < sz? sz: largest;
        cout << largest << endl;
        largest = 0;
        package.clear();
        contents.clear();

        --nTestCases;
    }

    return 0;
}
