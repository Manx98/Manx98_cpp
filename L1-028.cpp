#include<iostream>
#include<cmath>
#include<windows.h>
using namespace std;
bool check(int n){
    if(n<=1)
        return 0;
    for(int i=2;i<=sqrt(n);++i){
        if(n%i==0)
            return 0;
    }
    return 1;
}
int main(){
    int n;
    cin>>n;
    while(n--){
        int i;
        cin>>i;
        if(check(i)){
            cout<<"Yes\n";
        }else{
            cout<<"No\n";
        }
    }
    system("pause");}