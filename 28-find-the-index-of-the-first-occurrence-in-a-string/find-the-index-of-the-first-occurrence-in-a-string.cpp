class Solution {
public:
    int strStr(string haystack, string needle) {
        int n=haystack.size();
        int m=needle.size();
        if(n<m)return -1;
        if(haystack==needle) return 0;
        int index=INT_MAX;
        for(int i=0;i<n;i++)
        {
            for(int j=i, k=0;j<n&&k<m;j++,k++)
            {
               
                if(haystack[j]!=needle[k])
                {
                   
                    break;
                }
                if(k==m-1)
                {
                    return i;
                }
            }
        }
        return -1;
    }
};