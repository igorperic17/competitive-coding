//
//  main.cpp
//  cf-736
//
//  Created by Igor Peric on 1/8/21.
//

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <set>

using namespace std;

int main(int argc, const char * argv[]) {
    
//    int t;
//    cin >> t;
//    while (t--) {
        
        int n, m, a, b, c = 0;
        cin >> n >> m;
        vector<int> d(n, 0);
        for (int i=0;i<m;i++) {
            cin >> a >> b;
            a--; b--;
            c += (d[min(a,b)]++ == 0);
        }
        int q, k;
        cin >> q;
        while (q--) {
//            cout << "reading q " << endl;
            cin >> k;
            // ADD
            if (k == 1) {
                cin >> a >> b;
                a--; b--;
                c += (d[min(a,b)]++ == 0);
                continue;
            }
            // REMOVE
            if (k == 2) {
                cin >> a >> b;
                a--; b--;
                c -= (--d[min(a,b)] == 0);
                continue;
            }
            // QUERY
            if (k == 3) {
                cout << n - c << endl;
                continue;
            }
            
        }
        
        
//    }
}
