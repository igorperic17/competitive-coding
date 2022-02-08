//
//  main.cpp
//  hackerrank-intermediate-cert
//
//  Created by Igor Peric on 10/1/21.
//

#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <fstream>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);


/*
 * Complete the 'maxSubarrayValue' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

long maxSubarrayValue(vector<int> arr) {

    const long long INF = 10e9;
    long n = arr.size();
//    vector<vector<long long>> dp(n, vector<long long>(2, 0));
    vector<long long> s(n + 1, 0);
    vector<long long> mx(n + 1, -INF);
    vector<long long> mn(n + 1, INF);
    
    s[1] = arr[0]; mx[1] = s[1]; mn[1] = s[1];
    s[2] = arr[1]; mx[2] = s[2]; mn[2] = s[2];
    for (int i=3;i<=n;i++) {
        s[i] = s[i-2] + arr[i-1];
        mx[i] = max(mx[i-2], s[i]);
        mn[i] = min(mn[i-2], s[i]);
    }
    
    bool evRange;
    long long es, ee, os, oe, even, odd, r;
    long long m = 0;
    for (int i=1;i<=n;i++) {
        for (int j=i;j>0;j--) {
            evRange = ((j-i) % 2) == 0;
            es = max(j + evRange - 2, i);
            ee = min(i - !evRange, j);
            os = max(j + !evRange - 2, i);
            oe = min(i - evRange, j);
            even = s[ee] - s[es];
            odd = s[oe] - s[os];
            r = (even - odd) * (even - odd);
//            for (int k=0;k<=n;k++) cout << s[k] << " ";
//            cout << endl;
//            cout << "i,j: " << i << "," << j << " even,odd: " << even << "," << odd << endl;
//            cout << "r: " << r << endl << endl;
            m = max(m, r);
        }
    }
    
    return m;
}

int main()
{
//    ofstream fout(getenv("OUTPUT_PATH"));
    ifstream fin("in.txt");

    string arr_count_temp;
    getline(fin, arr_count_temp);

    int arr_count = stoi(ltrim(rtrim(arr_count_temp)));

    vector<int> arr(arr_count);

    for (int i = 0; i < arr_count; i++) {
        string arr_item_temp;
        getline(fin, arr_item_temp);

        int arr_item = stoi(ltrim(rtrim(arr_item_temp)));

        arr[i] = arr_item;
    }

    long result = maxSubarrayValue(arr);

    cout << result << "\n";

//    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
