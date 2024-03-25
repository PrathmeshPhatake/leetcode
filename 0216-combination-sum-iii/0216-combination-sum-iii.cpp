class Solution {
    private:
    void printf(vector<vector<int>>&ans,vector<int>&temp,int k,int n, int index,int sum)
    {
        //BASE CASE
        if(temp.size()>k || sum>n)
        {
            return ;
        }
        if(temp.size()==k && sum==n)
        {
            ans.push_back(temp);
            return ;
        }
        for( int i=index;i<=9;i++)
        {
            temp.push_back(i);
            sum=sum+i;
            printf(ans,temp,k,n,i+1,sum);
            sum-=i;
            temp.pop_back();
            // printf(ans,temp,k,n,i+1,sum);

        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
      int sum=0;
      int index=1;
      vector<vector<int>>ans;
      vector<int>temp;
      printf(ans,temp,k,n,index,sum);
      return ans;  
    }
};