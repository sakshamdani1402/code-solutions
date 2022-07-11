// Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.
// There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. 
// return -1 if there is no cycle. 

ListNode *detectCycle(ListNode *head) {
  ListNode *slow=head, *fast=head;

  //we dont check for slow cuz fast moves with 2x speed
  //if there is no cycle fast will equal null anyway
  //we also check fast->next cuz fast jumps 2 spaces
  //so we need to ensure its next isnt null
  //if there is a cycle they wont equal null ever
  while(fast && fast->next){
      slow=slow->next;
      fast=fast->next->next;
      if(slow==fast) break;
  }
  //if 1 of them is null there is no cycle
  if(!fast || !fast->next) return NULL;
  //intersection of fast and slow is entry pt of cycle
  fast=head;
  while(fast!=slow){
      fast=fast->next;
      slow=slow->next;
  }
  return slow;
}
