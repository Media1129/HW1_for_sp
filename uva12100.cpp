//  uva12100
//  Created by Joe - GT3 on 2018/9/10.
//  確認for loop index 不要搞錯
//  每經過一組測資 要把STL tool  clear
//  string 的 substr 可以切割字串
#include<iostream>
#include<algorithm>
#include<map>
#include<string>
#include<vector>
#include<queue>
using namespace std;
struct point{
    int pos,priority;
};
bool complare(int a,int b)

{
    
    return a>b;
    
}
int main(int argc, const char * argv[]) {
    int times;
    cin>>times;
    while(times--){
        int n,ans_pos,prio;
        queue<point> q;
        vector<int> order;
        cin>>n;
        cin>>ans_pos;
        for(int i = 0;i < n;i++){
            point tmp;
            cin>>prio;
            tmp.pos = i;
            tmp.priority = prio;
            q.push(tmp);
            order.push_back(prio);
        }
        sort(order.begin(),order.end(),complare);
        int vshift = 0;
        
        while(1){
            if(q.front().priority == order[vshift]){
                vshift++;
                if(q.front().pos == ans_pos){
                    break;
                }
                q.pop();
            }
            else{
                q.push(q.front());
                q.pop();
            }
        }
        cout<<vshift<<"\n";
        
    }
    
    return 0;
}
/*
 int q_size = (int)q.size();
 for(int i = 0;i < q_size;i++ ){
 cout<<q.front().pos<<" "<<q.front().priority<<"\n";
 q.pop();
 }
 
 for(int i = 0;i < order.size();i++ ){
 cout<<order[i]<<" ";
 }
 */
