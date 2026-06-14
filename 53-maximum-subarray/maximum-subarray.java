class Solution {
    public int maxSubArray(int[] nums) {
        int n=nums.length;
        int maxi=Integer.MIN_VALUE;
        int sum=0;
        for(int ch:nums){
            sum+=ch;
            maxi=Math.max(maxi,sum);
            if(sum<0){
                sum=0;
            }
        }
        return maxi;
    }
}