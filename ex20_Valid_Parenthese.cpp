#include <iostream>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char, char> bracketPairs;
        bracketPairs[')'] = '(';
        bracketPairs['}'] = '{';
        bracketPairs[']'] = '[';

        for (char ch : s) {

            if (bracketPairs.find(ch) != bracketPairs.end()) {

                if (!st.empty() && st.top() == bracketPairs[ch]) {
                    st.pop();
                } else {
                    return false;
                }
            } else {

                st.push(ch);
            }
        }


        return st.empty();
    }
};

int main() {
    Solution solution;


    string s1 = "()";
    cout << "Input: \"" << s1 << "\" Output: " << solution.isValid(s1) << endl;


    string s2 = "()[]{}";
    cout << "Input: \"" << s2 << "\" Output: " << solution.isValid(s2) << endl;


    string s3 = "(]";
    cout << "Input: \"" << s3 << "\" Output: " << solution.isValid(s3) << endl;

    return 0;
}
