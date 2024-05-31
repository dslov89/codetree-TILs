#include <iostream>
#include <queue>

using namespace std;
queue<pair<int,int>> q;
bool visit[101][101]={};
int step[101][101];
    
int n;
int fr,fc,lr,lc;

bool CanGo(int x,int y){
    return (x>=0&&x<n&&y>=0&&y<n)&&!visit[x][y];
}

void Push(int x, int y ,int s){
    q.push(make_pair(x,y));
    visit[x][y]=true;
    step[x][y]=s;
}

void BFS(){
    int dx[8]={1,2,2,1,-1,-2,-2,-1};
    int dy[8]={-2,-1,1,2,2,1,-1,-2};
    while(!q.empty()){
        pair<int,int> curr= q.front();
        //cout<<curr.first+1<<" "<<curr.second+1<<endl;
        q.pop();
        if(curr.first==lr&&curr.second==lc){
            break;
        }

        for (int i=0;i<8;i++){
            int x = curr.first+dx[i];
            int y = curr.second+dy[i];
            if(CanGo(x,y)){
                Push(x,y,step[curr.first][curr.second]+1);
            }

        }
    }
}

int main() {

    cin>>n;

    cin>>fr>>fc>>lr>>lc;
    fr--;
    fc--;
    lr--;
    lc--;
    step[lr][lc]=-1;

    Push(fr,fc,0);

    BFS();

    cout<<step[lr][lc];
    return 0;
}