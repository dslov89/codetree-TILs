#include <iostream>

using namespace std;

int n;
int arr[3][3];
int dir[3][3];
int r,c;
int dirX[9]={0,0,1,1,1,0,-1,-1,-1};
int dirY[9]={0,-1,-1,0,1,1,1,0,-1};
int maxN=0;

bool isOkay(int x,int y){
    if(x>=0&&x<3&&y>=0&&y<3) return true;
    return false;
}

void Choose(int cnt){
    int x = dirX[dir[r][c]];
    int y = dirY[dir[r][c]];

    if(maxN<cnt){
        maxN=cnt;
    }
    
    if(isOkay(r+y,c+x)&&arr[r+y][c+x]>arr[r][c]){
        r+=y;
        c+=x;
       // cout<<r<<c<<" "<<cnt<<endl;
        Choose(cnt+1);
        r-=y;
        c-=x;
    }

    if(isOkay(r+2*y,c+2*x)&&arr[r+2*y][c+2*x]>arr[r][c]){
        r+=2*y;
        c+=2*x;
       // cout<<r<<c<<" "<<cnt<<endl;
        Choose(cnt+1);
        r-=2*y;
        c-=2*x;
    }    

}

int main() {
    cin>>n;
    for (int i=0;i<3;i++){
        for (int j=0;j<3;j++){
            cin>>arr[i][j];
        }
    }
    for (int i=0;i<3;i++){
        for (int j=0;j<3;j++){
            cin>>dir[i][j];
        }
    }
    cin>>r>>c;
    r--;
    c--;

    Choose(0);

    cout<<maxN;
    return 0;
}