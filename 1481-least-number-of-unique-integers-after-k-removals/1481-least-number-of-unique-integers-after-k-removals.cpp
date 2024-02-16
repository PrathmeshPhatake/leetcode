class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> frequency;
        for (int num : arr) {
            frequency[num]++;
        }
        
        vector<int> freqCount;
        for (auto& pair : frequency) {
            freqCount.push_back(pair.second);
        }
        
        sort(freqCount.begin(), freqCount.end());
        
        int uniqueCount = freqCount.size();
        for (int freq : freqCount) {
            if (k >= freq) {
                k -= freq;
                uniqueCount--;
            } else {
                break;
            }
        }
        
        return uniqueCount;
    }
};