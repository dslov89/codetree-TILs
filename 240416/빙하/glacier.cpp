#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n,m;
int arr[200][200];
queue<pair<int,int>> oneQ;
queue<pair<int,int>> zeroQ;
queue<pair<int,int>> delOne;

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

int cnt=0;
bool visit[200][200];

bool CanGo(int x,int y){
    return (x>=0&&x<n&&y>=0&&y<m)&&!visit[x][y]&&!arr[x][y];
}

bool zeroEffect(){
    while(!zeroQ.empty()){
        int x = zeroQ.front().first;
        int y = zeroQ.front().second;
        zeroQ.pop();

        for(int i=0;i<4;i++){
            int x1 = x+dx[i];
            int y1 = y+dy[i];

            if(CanGo(x1,y1)){
                if(x1==cnt||x1==(n-cnt-1)||y1==cnt||y1==(m-cnt-1)) return true;
                zeroQ.push(make_pair(x1,y1));
                visit[x1][y1]=true;
            }
        }
    }
    return false;
}

bool isDelete(int x, int y){
    if(x==cnt||x==(n-cnt-1)||y==cnt||y==(m-cnt-1)){
        return true;
    }
    zeroQ.push(make_pair(x,y));
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            visit[i][j]=false;
        }
    }
    return zeroEffect();
}

void BFS(){
    while(!oneQ.empty()){
        int x = oneQ.front().first;
        int y = oneQ.front().second;
        oneQ.pop();

        for(int i=0;i<4;i++){
            int x1 = x+dx[i];
            int y1 = y+dy[i];

            if(!arr[x1][y1]&&isDelete(x1,y1)){
                delOne.push(make_pair(x,y));
                break;
            }
        }
    }
}

int main() {
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
            if(arr[i][j]) oneQ.push(make_pair(i,j));
        }
    }

    int ans;
    while(true){
        ans = oneQ.size();
        BFS();
        cnt++;
        while(delOne.empty()){
            arr[delOne.front().first][delOne.front().second]=0;
            delOne.pop();
        }
        for(int i=(cnt+1);i<(n-cnt-1);i++){
            for(int j=(cnt+1);j<(m-cnt-1);j++){
                if(arr[i][j]) oneQ.push(make_pair(i,j));
            }
        }
        if(oneQ.empty()) break;
    }

    cout<<cnt<<" "<<ans;

    return 0;
}