#include <iostream>
#include <queue>

using namespace std;

int n,k;
int arr[101][101];
bool visit[101][101]={};
int step[101][101];
queue<pair<int,int>> q;

bool CanGo(int x,int y){
    return (x>=0&&x<n&&y>=0&&y<n)&&!visit[x][y]&&arr[x][y];
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
                //cout<<"k";
                Push(x,y,step[curr.first][curr.second]+1);
            }   
        }
    }
}

int main() {
    cin>>n>>k;
    //vector<pair<int,int>> orig;
    vector<pair<int,int>> virus;
    
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            cin>>arr[i][j];
            // if(arr[i][j]==1){
            //     orig.push_back(make_pair(i,j));
            // }
            if(arr[i][j]==2){
                virus.push_back(make_pair(i,j));
            }
        }
    }

    for(int i=0;i<virus.size();i++){
        Push(virus[i].first,virus[i].second,0);
    }
    
    BFS();

    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            if(arr[i][j]==0){
                cout<<-1<<" ";
            }else if(arr[i][j]==1&&!visit[i][j]){
                    cout<<-2<<" ";
            }
            else{    cout<<step[i][j]<<" ";
            }
        }
        cout<<endl;
    }

    return 0;
}