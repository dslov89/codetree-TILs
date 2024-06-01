#include <iostream>
#include <queue>
#include <climits>
using namespace std;

int n, h, m;
int arr[101][101];
bool visit[101][101];
int step[101][101];
vector<pair<int,int>> space;
queue<pair<int,int>> q;

bool CanGo(int x,int y){
    return (x>=0&&x<n&&y>=0&&y<n)&&!visit[x][y]&&(arr[x][y]!=1);
}

void Push(int x,int y,int s){
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

        // for(int i=0;i<m;i++){
        //     if(space[i]==curr){
        //         q = queue<pair<int,int>>();
        //         break;
        //     }
        // }

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
    cin>>n>>h>>m;
    vector<pair<int,int>> v;
    int ans[n][n]={};
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            cin>>arr[i][j];
            if(arr[i][j]==2){
                v.push_back(make_pair(i,j));
            }
            if(arr[i][j]==3){
                space.push_back(make_pair(i,j));
            }
        }
    }

    for (int i=0;i<h;i++){
        //그 전에 visit,step 초기화 해줘야 할듯 
        // visit[101][101]={};
        // step[101][101]={};

         for (int i=0;i<n;i++){
            for (int j=0;j<n;j++){
                //cout<<step[i][j]<<" ";
                step[i][j]=0;
                visit[i][j]=false;
            }
           // cout<<endl;
        }
        //cout<<endl;
        Push(v[i].first,v[i].second,0);
        BFS();

       

        int minN = INT_MAX;
        for(int i=0;i<m;i++){
            int k = step[space[i].first][space[i].second];
            //cout<<k<<endl;
            if(k>0&&k<minN){
                minN=k;
                
            }
        }
        if(minN==INT_MAX){
            minN = -1;
        }
        ans[v[i].first][v[i].second]=minN;
    }

    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }

    
    return 0;
}