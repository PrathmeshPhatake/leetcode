class Solution {
public:
vector<string>splitWords(string& s1)
{
    vector<string>ans;
    istringstream stream(s1);
    string str;
    while(stream>>str)
    {
        ans.push_back(str);
    }
    return ans;
}
    bool areSentencesSimilar(string sentence1, string sentence2) {
  
        // Split both sentences into words
        vector<string> words1 = splitWords(sentence1);
        vector<string> words2 = splitWords(sentence2);
        
        // Ensure words1 is the longer sentence
        if (words1.size() < words2.size()) swap(words1, words2);
        
        int start = 0, end = 0;
        int n1 = words1.size(), n2 = words2.size();
        
        // Compare from the start
        while (start < n2 && words1[start] == words2[start]) start++;
        
        // Compare from the end
        while (end < n2 && words1[n1 - end - 1] == words2[n2 - end - 1]) end++;
        
        // Check if the remaining unmatched part is in the middle
        return start + end >= n2;
    }
};