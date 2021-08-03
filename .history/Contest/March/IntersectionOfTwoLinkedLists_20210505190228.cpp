#include<bits/stdc++.h>

using namespace std;

class Solution {
private:
	void changeSign(ListNode *head){
		while (head){
			head->val *= -1;
			head = head->next;
		}
	}
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		changeSign(headA);
		
		while (headB){
			if (headB->val < 0) break;
			headB = headB->next;
		}
		
		changeSign( headA );
		return headB;
	}
};

int main(){

    return 0;
}