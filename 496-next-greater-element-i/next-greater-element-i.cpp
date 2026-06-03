class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        for(auto it:nums1)
        {
            bool find=false;
            bool greaterfind=false;
            for(int i=0;i<nums2.size();i++)
            {
                if(it==nums2[i])
                {
                    find=true;
                }
                if(find && nums2[i]>it){
                    ans.push_back(nums2[i]);
                    greaterfind=true;
                    break;
                }
            }
                if(!greaterfind)
                {
                    ans.push_back(-1);
                }
        }
        return ans;
    }
};