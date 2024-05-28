#include <iostream>
#include <queue>

using namespace std;
    
int n,m;

int arr[100][100];

int dx[4]={0,1,0,-1};
int dy[4]= {1,0,-1,0};

bool visit[100][100]={};
int step[100][100];

queue<pair<int,int>> q;

void Push(int x, int y,int s){
    q.push(make_pair(x,y));
    visit[x][y]=true;
    step[x][y]=s;
}

bool CanGo(int x, int y){
    if((x>=0&&x<n&&y>=0&&y<m)&&!visit[x][y]&&arr[x][y]) {
        return true;
    }
    return false;
}

void BFS(){
    int s=0;
    while(!q.empty()){
        pair<int,int> curr = q.front();
        q.pop();

        for (int i=0;i<4;i++){
            int x = curr.first+dx[i];
            int y = curr.second+dy[i];

            if(CanGo(x,y)){
                Push(x,y,step[curr.first][curr.second]+1);
            }
        }
    }
}

int main() {

    cin>>n>>m;

    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }

    step[n-1][m-1]=-1;
    Push(0,0,0);
    
    BFS();

    cout<<step[n-1][m-1];
    return 0;
}