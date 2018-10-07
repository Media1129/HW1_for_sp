//  uva10763
//  Created by Joe - GT3 on 2018/9/10.
//  確認for loop index 不要搞錯
//  每經過一組測資 要把STL tool  clear

#include<iostream>
#include<utility>
#include<map>
using namespace std;

int main(int argc, const char * argv[]) {
    int n;
    while( cin>>n && n ){
        //insert data to map
        map< pair<int,int>,int > mymap;
        for(int i = 0;i < n;i++ ){
            int a,b;
            cin>>a>>b;
            pair<int,int> insert;
            if(a > b){
                insert = make_pair(a, b);
            }
            else{
                insert = make_pair(b, a);
            }
            if( mymap.count(insert) != 0 ){
                if(a > b){
                    mymap[insert]++;
                }
                else{
                    mymap[insert]--;
                }
            }
            else{
                if(a > b){
                    mymap[insert] =  1;
                }
                else{
                    mymap[insert] = -1;
                }
            }
        }
        //present
        int cnt = 0;
        for ( map< pair<int,int> ,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it){
            if( it->second  != 0){
                break;
            }
            cnt++;
        }
        if(cnt == mymap.size()){
            cout<<"YES"<<"\n";
        }
        else{
            cout<<"NO"<<"\n";
        }
    }
    
    
    return 0;
}
