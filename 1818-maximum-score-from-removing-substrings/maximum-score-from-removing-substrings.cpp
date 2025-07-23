//TIME :[O(N)]
//SPACE :[O(N)];
class Solution {
public:
    int maximumGain(string s, int x, int y) {
        if(x<y)
        {
            swap(x,y);
            for(auto&it:s)
            {
                if(it=='a') it='b';
                else if(it=='b') it='a';
            }
        }
        stack<char>stq;
        int points=0;
        //remove ab
        for(char c:s)
        {
             if(!stq.empty() &&stq.top()=='a' && c=='b')
             {
                stq.pop();
                points+=x;
             }
             else
             {
                stq.push(c);
             }
        }
        string remaning;
        while(!stq.empty())
        {
            remaning+=stq.top();
            stq.pop();
        }
        reverse(remaning.begin(),remaning.end());
        //remove "ba"
        for(auto c:remaning)
        {
            if(!stq.empty() && stq.top()=='b' &&c=='a')
            {
                stq.pop();
                points+=y;
            }
            else
            {
                stq.push(c);
            }
        }
        return points;
    }
};