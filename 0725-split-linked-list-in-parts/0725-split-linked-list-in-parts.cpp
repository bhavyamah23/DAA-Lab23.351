class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans(k, NULL);

        // Step 1: Count total nodes
        int n = 0;
        ListNode* temp = head;
        while (temp) {
            n++;
            temp = temp->next;
        }

        // Step 2: Calculate base size and extra nodes
        int base = n / k;
        int extra = n % k;

        temp = head;

        // Step 3: Split the list
        for (int i = 0; i < k; i++) {
            if (!temp) {
                ans[i] = NULL;
                continue;
            }

            ans[i] = temp;

            int size = base + (extra > 0 ? 1 : 0);
            if (extra > 0) extra--;

            // Move to the last node of current part
            for (int j = 1; j < size; j++) {
                temp = temp->next;
            }

            // Cut the list
            ListNode* nextPart = temp->next;
            temp->next = NULL;
            temp = nextPart;
        }

        return ans;
    }
};