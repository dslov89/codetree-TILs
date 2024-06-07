#include <iostream>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    
    int n;
    cin>>n;
    int arr[1001];
    arr[0]=1;
    arr[1]=1;
    for (int i=2;i<=n;i++){
        arr[i] = (arr[i-1]+arr[i-2])%10007;
    }
    cout<<arr[n];
    return 0;
}