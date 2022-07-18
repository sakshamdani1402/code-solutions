// Given the head of a singly linked list, return true if it is a palindrome.

// Input: head = [1,2,2,1]
// Output: true

// Input: head = [1,2]
// Output: false

// METHOD 1 - Store vals of linked list in a arr/ string and then check if it is a palindrome or not

//METHOD 2 - 2 POINTERS
ListNode* reverse(ListNode* head){
    if(!head || !head->next) return head;
    auto curr = reverse(head->next);
    head->next->next = head;
    head->next=NULL;
    return curr;
}

bool isPalindrome(ListNode* head) {
    auto slow=head, fast=head;
    //find mid pt
    while(fast->next && fast->next->next) slow = slow->next, fast=fast->next->next;

    slow->next = reverse(slow->next);  //reverse from mid pt

    auto one = head, two = slow->next;
    //while ll doent end
    while(two){
        if(one->val != two->val) return false;  //not palindrome
        one = one->next, two=two->next;
    }
    //no problem occured, so return true
    return true;
}
