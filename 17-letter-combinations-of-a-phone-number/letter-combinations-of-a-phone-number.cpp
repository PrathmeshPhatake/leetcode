class Solution {
public:
void substirng(vector<string>&ans,string temp,int i,string digits,string mapping[])
{
    if(i>=digits.size())
    {
        ans.push_back(temp);
        return; 
    }
    int num=digits[i]-'0';
    string value=mapping[num];
    
    // create a stiring of all value
    for(int j=0;j<value.size();j++)
    {
        temp+=value[j];
        substirng(ans,temp,i+1,digits,mapping);
        temp.pop_back();

    }
    

}
    vector<string> letterCombinations(string digits) {
        string mapping[10] = {"","","abc","def","ghi","jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string>ans;
        string temp="";
       if(digits.size()==0)return ans;
       substirng(ans,temp,0,digits,mapping);
       return ans;
       
    }
};