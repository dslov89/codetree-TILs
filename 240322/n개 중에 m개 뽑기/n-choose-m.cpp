#include <iostream>
#include <vector>

using namespace std;
int n,m;
vector<int> v;

void Choose(int cnt, int prev){
    if(cnt==m) {
        for(int i=0;i<m;i++){
            cout<<v[i]<<" ";
        }
        cout<<endl;
        return;
    }

    for (int i=1;i<=n;i++){
        if(i<=prev) continue;
        v.push_back(i);
        Choose(cnt+1,i);
        v.pop_back();
    }
}

int main() {
    cin>>n>>m;
    Choose(0,0);
    return 0;
}