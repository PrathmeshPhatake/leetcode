class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int Acount = 0;
        int Bcount = 0;
        int Ccount = 0;
        int left = 0;
        int count = 0;
        
        for (int right = 0; right < n; right++) {
            if (s[right] == 'a') {
                Acount++;
            } else if (s[right] == 'b') {
                Bcount++;
            } else if (s[right] == 'c') {
                Ccount++;
            }
            
            while (Acount >= 1 && Bcount >= 1 && Ccount >= 1) {
                count += n - right;  // All substrings from left to right are valid
                
                if (s[left] == 'a') {
                    Acount--;
                } else if (s[left] == 'b') {
                    Bcount--;
                } else if (s[left] == 'c') {
                    Ccount--;
                }
                left++;
            }
        }
        
        return count;
    }
};
