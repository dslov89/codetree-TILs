#include <iostream>

using namespace std;
int n;
int arr[46]={};

void Fibo(){
    arr[0]=1;
    arr[1]=1;
    for (int i=2;i<n;i++){
        arr[i]=arr[i-2]+arr[i-1];
    }
}

int main() {
    cin>>n;
    Fibo();
    cout<<arr[n-1];
    return 0;
}