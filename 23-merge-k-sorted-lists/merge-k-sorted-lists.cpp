// Definition for singly-linked list.
// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };

// Custom comparator for ListNode*
struct CompareListNode {
    bool operator()(ListNode* const& lhs, ListNode* const& rhs) {
        return lhs->val > rhs->val; // Min-heap: smallest element has highest priority
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // Priority queue with custom comparator
        priority_queue<ListNode*, vector<ListNode*>, CompareListNode> pq;
        
        // Push the head of each list into the priority queue
        for (auto list : lists) {
            if (list != nullptr) {
                pq.push(list);
            }
        }

        // Dummy node to start the merged list
        ListNode dummy;
        ListNode* tail = &dummy;

        // While there are elements in the priority queue
        while (!pq.empty()) {
            // Get the smallest element
            ListNode* node = pq.top();
            pq.pop();
            
            // Add it to the merged list
            tail->next = node;
            tail = node;

            // Push the next element from the same list into the priority queue
            if (node->next != nullptr) {
                pq.push(node->next);
            }
        }

        // Return the merged list
        return dummy.next;
    }
};