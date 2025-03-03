class Solution {
public:
    int trap(vector<int>& height) {
        // we store max element at prefixleft and suffixright element 
        int n=height.size();
        vector<int>prefixmax(n,0);
        vector<int>suffixmax(n,0);
        prefixmax[0]=height[0];
        for(int i=1;i<n;i++)
        {
            prefixmax[i]=max(prefixmax[i-1],height[i]);
        }
        suffixmax[n-1]=height[n-1];
        for(int i=n-2;i>=0;i--)
        {
            suffixmax[i]=max(suffixmax[i+1],height[i]);
        }
        int total=0;
        for(int i=0;i<n;i++)
        {
            total+=min(suffixmax[i],prefixmax[i])-height[i];
        }
        return total;
    }
};