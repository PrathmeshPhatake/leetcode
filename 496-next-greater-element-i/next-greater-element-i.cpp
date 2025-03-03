class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size();
        int n=nums2.size();
        vector<int>ans;
        for(int i=0;i<m;i++)
        {
            int index=find(nums2.begin(),nums2.end(),nums1[i])-nums2.begin();
            int flag=false;
            for(int j=index;j<n;j++)
            {
                if(nums2[j]>nums2[index])
                {
                    ans.push_back(nums2[j]);
                    flag=true;
                    break;
                }
            }
            if(!flag)
            {
                ans.push_back(-1);
            }
            
        }
        return ans;
    }
};