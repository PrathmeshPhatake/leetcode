class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        int n = original;

        while (true) {

            auto it = find(nums.begin(), nums.end(), original);
           if(it==nums.end())
           {
            break;
           }
           original*=2;
        }
        return original;
    }
};