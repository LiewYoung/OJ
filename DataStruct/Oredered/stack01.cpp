#include<iostream>

#define MAX_STACK 100000

using namespace std;
/*这里我们借助数组实现一个简单的栈*/


int stack[MAX_STACK]; 

void push(int stack[],int& t,int value) {
    if(t >= MAX_STACK) {
        cerr<<"Fail! Full STACK"<<endl;
        return;
    } 
    stack[t] = value;
    t++;
}


int pop(int stack[],int& t) {
    if(t == 0 ) {
        cerr<<"INVAILD STACK"<<endl;
    }

    t--;
    return stack[t];
}

int main(void) {
    int t = 0;
                   
    push(stack,t,10);
    push(stack,t,9);

    cout<<pop(stack,t)<<endl;
    cout<<pop(stack,t)<<endl;

    return 0;
}
