//
//  main.cpp
//  cf-700
//
//  Created by Igor Peric on 7/2/21.
//

#include <iostream>
#include <string>

using namespace std;

int main(int argc, const char * argv[]) {
    
    int t;
    cin >> t;
    while (t--) {
        
        string s;
        cin >> s;
        
        for (int i=0;i<s.size();i++) {
            if (i % 2 == 0) s[i] = 'a' + (s[i] == 'a');
            else s[i] = 'z' - (s[i] == 'z');
        }
        
        cout << s << endl;
    }
    
}
