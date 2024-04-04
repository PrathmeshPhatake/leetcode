class Solution {
public:
    bool isValid(string s) {
        stack<char> s1;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                s1.push('(');
            } else if (s[i] == ')') {
                if (!s1.empty() && s1.top() == '(') {
                    s1.pop();
                } else {
                    return false; // Mismatched closing bracket
                }
            } else if (s[i] == '{') {
                s1.push('{');
            } else if (s[i] == '}') {
                if (!s1.empty() && s1.top() == '{') {
                    s1.pop();
                } else {
                    return false; // Mismatched closing bracket
                }
            } else if (s[i] == '[') {
                s1.push('[');
            } else if (s[i] == ']') {
                if (!s1.empty() && s1.top() == '[') {
                    s1.pop();
                } else {
                    return false; // Mismatched closing bracket
                }
            }
        }
        //thsi is will check is empty or not 
       return s1.empty();
    }
};