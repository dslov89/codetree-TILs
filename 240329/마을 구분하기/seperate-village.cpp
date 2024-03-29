#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int arr[25][25];

int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};

int visit[25][25]={};

vector<int> v;

int cnt;

bool CanGo(int x, int y){
    if((x>=0&&x<n&&y>=0&&y<n)&&arr[x][y]&&!visit[x][y]){
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
            cnt++;
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
    
    for(int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            if(arr[i][j]&&!visit[i][j]){
                cnt=1;
                visit[i][j]=1;
                DFS(i,j);
                v.push_back(cnt);
            }
        }
    }
    
    sort(v.begin(),v.end());

    cout<<v.size()<<endl;
    for (int i=0;i<v.size();i++){
        cout<<v[i]<<endl;
    }

    return 0;
}