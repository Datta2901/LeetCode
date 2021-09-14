#include<bits/stdc++.h>
using namespace std;



//  * Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next() {}
    ListNode(int x) : val(x), next() {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


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
        if(head == NULL){
            return false;
        }
        ListNode *slow = head;
        ListNode *fast = head;
        while(fast ->next != NULL && fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                return true;
            }
        }
        return false;
    }
};

void printList(struct ListNode *a){
    cout << "List : ";
    while(a != NULL){
        cout << a->val << " ";
        a = a->next;
    }
    cout << endl;
}


ListNode* GetInput(int size){
    struct ListNode *temp,*head = NULL;
    for(int i = 0; i < size; i++){
        struct ListNode *new_node = (struct ListNode*)malloc(sizeof(struct ListNode));
        int val;
        cin >> val;
        new_node->val = val;
        if(head == NULL){
            head = new_node;
            temp = head;   
        }else{
            temp->next = new_node;
            temp = new_node;
        }
    }
    temp->next = NULL;
    return head;
}

int main(){
    Solution obj;
    struct ListNode *head = NULL;
    int size;
    cin >> size;
    head = GetInput(size);
    
    return 0;
}