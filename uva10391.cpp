//  uva10391
//  Created by Joe - GT3 on 2018/9/10.
//  確認for loop index 不要搞錯
//  每經過一組測資 要把STL tool  clear
//  string 的 substr 可以切割字串
#include<iostream>
#include<utility>
#include<map>
#include<string>
#include<vector>
using namespace std;
map<string,int> dic;
vector<string> words;
void find(const string& s){
    for(int i = 1;i < s.length();i++ ){
        string s1,s2;
        s1 = s.substr(0,i);
        s2 = s.substr(i,s.length()-i);
        //cout<<s1<<"]"<<s2<<"\n";
        if( dic.count(s1) != 0 && dic.count(s2) != 0){
            cout<<s<<"\n";
            return ;
        }
    }
    return;
}
int main(int argc, const char * argv[]) {
    string str;
    while( cin>>str ){
        //if(str == "quit")
          //  break;
        dic[str] = 1;
        words.push_back(str);
    }
    string s;
    for(int i = 0;i < words.size();i++){
        s = words[i];
        find(s);
    }
    
    
    return 0;
}











