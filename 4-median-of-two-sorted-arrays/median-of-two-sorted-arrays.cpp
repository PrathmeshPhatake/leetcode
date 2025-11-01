class Solution {
public:
    vector<int> merge(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        int left = 0;
        int right = 0;
        int n = nums1.size();
        int m = nums2.size();
        while (left < n && right < m) {
            if (nums1[left] < nums2[right]) {
                ans.push_back(nums1[left]);
                left++;
            } else {
                ans.push_back(nums2[right]);
                right++;
            }
        }
        while (left < n) {
            ans.push_back(nums1[left]);
            left++;
        }
        while (right < m) {
            ans.push_back(nums2[right]);
            right++;
        }
        return ans;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans=merge(nums1,nums2);
        int n=ans.size();
        if(n%2!=0) return ans[n/2];
       return (ans[n/2]+ans[(n/2)-1])/2.0;

    }
};