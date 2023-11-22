#include <iostream>
using namespace std;
int main() {
    int n,m;
    cin>>n>>m;
    int arr[n][n]={};
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    int total=0;
    int num=0,cnt=0;
    for (int i=0;i<n;i++){
        num=arr[i][0];
        for (int j=0;j<n;j++){
           if(num==arr[i][j]){
            cnt++;
           } else{
            num=arr[i][j];
           }
           if(cnt==m){
            total++;
            break;
           }
        }
        cnt=0;
    }
     for (int i=0;i<n;i++){
        num=arr[0][i];
        for (int j=0;j<n;j++){
           if(num==arr[j][i]){
            cnt++;
           } else{
            num=arr[j][i];
           }
           if(cnt==m){
            total++;
            break;
           }
        }
        cnt=0;
    }
    cout<<total;
    return 0;
}