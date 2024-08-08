class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        int r=rStart;
        int c=cStart;
        vector<vector<int>>ans;
        ans.push_back({r,c});
        int total=rows*cols;
        
        int step=1;
        while(ans.size()<total)
        {
            //move left
            for(int i=0;i<step;i++){
                c++;
                if(r>=0 && r<rows && c>=0 && c<cols) ans.push_back({r,c});  
            }
            // move to down 
            for(int i=0;i<step;i++){
                r++;
                if(r>=0 && r<rows && c>=0 && c<cols) ans.push_back({r,c});  
            }
            step++;
            // move to right 
            for(int i=0;i<step;i++){
                c--;
                if(r>=0 && r<rows && c>=0 && c<cols) ans.push_back({r,c});  
            }
            // move to up
            for(int i=0;i<step;i++){
                r--;
                if(r>=0 && r<rows && c>=0 && c<cols) ans.push_back({r,c});  
            }
            step++;
        }
        return ans;
    }
};