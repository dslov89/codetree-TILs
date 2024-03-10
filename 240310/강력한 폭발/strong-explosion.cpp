#include <iostream>
#include <vector>

using namespace std;

int n,bomb=0,total=0;
int arr[20][20];
vector<int> v;

bool isOkay(int i,int j){
    if(i>=0&&i<n&&j>=0&&j<n) return true;
    return false;
}

void Chose(int cnt){
    if(cnt == bomb){
        int k=0;
        for (int i=0;i<n;i++){
            for (int j=0;j<n;j++){
                // cout<<arr[i][j]<<" ";
                if(arr[i][j]>0) k++;
            }
            // cout<<endl;
        }
        if(total<k) total=k;
        return;
    }

    int i = v[cnt*2];
    int j = v[cnt*2+1];


    if(isOkay(i+1,j)) arr[i+1][j]++;
    if(isOkay(i+2,j)) arr[i+2][j]++;
    if(isOkay(i-1,j)) arr[i-1][j]++;
    if(isOkay(i-2,j)) arr[i-2][j]++;
    Chose(cnt+1);
    if(isOkay(i+1,j)) arr[i+1][j]--;
    if(isOkay(i+2,j)) arr[i+2][j]--;
    if(isOkay(i-1,j)) arr[i-1][j]--;
    if(isOkay(i-2,j)) arr[i-2][j]--;

    if(isOkay(i+1,j)) arr[i+1][j]++;
    if(isOkay(i,j+1)) arr[i][j+1]++;
    if(isOkay(i-1,j)) arr[i-1][j]++;
    if(isOkay(i,j-1)) arr[i][j-1]++;
    Chose(cnt+1);
    if(isOkay(i+1,j)) arr[i+1][j]--;
    if(isOkay(i,j+1)) arr[i][j+1]--;
    if(isOkay(i-1,j)) arr[i-1][j]--;
    if(isOkay(i,j-1)) arr[i][j-1]--;

    if(isOkay(i+1,j+1)) arr[i+1][j+1]++;
    if(isOkay(i-1,j-1)) arr[i-1][j-1]++;
    if(isOkay(i+1,j-1)) arr[i+1][j-1]++;
    if(isOkay(i-1,j+1)) arr[i-1][j+1]++;
    Chose(++cnt);
    if(isOkay(i+1,j+1)) arr[i+1][j+1]--;
    if(isOkay(i-1,j-1)) arr[i-1][j-1]--;
    if(isOkay(i+1,j-1)) arr[i+1][j-1]--;
    if(isOkay(i-1,j+1)) arr[i-1][j+1]--;

}

int main() {

    cin>>n;

    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            cin>>arr[i][j];
             if(arr[i][j]) {
                bomb++;
                //v.push_back(bomb);
                v.push_back(i);
                v.push_back(j);
            }
        }
    }

    Chose(0);

    cout<<total;
   
    return 0;
}

//C(0)- 1,2,3
//C(1) -