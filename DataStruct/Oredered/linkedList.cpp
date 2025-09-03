#include<iostream>

#define PASS 0;
#define ERROR 1;

using namespace std;

typedef struct Node* NodePtr;

struct Node {
    int data;
    NodePtr next;
};

NodePtr initList() {
    NodePtr newNode = new Node;
    newNode->data = 0;
    newNode->next = nullptr;
    return newNode;
}

int insert(const int value,NodePtr list) {
    if(!list) return ERROR;
    NodePtr temp = list;
    
    while (temp->next) {
        temp = temp->next;
    }

    NodePtr newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;
    
    return PASS;
}

int remove(const int index,NodePtr list) {
    if(!list) return ERROR;
    NodePtr head = list;

    for(int i = 0;i<index;i++) {
        head = head->next;
    }

    NodePtr temp = head->next;
    head->next = temp->next;
    delete temp;

    return PASS;
 }

int setter(const int index,int value,NodePtr list) {
    if(!list) return ERROR;
    NodePtr head = list;

    int i = 0;
    while(head->next && i<index) {
        head = head->next;
    }
    
    if(head->next) {
        head->next->data = value;
    } else {
        return ERROR;
    }

    return PASS;
}

int getter(const int index,NodePtr list,int& result) {
    if(!list) return ERROR;

    NodePtr temp = list;
    int i = 0;

    while (temp->next && i < index) {
        temp = temp->next;
    }

    if(temp->next) {
        result = temp->next->data;
    } else {
        return ERROR
    }
    return PASS;
}

int main(void) {
    NodePtr head = initList();


    
}