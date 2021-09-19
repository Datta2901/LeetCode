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
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL){
            return head;
        }if(head->next == NULL){
            return NULL;
        }
        ListNode *temp = head,*prev = head;
        int size = 0;
        while(temp){
            temp = temp->next;
            size++;
        }
        temp = head;
        int count = 0;
        while(temp){
            if(size - n == 0){
                ListNode* node = head;
                head = head->next;
                delete(node);
                return head;
            }
            if(count == size - n){
                ListNode* node = temp;
                prev->next = (temp->next);
                delete(node);
                return head;
            }
            count++;
            prev = temp;
            temp = temp->next;
        }
        return head;
    }
};

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

void printList(struct ListNode *a){
    // cout << "List : ";
    while(a != NULL){
        cout << a->val << " ";
        a = a->next;
    }
    cout << endl;
}


int main(){
    Solution obj;
    struct ListNode *head = NULL;
    int size,n;
    cin >> size >> n;
    head = GetInput(size);
    // printList(head);
    printList(obj.removeNthFromEnd(head,n));
    return 0;
}