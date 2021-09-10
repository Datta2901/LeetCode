#include<bits/stdc++.h>
using namespace std;


//  Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(NULL) {}
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// O(N) 

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* temp = head;
        int size = 0;
        while(temp){
            size++;
            temp = temp->next;
        }
        temp = head;
        int count = 0;
        while(temp){
            count++;
            if(count == ((size + 2) / 2)){
                return temp;
            }
            temp = temp->next;
        } 
        return temp;
    }
};

// O(N/2)
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *fast = head,*slow = head;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};

int main(){
    Solution obj;
    return 0;
}