#include <iostream>
#include <algorithm>

using namespace std;

int n,blockN,num;
int arr[100][100];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int visit[100][100]={};

bool CanGo(int x,int y){
    if((x>=0&&x<n&&y>=0&&y<n)&&!visit[x][y]&&arr[x][y]==num){
        return true;
    }
    return false;
}

void DFS(int x,int y){
    for (int i=0;i<4;i++){
        int x1 = x+dx[i];
        int y1 = y+dy[i];
        if(CanGo(x1,y1)){
            visit[x1][y1]=1;
            blockN++;
            DFS(x1,y1);
        }
    }

}

int main() {
    cin>>n;

    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }

    int bomb=0;
    int maxBlock = 0;
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            if(!visit[i][j]){
                visit[i][j]=1;
                num=arr[i][j];
                blockN=1;
                DFS(i,j);
                if(blockN>=4) bomb++;
                maxBlock=max(maxBlock,blockN);
            }
        }
    }

    cout<<bomb<<" "<<maxBlock;

    return 0;
}