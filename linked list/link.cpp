#include <bits/stdc++.h>

using namespace std;

struct node {
    int data;
    node *next;
};

struct dnode{
	int data;
	dnode* prev;
	dnode* next;
};

struct cnode{
	int data;
	cnode* next;
};

int sListLength(node* head){
    if(!head)
        return 0;
    int length = 0;
    node* current = head;
    while(current)
    {
        current = current->next;
        length++;
    }
    return length;
}

void sPrintList(node* head){
	if(!head)
		return;
	while(head){
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}

void sInsert(node** head, int data, int pos){
    if(pos < 1)
        return;
    node* toIns = new node;
    toIns->data = data;
    toIns->next = NULL;
    if(pos == 1){
        toIns->next = *head;
        *head = toIns;
        sPrintList(*head);
        return;
    }
    int localpos = 1;
    node* start = *head;
    while(start && localpos < pos-1){
        localpos++;
        start = start->next;
    }
    if(localpos == pos - 1){
        node* next = start->next;
        start->next = toIns;
        toIns->next = next;
    }
    sPrintList(*head);
}

void sDelete(node** head, int pos){
	if(pos < 1 || !(*head))
		return;
    node* thead = *head;
    if(pos == 1){
        node* toDel = thead;
        *head = toDel->next;
        delete toDel;
        sPrintList(*head);
        return;
    }
    int localpos = 1;
    while(thead && localpos < pos - 1){
    	thead = thead->next;
    	localpos++;
    }
    if(localpos == pos - 1){
    	node* toDel = thead->next;
    	if(toDel){
    		thead->next = toDel->next;
    		delete toDel;
    	}
    }
    sPrintList(*head);
}

void sDeleteList(node** head){
	node* thead = *head;
	while(thead){
		node* toDel = thead;
		thead = thead->next;
		delete toDel;
	}
	*head = NULL;
}

void dPrintList(dnode* head){
	if(!head)
		return;
	while(head){
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}

void dInsert(dnode** head, int data, int pos){
	if(pos < 1)
		return;
	dnode* thead = *head;
	dnode* toIns = new dnode;
	toIns->data = data;
	toIns->prev = NULL;
    toIns->next = NULL;
	if(pos == 1){
        if(thead)
		      thead->prev = toIns;
		toIns->next = thead;
		*head = toIns;
        dPrintList(*head);
		return;
	}
	int localpos = 1;
	while(thead && localpos < pos - 1){
		localpos++;
		thead = thead->next;
	}
	if(localpos == pos - 1 && thead){
		toIns->next = thead->next;
		toIns->prev = thead;
		if(thead->next)
			thead->next->prev = toIns;
		thead->next = toIns;
	}
    dPrintList(*head);
}

void dDelete(dnode** head, int pos){
	if(pos < 1 || !(*head))
		return;
	dnode* thead = *head;
	if(pos == 1){
		dnode* toDel = thead;
		*head = thead->next;
		delete toDel;
        dPrintList(*head);
		return;
	}
	int localpos = 1;
	while(thead && localpos < pos-1){
		localpos++;
		thead = thead->next;
	}
	if(localpos == pos-1){
		dnode* toDel = thead->next;
		if(toDel){
			thead->next = toDel->next;
			if(toDel->next)
				toDel->next->prev = thead;
			delete toDel;
		}
	}
    dPrintList(*head);
}

int cListLength(cnode* head){
	if(!head)
		return 0;
	cnode* current = head;
	int length = 1;
	while(current->next != head){
		length++;
		current = current->next;
	}
	return length;
}

void cPrintList(cnode* head){
	if(!head)
		return;
	cnode* current = head;
    cout << current->data << " ";
    current = current->next;
	while(current != head){
		cout << current->data << " ";
		current = current->next;
	}
	cout << " Length : " << cListLength(head)    <<endl;
}

void cInsertLast(cnode** head, int data){
	cnode* lhead = *head;
	cnode* toIns = new cnode;
	toIns->data = data;
	toIns->next = NULL;
	if(!lhead){
		*head = toIns;
		toIns->next	= toIns;
        cPrintList(*head);
		return;
	}
	while(lhead->next != *head)
		lhead = lhead->next;
	lhead->next = toIns;
	toIns->next = *head;
    cPrintList(*head);
}

void cInsertFront(cnode** head,int data){
	cnode* toIns = new cnode;
	toIns->data = data;
	toIns->next = NULL;
	cnode* current = *head;
	if(!current){
		*head = toIns;
		toIns->next = toIns;
        cPrintList(*head);
		return;
	}
	toIns->next = current;
	while(current->next != *head)
		current = current->next;
	current->next = toIns;
    *head = toIns;
    cPrintList(*head);
}

void cDeleteLast(cnode** head){
	if(!(*head))
		return;
	cnode* lhead = *head;
	if(lhead->next == lhead){
		delete lhead;
		*head = NULL;
        cPrintList(*head);
		return;
	}
	cnode* current = lhead;
	while(current->next->next != lhead)
		current = current->next;
	cnode* toDel = current->next;
	current->next = toDel->next;
	delete toDel;
    cPrintList(*head);
}

void cDeleteFront(cnode** head){
	cnode* thead = *head;
	if(!thead) return;
    if(thead->next == thead) {
        delete thead;
        *head = NULL;
        cPrintList(*head);
        return;
    }
	cnode* toDel = *head;
	while(thead->next != *head)
		thead = thead->next;
	thead->next = toDel->next;
	delete toDel;
    *head = toDel->next;
    cPrintList(*head);
}

int main(){
    /* Testing circular linked list
    cnode* head = NULL;
    //for(int i=1;i<5;i++){
        cInsertFront(&head,5);
        cInsertLast(&head,4);
        cDeleteFront(&head);
    //}
    //for(int i=1;i<5;i++){
    //    cDeleteLast(&head);
    //}*/
    /* // Testting doubly linked list
    dnode* head = NULL;
    for(int i=1;i<=10;i++){
        dInsert(&head, i,i);
    }
    for(int i=1;i<=10;i++){
        dDelete(&head,1);
    }

    std::cout << "After" << '\n';
    dPrintList(head);
    //*/
    /*// Testing singly linked list
    node* head = NULL;
    for(int i=1;i<=5;i++){
        sInsert(&head, i, i);
    }
    for(int i=1;i<=5;i++){
        sDelete(&head,1 );
    }
    sDeleteList(&head);
    //*/
}
