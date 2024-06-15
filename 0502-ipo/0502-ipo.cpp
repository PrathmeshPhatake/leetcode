class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<pair<int, int>> projects(n);
        
        for (int i = 0; i < n; ++i) {
            projects[i] = {capital[i], profits[i]};
        }
        
        // Sort projects by their capital requirements
        sort(projects.begin(), projects.end());
        
        priority_queue<int> maxHeap;
        int projectIndex = 0;
        
        for (int i = 0; i < k; ++i) {
            // Push all projects we can afford with the current capital into the max heap
            while (projectIndex < n && projects[projectIndex].first <= w) {
                maxHeap.push(projects[projectIndex].second);
                projectIndex++;
            }
            
            // If there are no projects we can afford, break the loop
            if (maxHeap.empty()) {
                break;
            }
            
            // Select the project with the maximum profit
            w += maxHeap.top();
            maxHeap.pop();
        }
        
        return w;
    }
};