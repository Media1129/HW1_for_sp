//  uva1597
//  Created by Joe - GT3 on 2018/9/11.
//  確認for loop index 不要搞錯
//  每經過一組測資 要把STL tool  clear
//  string 的 substr 可以切割字串
//  考慮變數的起始狀況!! 和變數的邊界狀況
//  邊寫邊測試
#include<iostream>
#include<algorithm>
#include<sstream>
#include<utility>
#include<map>
#include<string>
#include<vector>
#include<queue>
#include<set>
#include<cstddef>
using namespace std;
void deal(string& s){
    if( isalpha( s[s.length()-1] ) ){
        return;
    }
    else
        s = s.substr(0,s.length()-1);
}
int main(int argc, const char * argv[]) {
    int docu_num = 0;
    (cin>>docu_num).get();
    //map--->   <什麼字 ,  <第幾個document,那個document中的第幾行> >
    map< string,vector< pair<int,int> > > mymap;
    //第i個document 的 第count_line行
    for(int i = 0;i < docu_num;i++){
        string str,buf;
        int count_line = 0;
        while( getline(cin,str) ){
            if(str == "**********")
                break;
            stringstream ss(str);
            //避免同一行有重複的字 被放到map 兩次
            map< string,int > check_line;
            //去除逗號 跟一些符號
            while(ss >> buf){
                if( check_line.count(buf) == 0 ){
                    deal(buf);
                    check_line[buf] = 1;
                    pair<int,int> tmp;
                    tmp = make_pair(i,count_line);
                    mymap[buf].push_back(tmp);
                }
            }
            check_line.clear();
            count_line++;
        }
        cout<<"okk----------------"<<"\n";
    }
    //present map
    for (map< string,vector< pair<int,int> > >::iterator it=mymap.begin(); it!=mymap.end(); ++it){
        for(int i = 0;i < it->second.size();i++){
            cout<<it->first<<" in "<<it->second[i].first;
            cout<<"document "<<it->second[i].second<<" line"<<"\n";
        }
    }
    cout<<"query-------"<<"\n";
    //deal query
    int qur_num = 0,cnt_qur = 0;
    (cin>>qur_num).get();
    string str,buf;
    while( getline(cin,str) ){
        stringstream ss(str);
        int cnt_word = 0;
        //事先計算一行有幾個字
        while(ss>>buf){
            cnt_word++;
        }
        //one word query
        if(cnt_word == 1){
            string one_tmp;
            stringstream one_sss(str);
            one_sss>>one_tmp;
            cout<<"one_tmp = "<<one_tmp<<"\n";
            for(int i = 0;i < mymap[one_tmp].size();i++){
                cout<<mymap[one_tmp][i].first<<" "<<mymap[one_tmp][i].second<<"\n";
            }
        }
        //NOT
        else if(cnt_word == 2){
            set<int> s;
            string not_tmp;
            stringstream not_sss(str);
            for(int g = 0;g < 2;g++)
                not_sss>>not_tmp;
            cout<<"not_tmp = "<<not_tmp<<"\n";
            for(int i = 0;i < mymap[not_tmp].size();i++){
                cout<<mymap[not_tmp][i].first<<" "<<mymap[not_tmp][i].second<<"\n";
            }
        }
        //AND or OR
        else if(cnt_word == 3){
            cout<<"AND or OR"<<"\n";
        }
        cnt_qur++;
        if(cnt_qur == qur_num)
            break;
    }
    
    
    return 0;
}





