#include<bits/stdc++.h>

using namespace std;

ListNode* getIntersectionNode(ListNode *headA, ListNode *headB) {
    map<int,int> fre;
    ListNode* h1,h2;
    if(headA == NULL )
    h1 = headA;
    h2 = headB;
    while(h1 != NULL){
        fre[h1->val] = 1;
        h1 = h1->next;
    }    
    while(h2 != NULL){
        if(fre[h2->val]){
            return h2;
        }else{
            h2 = h2->next;
        }
    }
}

int main(){

    return 0;
}