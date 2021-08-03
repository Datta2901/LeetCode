#include<bits/stdc++.h>

using namespace std;

ListNode* getIntersectionNode(ListNode *headA, ListNode *headB) {
    map<int,int> fre;
    ListNode* h1,h2;
    h1 = headA;
    h2 = headB;
    while(h1 != NULL){
        fre[h1->val] = 1;
        h1 = h1->next;
    }    
    while(h2 != NULL){
        if(fre[h2->val]){
            
        }
    }
}

int main(){

    return 0;
}