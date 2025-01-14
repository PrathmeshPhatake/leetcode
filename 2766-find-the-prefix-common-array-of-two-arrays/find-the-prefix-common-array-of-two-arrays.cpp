class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        set<int>st;   
        int n=A.size();
        if(n==1)return {1};
        // st.insert(A[0]);
        // st.insert(B[0]);
        vector<int>ans(n+1,0);
        for(int i=0;i<n;i++)
        {
            int count=0;
            if(st.find(A[i])!=st.end())
            {
                count++;
            }
                st.insert(A[i]);
            if(st.find(B[i])!=st.end())
            {
                count++;
            }
            st.insert(B[i]);
            ans[i+1]+=ans[i]+count;  
        }
        ans.erase(ans.begin());
        return ans;
    }
};