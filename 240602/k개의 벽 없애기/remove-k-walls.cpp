#include <iostream>
#include <queue>
#include <climits>

using namespace std;

int n,k;
int arr[101][101];
int r1,c1,r2,c2;
bool visit[101][101]={};
int step[101][101];
queue<pair<int,int>> q;

bool CanGo(int x, int y){
    return (x>=0&&x<n&&y>=0&&y<n)&&!visit[x][y]&&!arr[x][y];
}

void Push(int x, int y,int s){
    q.push(make_pair(x,y));
    visit[x][y]=true;
    step[x][y]=s;
}

void BFS(){
    int dx[4]={0,1,0,-1};
    int dy[4]={1,0,-1,0};
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

int minN=INT_MAX;
vector<pair<int,int>> v;

void DFS(int cnt,int i){
    if(cnt==k||i==v.size()){
        for (int i=0;i<n;i++){
            for (int j=0;j<n;j++){
                //cout<<step[i][j]<<" ";
                visit[i][j]=false;
                step[i][j]=0;
            }
           // cout<<endl;
        }
        Push(r1,c1,0);
        BFS();
        // for (int i=0;i<n;i++){
        //     for (int j=0;j<n;j++){
        //         cout<<step[i][j]<<" ";
        //        // visit[i][j]=false;
        //         //step[i][j]=0;
        //     }
        //    cout<<endl;
        // }
        if(visit[r2][c2]){
        //     for (int i=0;i<n;i++){
        //     for (int j=0;j<n;j++){
        //         cout<<step[i][j]<<" ";
        //        // visit[i][j]=false;
        //         //step[i][j]=0;
        //     }
        //    cout<<endl;
        // }
            minN = min(step[r2][c2],minN);
        }
        return;
    }

    arr[v[i].first][v[i].second]=0;
    DFS(cnt+1,i+1);
    arr[v[i].first][v[i].second]=1;

    DFS(cnt,i+1);
}

int main() {
    cin>>n>>k;

    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            cin>>arr[i][j];
            if(arr[i][j]){
                v.push_back(make_pair(i,j));
            }
        }
    }
    cin>>r1>>c1>>r2>>c2;
    r1--;c1--;r2--;c2--;

    //step[r2][c2]=-1;
    
    
     //  BFS();
    DFS(0,0);
    // for (int i=0;i<n;i++){
    //         for (int j=0;j<n;j++){
    //             cout<<step[i][j]<<" ";
    //         }
    //         cout<<endl;
    // }
    if(minN==INT_MAX){ 
        cout<<-1; 
        return 0;
    }
    cout<<minN;
    return 0;
}