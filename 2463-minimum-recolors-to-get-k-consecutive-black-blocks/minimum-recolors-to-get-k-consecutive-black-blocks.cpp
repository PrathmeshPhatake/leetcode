class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int black=0;
        int white=0;
        int n=blocks.size();
        int mini=INT_MAX;
        for(int i=0;i<k && i<n;i++)
        {
            if(blocks[i]=='W')
            {
                white++;
            }
            

        }
        mini=min(mini,white);
        for(int j=k;j<n;j++){
            if(blocks[j]=='W')
            {
                white++;
            }
            if(blocks[j-k]=='W')
            {
                white--;
            }
            mini=min(mini,white);
           
        }
        return mini;
        
    }
};