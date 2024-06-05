#include <iostream>

using namespace std;

int n;
int total=0;
int dp[1004]={};


int main() {
    cin>>n;

    dp[0]=1;
    dp[1]=0;
    dp[2]=1;
    dp[3]=1;
    
    for (int i=4;i<=n;i++){
        dp[i]=(dp[i-2]+dp[i-3])%10007;
    }

    cout<<dp[n];
    return 0;
}