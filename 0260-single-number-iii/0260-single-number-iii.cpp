class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
    long XOR=0;
    for(auto it:nums)
    
       { XOR^=it;}
    int rightmost=(XOR&(XOR-1)^XOR);  //THIS IS FIXED NUMBER  TO GET

    int b1=0,b2=0; //b1->> 1st bit is 1 and b2->> 1st bit is 0
    
    for(int i=0;i<nums.size();i++)
    {
        if(nums[i]&rightmost)
        {
            b1^=nums[i];
        }
        else
        {
            b2^=nums[i];
        }
    }
    return {b1,b2};
    
    }
};