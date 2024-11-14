#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    string decodeString(const string& s) {
        stack<string> st;  // Stack to store strings and numbers as strings
        string current;    // Current string we're building
        string num;        // Current number as a string

        for (char ch : s) {
            if (isdigit(ch)) {
                num += ch;  // Build the number as a string
            } else if (ch == '[') {
                // Push the current number and current string onto the stack
                st.push(current);  
                st.push(num);
                current.clear();
                num.clear();
            } else if (ch == ']') {
                // Convert the accumulated number string to an integer
                int repeat = 0;
                for (char digit : st.top()) {
                    repeat = repeat * 10 + (digit - '0'); // Manual string to integer conversion
                }
                st.pop();  // Remove the number string from the stack

                // Pop the previous string context from the stack
                string prev = st.top(); st.pop();

                // Repeat the current string and append to the previous string
                string temp = current;
                for (int i = 1; i < repeat; i++) {
                    current += temp;
                }

                current = prev + current;  // Append to previous context
            } else {
                current += ch;  // Regular characters, just add to the current string
            }
        }

        return current;
    }
};
