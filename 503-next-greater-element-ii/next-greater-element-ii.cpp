class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n,-1);
        stack<int>st;
        for(int i=n*2-1;i>=0 ;i--)
        {
            int id=i%n;
            while(!st.empty() && st.top()<=nums[id])
            {
                st.pop();
            }
           if(!st.empty())
           {
             ans[id]=st.top();
            }
            st.push(nums[id]);
           
        }
        return ans;
    }
};