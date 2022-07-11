// You are given the heads of two sorted linked lists list1 and list2.
// Merge the two lists in a one sorted list. The list should be made by splicing together the nodes of the first two lists.
// Return the head of the merged linked list.

// Input: list1 = [1,2,4], list2 = [1,3,4]
// Output: [1,1,2,3,4,4]

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
  //if any one of the list is empty return other list
  if(!l1) return l2; 
  if(!l2) return l1;
  //make dummy node
  ListNode dummy;
  ListNode *tail=&dummy;
  //while both lists arent empty
  while(l1 && l2){
      if(l1->val<l2->val){
          tail->next=l1;
          l1=l1->next;
      }
      else{
          tail->next=l2;
          l2=l2->next;
      }
      tail=tail->next;
  }
  //insert the non empty list in tail->next
  tail->next=l1?l1:l2;
  return dummy.next;
}  
