class Solution {
public:
    bool isCircularSentence(string sentence) {
        istringstream stream(sentence);
        string word;
        vector<string> words;

        while (stream >> word) {
            words.push_back(word);
        }

        // Single word check
        if (words.size() == 1) {
            return words[0].front() == words[0].back();
        }

        // Check each word for circular condition
        for (int i = 0; i < words.size(); ++i) {
            if (words[i].back() != words[(i + 1) % words.size()].front()) {
                return false;
            }
        }

        return true;
    }
};
