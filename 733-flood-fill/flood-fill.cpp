class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int m=image[0].size();
        int prvcolor=image[sr][sc];
        if(prvcolor==color) return image;

        image[sr][sc]=color;
        queue<pair<int,int>>q;
        q.push({sr,sc});

        while(!q.empty())
        {
            auto [r,c]=q.front();
            q.pop();
            int row[]={-1,0,1,0};
            int col[]={0,1,0,-1};
            
            for(int i=0;i<4;i++)
            {
                int nr=r+row[i];
                int nc=c+col[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m && image[nr][nc]==prvcolor)
                {
                    image[nr][nc]=color;
                    q.push({nr,nc});
                }
            }
        }
        return image;
    }
};