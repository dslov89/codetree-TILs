#include <iostream>
#include <queue>

using namespace std;

int n,k;
int arr[100][100];
queue<pair<int,int>> q;
int visit[100][100]={};
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};

bool isOkay(int x,int y){
    if(x>=0&&x<n&&y>=0&&y<n){
        if(!visit[x][y]&&!arr[x][y]){
            return true;
        }
    }
    return false;
}

void BFS(){
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for(int i=0;i<4;i++){
            int x1 = x+dx[i];
            int y1 = y+dy[i];

            if(isOkay(x1,y1)){
                visit[x1][y1]=1;
                q.push(make_pair(x1,y1));
            }
        }
    }
}

int main() {
    cin>>n>>k;
    for(int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    int r,c;
    for (int i=0;i<k;i++){
        cin>>r>>c;
        r--;
        c--;
        q.push(make_pair(r,c));
        visit[r][c]=1;
        BFS();
    }
    int answer=0;
    for(int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            if(visit[i][j]) answer++;
        }
    }
    cout<<answer;
    return 0;
}