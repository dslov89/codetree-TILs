#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    vector<int> v;
    int n;
    cin>>n;
    string k;
    int l;

    for (int i=0;i<n;i++){
       cin>>k;
       if(k=="push_back"){
        cin>>l;
        v.push_back(l);
       }else if(k=="pop_back"){
        v.pop_back();
       }else if(k=="size"){
        cout<<v.size()<<endl;
       }else if(k=="get"){
        cin>>l;
        cout<<v[l-1]<<endl;
       }

    }
    return 0;
}