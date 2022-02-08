//
//  main.cpp
//  codechef-jan-lunchtime
//
//  Created by Igor Peric on 30/1/21.
//

#include <iostream>
#include <vector>

using namespace std;

int main1(int argc, const char * argv[]) {
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        vector<int> p(2,0);
        for (int i=0;i<n;i++) {
            cin >> a[i];
            p[ a[i] % 2 ]++;
        }
        cout << n - max(p[0], p[1]) << endl;
    }
    return 0;
}
