class Solution {
public:
    string removeStars(string s) {
        stack<char> stk;

        for(char ch : s) {
            if(ch == '*') {
                if(!stk.empty()) stk.pop(); }
                else {
                    stk.push(ch);
                }

            }
            string result;
            while(!stk.empty()) {
                result+= stk.top();
                stk.pop();
            } 
        reverse(result.begin(), result.end());
        return result;

        }
    };

   