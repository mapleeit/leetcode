// first solution. Memory exceeded...
int getListLength(ListNode *node,int i){
    if(node == NULL) return 0;
    else if (!node -> next)
    {
    	return i;
    }else return getListLength(node -> next, i + 1);
}

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if (!headA || !headB) return NULL;
    int lenA = getListLength(headA, 1),
        lenB = getListLength(headB, 1);
    ListNode *p1 = headA,
             *p2 = headB;
    int lenDelta = lenA - lenB;
    if (lenDelta < 0){ // lenA < lenB
        for(int i = 0; i < -lenDelta;i++){
            p2 = p2 -> next;
        }
        p1 = p1 -> next;
        p2 = p2 -> next;
        if (p1 = p2) return p1;
    }else if(lenDelta > 0){
        for(int i = 0; i < lenDelta;i++){
            p1 = p1 -> next;
        }
        p1 = p1 -> next;
        p2 = p2 -> next;
        if (p1 = p2) return p1;
    }else{
        p1 = p1 -> next;
        p2 = p2 -> next;
        if (p1 = p2) return p1;
    }
}
// others solution: what a genius!!
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
{
    ListNode *p1 = headA;
    ListNode *p2 = headB;

    if (p1 == NULL || p2 == NULL) return NULL;

    while (p1 != NULL && p2 != NULL && p1 != p2) {
        p1 = p1->next;
        p2 = p2->next;

        //
        // Any time they collide or reach end together without colliding 
        // then return any one of the pointers.
        //
        if (p1 == p2) return p1;

        //
        // If one of them reaches the end earlier then reuse it 
        // by moving it to the beginning of other list.
        // Once both of them go through reassigning, 
        // they will be equidistant from the collision point.
        //
        if (p1 == NULL) p1 = headB;
        if (p2 == NULL) p2 = headA;
    }

    return p1;
}
// #include <iostream>

// using namespace std;

// struct ListNode {
//     int val;
// 	ListNode *next;
// }node0, node1, node2;

// int getListLength(ListNode *node,int i){
//     if(node == NULL) return 0;
//     else if (!node -> next)
//     {
//     	return i;
//     }else return getListLength(node -> next, i + 1);
// }

// ListNode *getLastNode(ListNode *node){
// 	if (node -> next)
// 	{
// 		cout << node->val << endl;
// 		return getLastNode(node->next);
// 	}else{
// 		cout << "WTF" << node->val << endl;
// 		return node;
// 	}
// }

// ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    
// }

// int main(){
// 	ListNode result;
// 	node0.val = 0;
// 	node0.next = &node1;
// 	node1.val = 1;
// 	node1.next = &node2;
// 	node2.val = 2;
// 	int val = getListLength(&node0, 1);

// 	cout << val << endl;
// 	return 0;
	
// }