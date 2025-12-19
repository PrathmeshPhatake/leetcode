class Solution {
    public void moveZeroes(int[] nums) {
        int n = nums.length;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                int j = i + 1;
                while (j<n && nums[j] == 0 ) {
                    j++;
                }
                while(j>i && j<n)
                {
                    int temp=nums[j-1];
                    nums[j-1]=nums[j];
                    nums[j]=temp;
                    j--;
                }
            }
        }
    }
}