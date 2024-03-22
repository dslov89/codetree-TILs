#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> v;
bool arr[9]={};

void Choose(int cnt){
    if(cnt==n){
        for (int i=0;i<v.size();i++){
            cout<<v[i]<<" ";
        }
        cout<<endl;
        return ;
    }

    for (int i=1;i<=n;i++){
        if(arr[i]) continue;
        v.push_back(i);
        arr[i]=true;
        Choose(cnt+1);
        arr[i]=false;
        v.pop_back();
    }
}

int main() {
    cin>>n;
    Choose(0);
    return 0;
}