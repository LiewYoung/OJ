#include<iostream>

using namespace std;


    bool isOne(int nums) {
        int count = 1;
        while (nums != 0) {
            if(nums & 1 == 1) {
                count++;
            }

            if(count >= 3) {
                return true;
            }
            nums = nums >> 1;
        }
        return false;
    
    }
int main() {
    int nums;
    cin>>nums;
    cout<<isOne(nums)<<endl;
    return 0;
}