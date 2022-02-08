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

using namespace std;

int main(int argc, const char * argv[]) {
    
    int t;
    cin >> t;
    while (t--) {
        
        string a, b;
        int n;
        cin >> n;
        cin >> a >> b;
        
        string d(a);
        
//        int c = 0;
        for (int i=0;i<n;i++) {
            if (b[i] == '0') {
                continue;
            } else {
                
                if (a[i] == '0') {
                    d[i] = '2';
                    continue;
                } else {
                    
                    if (i > 0 && d[i-1] == '1') {
                        d[i-1] = '2';
                        continue;
                    }
                    
                    if (i < n-1 && d[i+1] == '1') {
                        d[i+1] = '2';
                        continue;
                    }
                }
            }
        }
        
//        cout << d << endl;
        
        int c = 0;
        for (int i=0;i<n;i++) c += (d[i] == '2');
        cout << c << endl;
        
    }
}
