class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n=blocks.size();
        int white=0;
        int mini=INT_MAX;
        for(int i=0;i<k;i++)
        {
            if(blocks[i]=='W')
            {
                white++;
            }
        }
        mini=white;
        for(int i=k;i<n;i++)
        {
            if(blocks[i]=='W')
            {
                white++;
            }
            if(blocks[i-k]=='W')
            {
                white--;
            }
            mini=min(mini,white);
        }
        return mini;
    }
};