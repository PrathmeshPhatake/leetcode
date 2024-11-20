class Solution {
    bool greaterThanEqualK(unordered_map<char , int>& freq,const int& k) //O(1)
    {
        for(auto& [ch , f] : freq)
        {
            if(f < k)
                return false;
        }
        return true;
    }
    bool possible(int mid , const string& s ,const int& k)
    {
        int n = s.size();
        int i = 0 , j = n - 1;
        unordered_map<char , int>freq;
        freq['a'] = 0 , freq['b'] = 0 , freq['c'] = 0;
        
        while(i < mid)
        {
            freq[s[i]]++;
            i++;
        }
        bool check = greaterThanEqualK(freq,k);
        if(check) return true;
        i--;
        while(i >= 0)
        {
            freq[s[i]]--;
            freq[s[j]]++;
            i-- , j--;
            bool check = greaterThanEqualK(freq,k);
            if(check) return true;
        }
        return false;
    }
public:
    int takeCharacters(string s, int k) {
        if(k == 0)
            return 0;
        int sLen = s.size();
        int low = 1 , high = sLen;
        int ans = -1;
        while(low <= high)
        {
            int mid = low + (high - low) / 2;
            
            bool check = possible(mid , s , k );
            if(check)
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return ans;
    }
};