#include<iostream>
#include<string>
#include<unordered_map>

using namespace std;

int main(void) {
    while (true) {
        int n;
        cin>>n;
        if(n==0) break;
        unordered_map<string,int> balloons;
        string maxBalloons;
        int value = 0;
        
        for(int i = 0;i < n;i++){
            string temp;
            cin>>temp;
            auto it = balloons.find(temp);
            if(it != balloons.end() ){
                balloons[temp]++;
            }else{
                balloons[temp] = 1;
            }
        }

        unordered_map<string,int>::iterator it;

        for(it = balloons.begin();it!=balloons.end();it++){
            if(balloons[it->first] > value) {
                maxBalloons = it->first;
                value = it->second;
            }
        }
        cout<<maxBalloons<<endl;
    }    
}