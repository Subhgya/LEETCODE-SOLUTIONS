
class Solution {
public:

    struct Compare {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {

        priority_queue<ListNode*, vector<ListNode*>, Compare> pq;

        // Insert first node of each list
        for (auto node : lists) {
            if (node != nullptr) {
                pq.push(node);
            }
        }

        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (!pq.empty()) {

            ListNode* smallest = pq.top();
            pq.pop();

            tail->next = smallest;
            tail = tail->next;

            if (smallest->next != nullptr) {
                pq.push(smallest->next);
            }
        }

        tail->next = nullptr;

        return dummy.next;
    }
};
