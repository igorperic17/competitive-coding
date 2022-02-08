////
////  main.cpp
////  hackerrank-intermediate-cert
////
////  Created by Igor Peric on 10/1/21.
////
//
//#include <iostream>
//#include <vector>
//#include <map>
//#include <queue>
//#include <set>
//#include <fstream>
//
//using namespace std;
//
//string ltrim(const string &);
//string rtrim(const string &);
//
//
///*
// * Complete the 'maxElement' function below.
// *
// * The function is expected to return an INTEGER.
// * The function accepts following parameters:
// *  1. INTEGER n
// *  2. INTEGER maxSum
// *  3. INTEGER k
// */
//
///*
// 
// 1 - 1
// 2 - 1, min(1,
// 3 - 1, 2, 2
// 4 - 1, 2, 2, 2
// ...
// w = 1 + (w - 1) * 2 < r
// 
// 
// n - 1
// 
// */
//
//int maxElement(int n, int maxSum, int k) {
//    int r = maxSum - n;
//    int w = 0;
//    while (true) {
//        w++;
//        cout << "trying W: " << w << " with current R: " << r << endl;
//        int left = k - max(0, k - w + 1);
//        int right = min(n - k - 1, w - 1);
//        cout << "L: " << left << " R: " << right << endl;
//        if (1 + left + right <= r) {
//            cout << "good..." << endl;
//            r -= 1 + left + right <= r;
//        } else { w--; break; }
//    }
//    return w + 1;
//}
//
//int main()
//{
////    ofstream fout(getenv("OUTPUT_PATH"));
//
//    string n_temp;
//    ifstream fin("in.txt");
//    getline(fin, n_temp);
//
//    int n = stoi(ltrim(rtrim(n_temp)));
//
//    string maxSum_temp;
//    getline(fin, maxSum_temp);
//
//    int maxSum = stoi(ltrim(rtrim(maxSum_temp)));
//
//    string k_temp;
//    getline(fin, k_temp);
//
//    int k = stoi(ltrim(rtrim(k_temp)));
//
//    int result = maxElement(n, maxSum, k);
//
//    cout << result << "\n";
//
//    return 0;
//}
//
//string ltrim(const string &str) {
//    string s(str);
//
//    s.erase(
//        s.begin(),
//        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
//    );
//
//    return s;
//}
//
//string rtrim(const string &str) {
//    string s(str);
//
//    s.erase(
//        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
//        s.end()
//    );
//
//    return s;
//}
