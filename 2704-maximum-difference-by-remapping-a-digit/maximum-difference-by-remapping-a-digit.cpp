class Solution {
public:
    int minMaxDifference(int num) {
        string nums=to_string(num);
        string mi="";
        string ma="";
        char ele=' ';
        int n=nums.size();
        // find max element except 9 
        for(int i=0;i<n;i++)
        {
            if(nums[i]!='9')
            {
                ele=nums[i];
                break;
            }
        }
        for(int i=0;i<n;i++)
        {
            if(nums[i]==ele)
            {
                ma+='9';

            }else
            {
                ma+=nums[i];
            }
        }
        for(int i=0;i<n;i++)
        {
            if(nums[i]==nums[0])
            {
                mi+='0';
            }
            else
            {
                mi+=nums[i];
            }
        }
        return stoi(ma)-stoi(mi);
    }
};