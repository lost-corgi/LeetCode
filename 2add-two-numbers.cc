class Solution {
public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* res = NULL, **cur=&res;
    int sum=0;
    while (l1||l2) {
      if (l1) {
        sum += l1->val;
        l1 = l1->next;
      }
      if (l2) {
        sum += l2->val;
        l2 = l2->next;
      }
      *cur = new ListNode(sum%10);
      sum /= 10;
      cur = &((*cur)->next);
    }
    if (sum)
      *cur = new ListNode(sum%10);
    return res;
  }
};
