//  uva1594
//  Created by Joe - GT3 on 2018/9/9.
#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<sstream>
#include<string>
using namespace std;
int main(int argc, const char * argv[]) {
    int times;
    cin>>times;
    while(times--){
        int num;
        cin>>num;
	vector<int> v;
        for(int i = 0 ;i < num;i++){
            int n;
            cin>>n;
            v.push_back(n);
        }
        int v_0 = 0,test = 0;
        for(int i = 0;i < 1000;i++){
            test = 0;
            for(int t = 0;t < v.size();t++){
                if(v[t] == 0)
                    test++;
            }
            if(test == v.size())
            {
                break;
            }
            for(int k = 0;k < v.size();k++){
                if(k == 0){
                    v_0 = v[0];
                }
                if( k == v.size() - 1 ){
                    v[k] = abs( v[k]-v_0 );
                }
                else{
                    v[k] = abs( v[k]-v[k+1] );
                }
            }
        }
        
        if(test != v.size())
        {
            cout<<"LOOP"<<"\n";
        }
        else
        {
            cout<<"ZERO"<<"\n";
        }
        
    }
    return 0;
}
 
