#include <iostream>
#include <vector>
using namespace std;

int n;
int total=0;
vector<int> v;

void Chose(int cnt){
    if(cnt == n){
        total++;
        return;
    }
    else if(cnt>n){
        return;
    }

    for (int i=1;i<=4;i++){
        for (int j=0;j<i;j++){
            v.push_back(i);
        }
        Chose(cnt+i);
        for (int j=0;j<i;j++){
            v.pop_back();
        }
    }
}
//1은 몇번이든 노상관
//2는 2번씩
//3은 3번씩
//4는 4번씩

//여기서 중요한 건 
//모든 경우의 수를 하고 검사하는 법
//가능 경우 수만 구하는 것 
int main() {
    cin>>n;
    Chose(0);
    cout<<total;
    return 0;
}