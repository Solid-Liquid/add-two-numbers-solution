/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *solution = NULL;
    struct ListNode *next = NULL;
    int carry = 0, sum = 0;
    
    while(l1 || l2 || carry){
        
        sum = 0 + carry;
        
        if(l1){
            sum += l1->val;
            l1 = l1->next;
        }
        
        if(l2){
            sum += l2->val;
            l2 = l2->next;
        }
        
        if(sum >= 10){
            carry = 1;
            sum -= 10;
        }
        else
            carry = 0;
        
        if(next){
            next->next = malloc(sizeof(struct ListNode));
            next = next->next;
            next->val = sum;
            next->next = NULL;
        }
        else{
            solution = malloc(sizeof(struct ListNode));
            solution->val = sum;
            solution->next = NULL;
            next = solution;
        }
    }
    
    return solution;
}