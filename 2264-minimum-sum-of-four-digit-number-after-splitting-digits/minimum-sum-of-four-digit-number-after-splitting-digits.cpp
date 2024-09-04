class Solution {
public:
    int minimumSum(int num) {
        string s=to_string(num);
        sort(s.begin(),s.end());
        int i=0;
        int num1=(s[i]-'0')*10+s[3]-'0';
        int num2=(s[i+1]-'0')*10+s[2]-'0';
        return num1+num2;
    }
};