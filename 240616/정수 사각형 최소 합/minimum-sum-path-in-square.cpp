#include <iostream>

using namespace std;
int n;
int arr[101][101];
int dp[101][101];

int DP(int x,int y){
    if(x>=0&&x<n&&y>=0&&y<n){
        return dp[x][y];
    }
    return 1000000;
}

int main() {
    cin>>n;

    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            cin>>arr[i][j];
            dp[i][j]=arr[i][j];
        }
    }

    for (int i=0;i<n;i++){
        for (int j=n-1;j>=0;j--){
            if(i==0&&j==(n-1)) continue;
            dp[i][j]=min(DP(i,j+1),DP(i-1,j))+arr[i][j];
        }
    }

    cout<<dp[n-1][0];
    
    return 0;
}