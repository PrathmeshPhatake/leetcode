class Solution {
public:
    int splitNum(int num) {
        string str=to_string(num);
        sort(str.begin(),str.end());
        int left=0;
        int right =str.size()-1;
        int num1=0;
        int num2=0;
        while(left<=right)
        {
            if(left<=right)
            {
                num1=num1*10 + (str[left]-'0');
                left++;
            }
            if(left<=right)
            {
                num2=num2*10+(str[left]-'0');
                left++;
            }

            
        }
        return num1+num2;
    }
};