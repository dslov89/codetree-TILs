#include <iostream>
#include <vector>

using namespace std;

int n;
int arr[1000]={};
vector<int> v;
int total=0,maxN=0;

void Choose(int cnt){
    if(cnt == n){
        for (int i=0;i<1000;i++){
            if(arr[i]>1){
                return ;
            }
        }
        if(total>maxN){
            maxN=total;
        }
       
        return ; 
    }

    for (int i=v[cnt*2]-1;i<v[cnt*2+1];i++){
        arr[i]++;
    }
    total++;
    Choose(cnt+1);
    total--;
    for (int i=v[cnt*2]-1;i<v[cnt*2+1];i++){
        arr[i]--;
    }

    Choose(cnt+1);

}

int main() {
    // 여기에 코드를 작성해주세요.
    cin>>n;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        v.push_back(a);
        v.push_back(b);
    }
    Choose(0);
    cout<<maxN;
    
    return 0;
}