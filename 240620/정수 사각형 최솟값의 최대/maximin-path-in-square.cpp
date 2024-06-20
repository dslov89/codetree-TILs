#include <iostream>

using namespace std;

int n;
int arr[101][101];
int dp[101][101];

int DP(int x,int y){
    if(x>=0&&x<n&&y>=0&&y<n){
        return dp[x][y];
    }
    return 0;
}

int main() {
    
    cin>>n;

    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }

    dp[0][0]=arr[0][0]; 

    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            if(i==0&&j==0) continue;
            dp[i][j] = min(max(DP(i-1,j),DP(i,j-1)),arr[i][j]);
        }
    }

    cout<<dp[n-1][n-1];
    return 0;
}