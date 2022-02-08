//
//  main.cpp
//  codechef-jan-lunchtime
//
//  Created by Igor Peric on 30/1/21.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main3(int argc, const char * argv[]) {
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> s(n+1, 0);
        string a;
        cin >> a;
        for (int i=0;i<n;i++) s[i+1] = s[i] + (a[i] == '1');
        
        int sol = n;
        for (int i=0;i<=n;i++) {
            int L = s[i];
            int R = n - i - (s[n] - s[i]);
//            cout << "i: " << i << " L: " << L << " R: " << R << endl;
            sol = min(sol, L + R);
        }
        cout << sol << endl;
    }
    return 0;
}
