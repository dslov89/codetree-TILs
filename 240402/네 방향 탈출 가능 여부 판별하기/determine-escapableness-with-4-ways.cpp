#include <iostream>
#include <queue>

using namespace std;

int n,m;
int arr[100][100];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
bool visit[100][100];
queue<pair<int,int>> q;

bool isOkay(int x,int y){
    if((x>=0&x<n&&y>=0&&y<m)&&!visit[x][y]&&arr[x][y]){
        return true;
    }
    return false;
}

void Push(int x,int y){
    visit[x][y]=true;
    q.push(make_pair(x,y));
}

void BFS(){
    while(!q.empty()) {
        pair<int,int> curr = q.front();
        q.pop();

        int x = curr.first;
        int y = curr.second;
        for(int i=0;i<4;i++){
            int x1 = x+dx[i];
            int y1 = y+dy[i];
            if(isOkay(x1,y1)){
                Push(x1,y1);
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

    Push(0,0);
    BFS();
    
    cout<<visit[n-1][m-1];

    return 0;
}