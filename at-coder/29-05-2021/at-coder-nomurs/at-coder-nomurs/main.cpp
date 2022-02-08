//
//  main.cpp
//  at-coder-nomurs
//
//  Created by Igor Peric on 29/5/21.
//

#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

int main(int argc, const char * argv[]) {
    
    vector<pair<int,int>> x, y;
    int X, Y;
    int n;
    cin >> n;
    for (int i=0;i<n;i++) {
        cin >> X >> Y;
        x.push_back({X,Y});
        y.push_back({Y,X});
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    
    multiset<int> sol;
    int k = 5;
    
    auto itXStart = x.begin();
    auto itXEnd = x.end();
    itXEnd--;
    for (int i=0;i<min(n,k);i++) {
        itXEnd = x.end(); itXEnd--;
        for (int j=0;j<min(n,k);j++) {
            int t = max( itXStart->first - itXEnd->first, itXStart->second - itXEnd->second );
            sol.insert(t);
            itXEnd--;
        }
        itXStart++;
    }
    
    auto itYStart = y.begin();
    auto itYEnd = y.end();
    itYEnd--;
    for (int i=0;i<min(n,k);i++) {
        itYEnd = y.end(); itYEnd--;
        for (int j=0;j<min(n,k);j++) {
            int t = max( abs(itYStart->first - itYEnd->first), abs(itYStart->second - itYEnd->second) );
            sol.insert(t);
            itYEnd--;
        }
        itYStart++;
    }
    
    for (int a : sol) {
        cout << a << " ";
    }
    cout << endl;
    
    auto ret = sol.end();
    ret--; ret--;
    cout << *ret << endl;
}
