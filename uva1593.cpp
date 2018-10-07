//  uva1593
//  Created on 2018/9/9
//  Check the for loop index!!
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<sstream>
#include<string>
using namespace std;
vector<string> vorder[180];
vector<string> vline[1005];
vector<int> max_len;
string s,a;
void print(const string& s,const int& format,bool end){
	cout<<s;
	if(!end){
	    for(int i = 0;i < format - s.length();i++){
                cout<<']';
    	    }
	}
    return;
}
int main(int argc, const char * argv[]) {
    int count_line =0,word_order = 0,Max_word = 0;
    //use stringstream to read input data
    while( getline(cin,a) ){
        //if(a == "quit")   break;   //for test
        
        stringstream line(a);
        word_order = 0;
        while( line>>s ){
            vline[count_line].push_back(s);
            vorder[word_order].push_back(s);
            word_order++;
        }
        count_line++;
        Max_word = max(Max_word,word_order);
    }
    //record the max len for each word order
    for(int i = 0;i < Max_word;i++){
        int Max_len = 0;
        for(int j = 0;j < vorder[i].size();j++){
            Max_len = max( Max_len , (int)vorder[i][j].length() );
        }
        max_len.push_back(Max_len);
    }
    //present the each word order
    /*
    cout<<"the Max_word is"<<Max_word<<"\n";
    for(int i = 0;i < max_len.size();i++){
        cout<<max_len[i]<<" ";
    }
    cout<<"\n";
    */
    for(int i = 0 ;i < count_line;i++){
        for(int k = 0;k < vline[i].size();k++){
            int format;
            format = max_len[k];
	    if( k == vline[i].size() -1){
	    	print(vline[i][k],format+1,1);
	    }
	    else
            	print(vline[i][k],format+1,0);
        }
        cout<<"\n";
    }
    return 0;
}


/*
 for(int i = 0;i < count_line;i++){
 for(int j = 0;j < vline[i].size();j++ ){
 cout<<vline[i][j]<<" ";
 }
 cout<<"\n";
 }
 
 for(int i = 0;i < Max_word;i++){
 for(int j = 0;j < vorder[i].size();j++){
 cout<<vorder[i][j]<<" ";
 }
 cout<<"\n";
 }
 */



