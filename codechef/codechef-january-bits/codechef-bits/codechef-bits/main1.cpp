//
//  main.cpp
//  codechef-bits
//
//  Created by Igor Peric on 31/1/21.
//

#include <iostream>
#include <vector>

using namespace std;

int main1(int argc, const char * argv[]) {
    
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        int sol = 0;
        while (n) {
            sol += n & 1;
            n >>= 1;
        }
        if (sol % 2 == 1) cout << "Non-Magical" << endl;
        else cout << "Magical" << endl;
    }
}
