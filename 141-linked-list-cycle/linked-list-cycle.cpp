/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> visited;

        ListNode* i = head;

        while(i != nullptr){
            if(visited.count(i)){
                return true;
            }
            visited.insert(i);
            i = i->next;
        }
        return false;
    }
};