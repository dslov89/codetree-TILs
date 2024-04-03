#include <iostream>
#include <queue>

using namespace std;

int n,k;
int arr[100][100];
int r,c;
queue<pair<int,int>> q;
int mr,mc;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int visit[100][100]={};


void BFS(){
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
       
        for(int i=0;i<4;i++){
            int x1 = x+dx[i];
            int y1 = y+dy[i];
            
            if((x1>=0&&x1<n&&y1>=0&&y1<n)&&(arr[x1][y1]<arr[mr][mc])&&!visit[x1][y1]){
                q.push(make_pair(x1,y1));
                visit[x1][y1]=1;
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
    cin>>r>>c;
    r--;
    c--;

    q.push(make_pair(r,c));
    mr=r;
    mc=c;
    for(int i=0;i<k;i++){
        BFS();
        int maxN=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
              //  cout<<visit[i][j]<<" ";
                if(visit[i][j]){
                    if(maxN<arr[i][j]){
                        maxN=arr[i][j];
                        mr=i;
                        mc=j;
                    }
                    visit[i][j]=0;
                }
            }
          //  cout<<endl;
        }
       // cout<<"max "<<mr<<" "<<mc<<endl;
        q.push(make_pair(mr,mc));
      //visit[mr][mc]=1;
    }
    cout<<mr+1<<" "<<mc+1;

    return 0;
}
        // if(CanGo(x,y)){
        //     int maxN=0;
        //     for(int i=0;i<n;i++){
        //         for(int j=0;j<n;j++){
        //             int curr = arr[i][j];
        //             if((curr<arr[x][y])&&(maxN<curr)){
        //                     cout<<"가능 "<<i<<" "<<j<<" "<<curr<<endl;
        //                     maxN=curr;
        //                     mr=i;
        //                     mc=j;
        //             }
        //         }
        //     }
        //     q.push(make_pair(mr,mc));
        //     k--;
        // }