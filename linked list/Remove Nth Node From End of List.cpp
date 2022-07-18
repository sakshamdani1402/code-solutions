/* Given the head of a linked list, remove the nth node from the end of the list and return its head.

Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]

Input: head = [1], n = 1
Output: []

Input: head = [1,2], n = 1
Output: [1]  */

//METHOD 1
ListNode* removeNthFromEnd(ListNode* head, int n) {
    int len=0;
    auto curr = head;
    while(curr) curr = curr->next, len++; //find len of linkedlist

    len-=n; //find nth idx from starting
    curr=head;
    
    if(len==0) return head->next;   //if the node to be deleted is the head node, simply move head ahead and return

    for(int i=1; i<len; i++) curr=curr->next; //else move curr just before the node to be deleted 

    curr->next = curr->next->next;  //skip the next node 

    return head;
}

//METHOD 2 - 2 POINTERS
/* move fast pointer to the n times, then move fast and slow both till fast reaches the last node
this way slow would reach the node just before the node to be deleted, then simply skip slow->next */

ListNode* removeNthFromEnd(ListNode* head, int n) {
    auto slow = head, fast = head;

    for(int i=1; i<=n; i++) fast = fast->next;  //move from 1st to nth position
    if(!fast) return head->next;  //if we reach end then the node to be deleted is the head node, so simply return head->next

    while(fast->next) fast = fast->next, slow = slow->next; //else move fast till the last node
    slow->next = slow->next->next;  //skip the node to be deleted
  
    return head;
}
