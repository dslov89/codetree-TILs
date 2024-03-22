#include <iostream>
#include <vector>
using namespace std;

int m,n;
int maxN=0;
vector<int> v;
vector<int> ans;


void Xor(){
    int total=ans[0];
    for (int i=1;i<n;i++){
        total = total^ans[i];
    }
    if(maxN<total){
        maxN=total;
    }
}


void Choose(int cnt,int i){

    if(i==m){
        if(cnt==n){
            Xor();
        }
        return ;
    }

    ans.push_back(v[i]);
    Choose(cnt+1,i+1);
    ans.pop_back();

    Choose(cnt,i+1);

}

int main() {
    cin>>m>>n;
    for (int i=0;i<m;i++){
        int k;
        cin>>k;
        v.push_back(k);
    }
    Choose(0,0);
    cout<<maxN;
    return 0;
}