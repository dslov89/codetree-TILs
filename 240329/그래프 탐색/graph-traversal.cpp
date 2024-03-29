#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n,m;
vector<int> v[1001];
int visit[1001]={};
int total = 0;

void Dfs(int start){
    for (int i=0;i<v[start].size();i++){
        if(!visit[v[start][i]]){
            visit[v[start][i]]=1;
            total++;
            Dfs(v[start][i]);
        }
    }
    
}

int main() {
    cin>>n>>m;
    int root=1;
    for (int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
    
        v[x].push_back(y);
        v[y].push_back(x);
    }
    
    visit[1]=1;
    Dfs(root);
    cout<<total;
    return 0;
}