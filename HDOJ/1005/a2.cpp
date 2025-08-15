#include<iostream>

using namespace std;

/*错误之处TLE*/
int getAnswer(int A,int B,int n){
    A %= 7;
    B %= 7;

    int prev1 = 1;
    int prev2 = 2;
    int curr = 0;

    if(n == 1 || n == 2) return 1;
    
    for(int i = 2;i<n;i++){
        curr = A*prev1+B*prev2;
        prev1 = prev2;
        prev2 = curr;
    }
    return curr;
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