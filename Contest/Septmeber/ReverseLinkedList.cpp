/**
 * Definition for singly-linked list.*/
#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(NULL) {}
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL){
            return head;
        }
        
        ListNode *prev = NULL,*nxt,*current = head;
        while(current){
             nxt = current->next; 
             current->next = prev;
             prev = current;
             current = nxt;
        }
        head = prev;
        return head;
    }
};