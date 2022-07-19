//Given the head of a linked list, return the list after sorting it in ascending order.
// USE MERGE SORT FOR LINKED LIST SORTING

ListNode* merge(ListNode* l1, ListNode* l2){
    ListNode* dummy = new ListNode();
    auto curr = dummy;

    while(l1 && l2){
        if(l1->val < l2->val) curr->next = l1, l1=l1->next;
        else curr->next = l2, l2 = l2->next;
        curr = curr->next;
    }
    
    //concatinate the remaining list
    if(l1) curr->next = l1;
    else curr->next = l2;
    
    return dummy->next; //return sorted list
}

ListNode* getMid(ListNode* head){
    auto slow = head, fast=head;
    ListNode* prev;
    //find mid pt
    while(fast->next && fast->next->next)
        slow = slow->next, fast = fast->next->next;
    //break the list in 2, then return mid
    auto mid = slow->next;
    slow->next = nullptr;
    return mid; 
}

ListNode* sortList(ListNode* head) {
    if(!head || !head->next) return head;
    auto mid = getMid(head);    //get mid pt
    auto l1 = sortList(head);   //sort 1st half
    auto l2 = sortList(mid);    //sort 2nd half
    return merge(l1,l2);        //merge both halves
}
