//
//  main.cpp
//  codechef-january-cookoff
//
//  Created by Igor Peric on 24/1/21.
//

#include <iostream>
#include <vector>

using namespace std;

int main(int argc, const char * argv[]) {
    
    int t, i, j;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        vector<bool> p(n + 1, true);
        for (i=2;i<n/2;i+=2) {
            for (j=i+1;j<n/2;j++) {
                int k = i * j;
                if (k <= n) p[k] = false;
            }
        }
        
        for (i=0;i<n;i++) cout << p[i] << " ";
        cout << endl;
        
    }
    
}
