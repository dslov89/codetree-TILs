#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> v;
int arr[9]={};

void Choose(int cnt){
    if(cnt==n){
        for (int i=0;i<n;i++){
            cout<<v[i]<<" ";
        }
        cout<<endl;
        return ;
    }

    for (int i=n;i>0;i--){
        if(arr[i]==1) continue;
        v.push_back(i);
        arr[i]=1;
        Choose(cnt+1);
        arr[i]=0;
        v.pop_back();
    }
}

int main() {
    cin>>n;
    Choose(0);
    return 0;
}