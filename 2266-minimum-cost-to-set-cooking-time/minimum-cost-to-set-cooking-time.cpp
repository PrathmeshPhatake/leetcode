class Solution {
public:
    int minCostSetTime(int startAt, int moveCost, int pushCost, int targetSeconds) {
        
        int mm1=targetSeconds;
        int ss1=0;
        mm1=mm1/60;
        ss1=targetSeconds%60;
        
        int mm2=-1,ss2=-1;
        
        if(ss1<=39){
            mm2=mm1-1;
            ss2=ss1+60;
        }

//		cout<<mm2<<" "<<ss2<<endl;

		
        
        int sum1=INT_MAX;
        int sum2=INT_MAX;

        if(mm1<=99){
            string s1="";
            if(ss1<10){
                s1=to_string(mm1)+'0'+to_string(ss1);
            }
            else{
                s1=to_string(mm1)+to_string(ss1);
            }

            string t1="";
            int flag=1;
            for(int i=0;i<s1.length();i++){
                if(flag==0){
                    t1=t1+s1[i];
                }
                if(flag==1 && s1[i]!='0'){
                    flag=0;
                    t1=t1+s1[i];
                }
            }
            
            
    //		cout<<t1<<endl;
            

            sum1=0;
            if(int(t1[0]-48)==startAt){
                sum1=sum1+pushCost;
            }
            else{
                sum1=sum1+pushCost+moveCost;
            }
            for(int i=1;i<t1.length();i++){
                if(t1[i]==t1[i-1]){
                    sum1=sum1+pushCost;
                }
                else{
                    sum1=sum1+pushCost+moveCost;
                }
            }
        }


        if(mm2!=-1){
            sum2=0;
            string s2=to_string(mm2)+to_string(ss2);
			string t2="";
			int flag=1;
			for(int i=0;i<s2.length();i++){
				if(flag==0){
					t2=t2+s2[i];
				}
				if(flag==1 && s2[i]!='0'){
					flag=0;
					t2=t2+s2[i];
				}
			}
//			cout<<t2<<endl;
            if(int(t2[0]-48)==startAt){
                sum2=sum2+pushCost;
            }
			else{
				sum2=sum2+pushCost+moveCost;
			}
            for(int i=1;i<t2.length();i++){
                if(t2[i]==t2[i-1]){
                    sum2=sum2+pushCost;
                }
                else{
                    sum2=sum2+pushCost+moveCost;
                }
            }
            
        }

        cout<<sum1<<" "<<sum2;

        return min(sum1,sum2);
        
    }
};