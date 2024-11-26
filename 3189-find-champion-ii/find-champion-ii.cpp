class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
             vector<int>arr(n,0);
             for(auto it:edges)
             {
                int u=it[0];
                int v=it[1];
                arr[v]++;
             }   
             int ans=-1;
             int count=0;
             for(int i=0;i<n;i++)
             {
                if(arr[i]==0)
                {
                    count++;
                    ans=i;
                }
             }
             return (count==1)?ans:-1;
    }
};