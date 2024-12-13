class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (auto it : nums) {
            if (it != 0) {
                pq.push(it);
            }
        }
        int count = 0;
        while (!pq.empty()) {
            int value = pq.top();
            pq.pop();
            count++;
            priority_queue<int, vector<int>, greater<int>> temp;
            while (!pq.empty()) {
                int temp_value = pq.top();
                pq.pop();
                int cons = temp_value-value;
                if (cons > 0) {
                    temp.push(cons);
                }
            }
            pq = move(temp);
        }
        return count;
    }
};