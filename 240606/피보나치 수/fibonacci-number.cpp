#include <iostream>

using namespace std;
int n;
int arr[47]={};

// void Fibo(){
//     arr[0]=1;
//     arr[1]=1;
//     for (int i=2;i<n;i++){
//         arr[i]=arr[i-2]+arr[i-1];
//     }
// }

int Fibo(int k){
    if(arr[k]==0){
        if(k==1||k==2){
            return arr[k]= 1;
        }
        return arr[k]= Fibo(k-1)+Fibo(k-2);
    }
    return arr[k];
}

int main() {
    cin>>n;
    // Fibo();
    // cout<<arr[n-1];
    cout<<Fibo(n);
    return 0;
}