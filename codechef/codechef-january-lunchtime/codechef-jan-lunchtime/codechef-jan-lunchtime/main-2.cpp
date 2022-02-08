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

int main2(int argc, const char * argv[]) {
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a;
        vector<int> p(2,0);
        for (int i=0;i<n;i++) {
            cin >> a;
            p[ a % 2 ]++;
        }
        
        int kk = 0;
        int s = 0;
        for (int i=0;i<n;i++) {
            
            if (kk == 0) { // player 1
                if (p[0]) { p[0]--; }
                else { p[1]--; s=(s+1)%2; }
            } else { // player 2
                if (s == 0) {
                    if (p[0]) { p[0]--; }
                    else { p[1]--; s=(s+1)%2; }
                } else {
                    if (p[1]) { p[1]--; s=(s+1)%2; }
                    else { p[0]--; }
                }
            }
            
            kk = (kk + 1) % 2;
        }
        
        cout << s + 1 << endl;
    }
    return 0;
}
