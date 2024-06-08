#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    void find(string digits,vector<string>& v,vector<string>& res,string s,int k){
        if(k>=digits.size()){
            res.push_back(s);
            return;
        }
        int a = digits[k] - '0';
        for(int i=0;i<v[a].size();i++){
            s+=v[a][i];
            find(digits, v, res, s, k+1);
            s.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if(digits.size() == 0) return res;

        vector<string> v(10); // Initialize vector with size 10
        v[2] = "abc";
        v[3] = "def";
        v[4] = "ghi";
        v[5] = "jkl";
        v[6] = "mno";
        v[7] = "pqrs";
        v[8] = "tuv";
        v[9] = "wxyz";

        int k = 0;
        string s = "";
        find(digits, v, res, s, k);
        return res;
    }
};

int main() {
    Solution solution;
    vector<string> res1 = solution.letterCombinations("23");
    cout << "Output for digits \"23\":" << endl;
    for (int i = 0; i < res1.size(); ++i) {
        cout << res1[i] << " ";
    }
    cout << endl;

    vector<string> res2 = solution.letterCombinations("");
    cout << "Output for empty digits:" << endl;
    for (int i = 0; i < res2.size(); ++i) {
        cout << res2[i] << " ";
    }
    cout << endl;

    vector<string> res3 = solution.letterCombinations("2");
    cout << "Output for digits \"2\":" << endl;
    for (int i = 0; i < res3.size(); ++i) {
        cout << res3[i] << " ";
    }
    cout << endl;

    return 0;
}
