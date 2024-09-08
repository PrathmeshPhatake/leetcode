class Solution {
public:
    string sortSentence(string s) {
         
         string word;
         istringstream stream(s);
       vector<pair<int,string>>words;
       while(stream >> word)
       {
         int len=word.size();
         int position=word[len-1]-'0';
         string str=word.substr(0,len-1);
         words.push_back({position,str});
       }
       sort(words.begin(),words.end(),[](pair<int,string>&a,pair<int,string>&b){
        return a.first<b.first;
       });
    // sort(words.begin(),words.end());
       string ans;
       for(int i=0;i<words.size();i++)
       {
         string st=words[i].second;
         ans+=st;
         if(i!=words.size()-1)
         {
            ans+=" ";
         }
       }
       return ans;
    }
};