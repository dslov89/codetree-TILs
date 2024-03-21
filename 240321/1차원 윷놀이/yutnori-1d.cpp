#include <iostream>
#include <vector>

using namespace std;

int n,m,k;
vector<int> v;
int arr[4] = {1,1,1,1};
int maxN = 0;

void Choose(int cnt){
    if(cnt==n){
        int total=0;
        for (int i=0;i<k;i++){
            if(arr[i]>=m){
                total ++;
            }
        }
        if(total>maxN){
            maxN=total;
        }
        return ;
    }

    for (int j=0;j<k;j++){
        //if(arr[j]<m){
            arr[j] += v[cnt];
            Choose(cnt+1);
            arr[j] -= v[cnt];
        //}
    }
}

int main() {
    cin>>n>>m>>k;
    for (int i=0;i<n;i++){
        int r;
        cin>>r;
        v.push_back(r);
    }

    Choose(0);
    cout<<maxN;
    return 0;
}