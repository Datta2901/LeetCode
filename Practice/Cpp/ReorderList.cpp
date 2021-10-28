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
    void reorderList(ListNode* head) {
        vector<int>answer;
        ListNode* temp = head;
        while(temp != NULL){
            answer.push_back(temp->val);
            temp = temp->next;
        }
        temp = head;
        int start = 0;
        bool s = true;
        int end = answer.size() - 1;
        bool e = false;
        while(temp != NULL){
            cout << start << " " << end << endl;
                if(s){
                    temp->val = answer[start++];
                    s = false;
                }else{
                    temp->val = answer[end--];
                    s = true;
                }
            temp = temp->next;
        }
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
    obj.reorderList(head);
    return 0;
}