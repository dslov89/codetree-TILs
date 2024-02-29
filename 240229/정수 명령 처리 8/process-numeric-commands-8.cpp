#include <iostream>
#include <list>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin>>n;
    list<int> l;
    for (int i=0;i<n;i++){
        string k;
        cin>>k;
        if(k=="push_back"){
            int j;
            cin>>j;
            l.push_back(j);
            
        }else if(k=="push_front"){
            int j;
            cin>>j;
            l.push_front(j);
        }else if(k=="pop_front"){
            cout<<l.front()<<endl;
            l.pop_front();
        }else if(k=="pop_back"){
            cout<<l.back()<<endl;
            l.pop_back();
        }else if(k=="size"){
            cout<<l.size()<<endl;
        }else if(k=="empty"){
            cout<<l.empty()<<endl;
        }else if(k=="front"){
            cout<<l.front()<<endl;
        }else if(k=="back"){
            cout<<l.back()<<endl;
        }
    }


    return 0;
}