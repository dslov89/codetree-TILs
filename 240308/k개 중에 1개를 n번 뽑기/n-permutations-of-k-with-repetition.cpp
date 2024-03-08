#include <iostream>
#include <vector>

using namespace std;

int k,n;
vector<int> v;

void Print(){
    for (int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

void Chose(int cnt){
    if (cnt == n) {
        Print();
        return;
    }

    for (int i=1;i<=k;i++){
        v.push_back(i);
        Chose(cnt+1);
        v.pop_back();

    }
}

int main() {
    cin>>k>>n;
    Chose(0);
    return 0;
}