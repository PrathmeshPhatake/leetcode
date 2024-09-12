class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int n=words.size();
        int count=0;
        
            
            set<char>set1(allowed.begin(),allowed.end());
            for(int j=0;j<n;j++)
            {
                string str1=words[j];
                for(int i=0;i<str1.size();i++)
                {
                    if(set1.find(str1[i])==set1.end())
                    {
                        break;
                    }
                    if(set1.find(str1[i])!=set1.end() && i==str1.size()-1)
                    {
                        count++;
                    }
                }
                
            }
        
        return count;
    }
};