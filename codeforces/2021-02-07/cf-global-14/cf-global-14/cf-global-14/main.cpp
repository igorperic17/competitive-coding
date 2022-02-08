//
//  main.cpp
//  cf-global-14
//
//  Created by Igor Peric on 2/5/21.
//

#include <iostream>
#include <vector>

using namespace std;

int main(int argc, const char * argv[]) {
    
    int n, t;
    cin >> t;
    while (t--) {
        
        cin >> n;
        if ((n & (n-1))> 0) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
    
    return 0;
}
