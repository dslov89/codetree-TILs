#include <iostream>
#include <list>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    list<char> l;
    list<char>::iterator it;
    int n,m;
    cin>>n>>m;
    for (int i=0;i<n;i++){
        char k;
        cin>>k;
        l.push_back(k);
    }
    
    it = l.end();
    for (int i=0;i<m;i++){
        char k;
        cin>>k;
        if(k=='L'){
            it--;
        
        }else if(k=='R'){
            it++;
        }else if(k=='D'){
            l.erase(it);
        }else if(k=='P'){
            char h;
            cin>>h;
            l.insert(it,h);
        }
    }
    for (it = l.begin();it!=l.end();it++){
        cout<<*it;
    }
  
    return 0;
}