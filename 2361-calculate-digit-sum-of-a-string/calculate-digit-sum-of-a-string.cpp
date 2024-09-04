class Solution {
public:
    string digitSum(string s, int k) {
        while(s.size()>k)
        {
            string str;
            for(int i=0;i<s.size();i+=k)
            {
                int temp=0;
                int j=i;
                while(j<i+k && j<s.size())
                {
                    temp+=s[j]-'0';
                    j++;
                }
                str+=to_string(temp);
            }
            s=str;
            
        }
        return s;
    }
};