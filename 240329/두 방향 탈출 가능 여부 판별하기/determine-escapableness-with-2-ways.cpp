#include <iostream>

using namespace std;

int n,m;
int arr[101][101];
int visit[101][101]={};

//오른쪽, 아래
int dx[2]={0,1};
int dy[2]={1,0};

int answer = 0;

bool CanGo(int x,int y){
    if((x>=0&&x<n&&y>=0&&y<m)&&arr[x][y]&&!visit[x][y]){
      return true;
    }
    return false;
}

void DFS(int x, int y){
    for(int i=0;i<2;i++){
        int x1 = x+dx[i];
        int y1 = y+dy[i];
        if(CanGo(x1,y1)){
            visit[x1][y1]=1;
            DFS(x1,y1);
        }
    }
    if(x==(n-1)&&y==(m-1)){
        answer = 1;
    }
}

int main() {
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }

    DFS(0,0);

    cout<<answer;
    return 0;
}