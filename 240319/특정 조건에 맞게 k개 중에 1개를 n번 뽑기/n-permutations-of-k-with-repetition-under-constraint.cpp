#include <iostream>
#include <vector>
using namespace std;

int k,n;
vector<int> v;

bool isThree(){
    int s = v.size();
    if((s>=3)&&(v[s-1]==v[s-2])&&(v[s-2]==v[s-3])) return true;
    return false;
}

void Choose(int cnt){
    if(cnt==n){
        for(int i=0;i<v.size();i++){
            cout<<v[i]<<" ";
        }
        cout<<endl;
        return;
    }

    for(int i=1;i<=k;i++){
        v.push_back(i);
        if(!isThree()){
            Choose(cnt+1);
        }
        v.pop_back();
    }

}

int main() {
    
    cin>>k>>n;

    Choose(0);

    return 0;
}