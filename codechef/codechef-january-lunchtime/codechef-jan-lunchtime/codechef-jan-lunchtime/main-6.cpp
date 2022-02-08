//
//  main.cpp
//  codechef-jan-lunchtime
//
//  Created by Igor Peric on 30/1/21.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(int argc, const char * argv[]) {
    
    int t;
    cin >> t;
    while (t--) {
        unsigned long long n, s=0, k;
        cin >> n;
        vector<pair<unsigned long long, unsigned long long>> a;
        for (int i=0;i<n;i++) {
            cin >> k;
            if (i == 0) s = k;
            else a.push_back(make_pair(k, i+1));
        }
        
        sort(a.begin(), a.end());
        
        int i = 0;
        vector<pair<unsigned long long,unsigned long long>> sol;
        while (i < n-1 && a[i].first <= s) {
            sol.push_back(a[i]);
            i++;
            s += a[i].first;
        }
        
        if (i < n-1) cout << -1 << endl;
        else {
            cout << sol.size() << endl;
            for (i=0;i<sol.size();i++)
                cout << sol[i].second << " 1 " << sol[i].first << endl;
        }
    }
    return 0;
}
