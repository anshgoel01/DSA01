class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* dummyNode = new ListNode(-1);
        ListNode* curr = dummyNode;
        
        int carry = 0;

        while (l1 != NULL || l2 != NULL) {
            
            int sum = carry;

            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }

            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }

            carry = sum / 10;

            ListNode* newNode = new ListNode(sum % 10);

            curr->next = newNode;
            curr = curr->next;
        }

        if (carry) {
            curr->next = new ListNode(carry);
        }

        return dummyNode->next;
    }
};