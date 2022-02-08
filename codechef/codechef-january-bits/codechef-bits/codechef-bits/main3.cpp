//
//  main.cpp
//  codechef-bits
//
//  Created by Igor Peric on 31/1/21.
//

#include <iostream>
#include <vector>

using namespace std;

int main(int argc, const char * argv[]) {
    
    unsigned long long MAXN = 10e8 + 1;
    vector<unsigned long long> p(MAXN, 0);
    
    unsigned long long x = 1;
    p[1] = 1;
    for (int i=2;i<MAXN;i++) {
        x = x ^ i;
        p[i] = x;
    }
    cout << "DONE." << endl;
    
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        cout << p[n] << endl;
    }
}
