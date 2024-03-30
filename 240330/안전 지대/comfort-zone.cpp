#include <iostream>
#include <algorithm>

using namespace std;

int n,m;
int arr[50][50];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int maxN;
int visit[50][50]={};

bool CanGo(int x,int y,int k){
    if((x>=0&&x<n&&y>=0&&y<m)&&(arr[x][y]>k)&&!visit[x][y]){
        return true;
    }
    return false;
}

void DFS(int x,int y,int k){
    for(int i=0;i<4;i++){
        int x1 = x+dx[i];
        int y1 = y+dy[i];
        if(CanGo(x1,y1,k)){
            visit[x1][y1]=1;
            DFS(x1,y1,k);
        }
    }
}

int main() {
    cin>>n>>m;
    
    int a;
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }

    int maxAns=0;
    int ansK=1;
    for (int k=1;k<=100;k++){
        int answer=0;
        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                if((arr[i][j]>k)&&!visit[i][j]) {
                 //   cout<<"안녕"<<endl;
                    answer++;
                    DFS(i,j,k);
                }
            }
        }
        if(answer>maxAns){
            maxAns=answer;
            ansK=k;
        }
        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                visit[i][j]=0;
            }
        }
    }

    cout<<ansK<<" "<<maxAns;

    return 0;
}