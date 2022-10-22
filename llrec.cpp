#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot){
	if(head == nullptr){ //base case
        return;
    }
    else if(head->val <= pivot){//if the node is less than or equal to pivot add it to smaller and remove head
        Node* temp = head->next;
        smaller = nullptr;
        smaller = head;
        smaller->next = nullptr;
        head = nullptr;
        llpivot(temp, smaller->next, larger, pivot); //recurse, using the next node in smaller as smaller was filled
    }
    else if(head->val > pivot){//if the node is greater than pivot, put it in the "larger" list
        Node* temp = head->next;
        larger = nullptr;
        larger = head;
        larger->next = nullptr;
        head = nullptr;
        llpivot(temp, smaller, larger->next, pivot);
    }
    head = nullptr;
    return;
}
