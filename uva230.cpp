//  uva230
//  Created by Joe - GT3 on 2018/9/10.
//  確認for loop index 不要搞錯
//  每經過一組測資 要把STL tool  clear
//  string 的 substr 可以切割字串
//  考慮變數的起始狀況!! 和變數的邊界狀況
//  邊寫邊測試
#include<iostream>
#include<algorithm>
#include<map>
#include<string>
#include<vector>
#include<queue>
#include<cstddef>
using namespace std;
struct book{
    string aut,tit;
};
int compare(const book& s1,const book& s2){
    if(s1.aut != s2.aut)
        return s1.aut < s2.aut;
    else
        return s1.tit < s2.tit;
}
int main(int argc, const char * argv[]) {
    string str,title,author;
    map<string,int> is_on;
    vector<book> order;
    while( getline(cin,str) ){
        //read data
        book tmp;
        if(str == "END")
            break;
        size_t init =str.find_last_of("\"");
        title = str.substr(1,init-1);
        author = str.substr(init+5,str.length()-init-6);
        tmp.tit = title;
        tmp.aut = author;
        //put to stl tool
        is_on[tmp.tit] = 1;
        order.push_back(tmp);
    }
    sort(order.begin(),order.end(),compare);
    //cout<<"\n"<<"---check sort------"<<"\n";
    //for(int i = 0;i < order.size();i++){
        //cout<<order[i].aut<<" "<<order[i].tit<<"\n";
    //}
    //cout<<"\n"<<"----check map--------"<<"\n";
    //for (map<string,int>::iterator it=is_on.begin(); it!=is_on.end(); ++it)
      //  cout << it->first << " => " << it->second << '\n';
    
    //cout<<"\n"<<"----input cmd--"<<"\n";
    string cmd;
    
    while( getline(cin,str) ){
        if(str == "END")
            break;
        cmd = str.substr(0,6);
        
        if(cmd == "BORROW"){
            //cout<<"str = "<<str<<"\n";
            //cout<<"str.length()-9 = "<<(str.length() - 9)<<"\n";
            title = str.substr(8,str.length()-9);
            //cout<<"title = "<<title<<"\n";
            if(is_on.count(title) !=0){
                is_on[title] = 0;
                //cout<<"BORROW"<<"\n";
            }
            //else
                //cout<<"error--in borrow---"<<"\n";
            //for (map<string,int>::iterator it=is_on.begin(); it!=is_on.end(); ++it)
                //cout << it->first << " => " << it->second << '\n';
        }
        else if(cmd == "RETURN"){
            //cout<<"str = "<<str<<"\n";
            //cout<<"str.length()-9 = "<<(str.length() - 9)<<"\n";
            title = str.substr(8,str.length()-9);
            //cout<<"title = "<<title<<"\n";
            if(is_on.count(title) != 0){
                is_on[title] = -1;
                //cout<<"RETURN"<<"\n";
            }
            //else
                //cout<<"error---in return--"<<"\n";
            //for (map<string,int>::iterator it=is_on.begin(); it!=is_on.end(); ++it)
                //cout << it->first << " => " << it->second << '\n';
        }
        else if(cmd == "SHELVE"){
            //cout<<"SHELVE"<<"\n";
            int before = -1;
            for(int i = 0;i < order.size();i++ ){
                if( is_on[ order[i].tit ] == -1 ){
                    is_on[ order[i].tit ] = 1;
                    if( before == -1 )
                        cout<<"Put \""<<order[i].tit<<"\" first"<<"\n";
                    else
                        cout<<"Put \""<<order[i].tit<<"\" after \""<<order[before].tit<<"\"\n";
                }
                if( is_on[ order[i].tit ] == 1){
                    before = i;
                }
            }
	    cout<<"END"<<"\n";            
            
            //for (map<string,int>::iterator it=is_on.begin(); it!=is_on.end(); ++it)
                //cout << it->first << " => " << it->second << '\n';
        }
        //else{
            //cout<<"error---the last----"<<"\n";
            //cout<<"str = "<<str<<"\n";
            //cout<<cmd<<"\n";
        //}
    }
    
    return 0;
}
