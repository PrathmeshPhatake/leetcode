class Solution {
public:
    bool isPrefixString(string s, vector<string>& words) {
        string temp = "";  
        
        for (int i = 0; i < words.size(); i++) {
            temp += words[i];  
            
            if (s.substr(0, temp.size()) != temp) {
                return false;  
            }
            
            if (temp == s) {
                return true;
            }
        }
        
        // If all words are used and we never found a match, return false
        return false;
    }
};
