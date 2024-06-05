#include <iostream>

using namespace std;

int n;
int total=0;

void Stair(int k){
    if(k==n){
        total++;
        return ;
    }
    else if(k>n) return ;
    
    Stair(k+2);

    Stair(k+3);
}

int main() {
    cin>>n;

    Stair(0);

    cout<<total;
    return 0;
}