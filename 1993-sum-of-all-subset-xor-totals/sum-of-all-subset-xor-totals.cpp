class Solution {
public:
void fibonacii(vector<int>nums,int sum,int& maxi,int i){
    int n=nums.size();
    if(i==n)
    {
        maxi+=sum;
        return;
    }
    // take
    fibonacii(nums,sum^nums[i],maxi,i+1);
    // non-take
    fibonacii(nums,sum,maxi,i+1);
}
    int subsetXORSum(vector<int>& nums) {
        int maxi=0;
         fibonacii(nums,0,maxi,0);
         return maxi;
    }
};