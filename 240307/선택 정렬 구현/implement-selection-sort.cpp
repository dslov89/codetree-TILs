#include <iostream>
#include <vector>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin>>n;
    int arr[n];
   // vector<int> arr;
    for (int i=0;i<n;i++){
        // int k;
        // cin>>k;
        // arr.push_back(k);
        cin>>arr[i];
    }
    for (int i=0;i<n;i++){
        int min = arr[i];
        int k = i;
        for (int j=i;j<n;j++){
            if(min>arr[j]){
                min = arr[j];
                k = j;
            }
        }
        arr[k] = arr[i];
        arr[i] = min;
    }
    for (int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}