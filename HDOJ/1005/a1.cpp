#include<iostream>

using namespace std;

/*错误之处栈溢出MLE*/
int getAnswer(int A,int B,int n){
    if(n == 1 || n == 2) return 1;
    return (A*getAnswer(A,B,n-1)+B*getAnswer(A,B,n-2))%7;
}

int main(void){
    int A,B;
    int n;
    while(true){
        cin>>A>>B>>n;
        if(A==0&&B==0&&n==0) break;
        printf("%d\n",getAnswer(A,B,n));
    }
    return 0;
}