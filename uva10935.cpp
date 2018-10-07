//  uva10935
//  Created by Joe - GT3 on 2018/9/10.
#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int main(int argc, const char * argv[]) {
    int n;
    while(cin>>n && n){
        queue<int> q;
        vector<int> ans;
        int end;
        for(int i = 0;i < n;i++){
            q.push(i+1);
        }
        while( q.size() >=2 ){
            ans.push_back( q.front() );
            q.pop();
            end = q.front();
            q.pop();
            q.push(end);
        }
        cout<<"Discarded cards:";
        if( ans.size() != 0)
            cout<<" ";
        for(int i = 0;i < ans.size();i++){ 
            if(i != ans.size()-1 )
                cout<<ans[i]<<", ";
            else
                cout<<ans[i];
        }
        cout<<"\n";
        cout<<"Remaining card: "<<q.front()<<"\n";
    }
    
    return 0;
}
