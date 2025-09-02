class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int c1 = 0, c2 = 0;
        int e1 = INT_MIN, e2 = INT_MIN;
        int n = nums.size();

        for (int num : nums) {
            if (e1 == num) {
                c1++;
            } else if (e2 == num) {
                c2++;
            } else if (c1 == 0) {
                e1 = num;
                c1 = 1;
            } else if (c2 == 0) {
                e2 = num;
                c2 = 1;
            } else {
                c1--;
                c2--;
            }
        }

        // verify candidates
        c1 = 0;
        c2 = 0;
        for (int num : nums) {
            if (num == e1) c1++;
            else if (num == e2) c2++;
        }

        vector<int> ans;
        int threshold = n / 3;
        if (c1 > threshold) ans.push_back(e1);
        if (c2 > threshold) ans.push_back(e2);

        sort(ans.begin(), ans.end());
        return ans;
    }
};
