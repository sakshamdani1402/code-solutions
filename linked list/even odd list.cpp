/* Given the head of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices, and return the reordered list.
The first node is considered odd, and the second node is even, and so on.
Note that the relative order inside both the even and odd groups should remain as it was in the input.
You must solve the problem in O(1) extra space complexity and O(n) time complexity.

Input: head = [1,2,3,4,5]
Output: [1,3,5,2,4]

Input: head = [2,1,3,5,6,4,7]
Output: [2,3,6,7,1,5,4] */

//idea is to make 2 linked list and then concat them

ListNode* oddEvenList(ListNode* head) {
    auto curr = head;
    if(!curr || !curr->next) return head;
    int cnt=1;
    
    ListNode* dummy1 = new ListNode(), *dummy2=new ListNode();
    auto odd = dummy1, even=dummy2;
        
    while(curr){
        auto temp = curr;   //save curr node
        curr = curr->next;  //move forward
        temp->next = NULL;  //break link

        if(cnt&1) odd->next = temp, odd = odd->next;    //if odd node, then add this node in odd list
        else even->next = temp, even = even->next;      //else in even list
        cnt++;
    }

    odd->next = dummy2->next;   //add even list after odd list
    return dummy1->next;        //return new head
}
