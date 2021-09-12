#include<iostream>
#include<fstream>
#include<algorithm>
#include<vector>
#define ln(x)   x.length()
#define ID  "IDENTIFIER"
#define ST  "STRING_LITERAL"
#define NUM "NUMBER_LITERAL"
#define FX  "FUNC_VAR"
using namespace std;
int main(){
    string res;
    vector<pair<string,string>> snip;
    vector<string> snippets;
    ifstream read("hello.txt");
    while(getline(read,res)){
        res.erase(remove(res.begin(), res.end(), ' '), res.end());
        if(res[0]=='<'){
            if(res.substr(1,ln(res)-2)=="htpl"){
                 snippets.push_back("#include<stdio.h>");
                 snippets.push_back("int main()");
                 snippets.push_back("{");
            } else if(res.substr(1,3)=="log"){
                snippets.push_back("printf()");
            } else if(res=="</log>"){
                snippets.push_back(";");
            } else if(res[1]=='/'){
                snippets.push_back("}");
            }
        } else {
             if (snippets[snippets.size() - 1]!="printf()"){
                 snippets[snippets.size() - 1] += res;
             } else {
                 snippets.push_back(res);
             }
        } 
    }
    for(int i=0;i<snippets.size();i++){
        if(snippets[i]=="printf()" && snippets[i+2]==";"){
            snippets[i+1] = '"' + snippets[i+1] + '"';
            snippets[i] = snippets[i].substr(0,7) + snippets[i+1] + snippets[i].substr(7,1) + snippets[i+2];
            snippets.erase(snippets.begin()+i+1);
            snippets.erase(snippets.begin()+i+1);
        }
    }
    ofstream writein("output.c");
    for(int i=0;i<snippets.size();i++){
        writein<<snippets[i]<<endl;
    }
    read.close();
    return 0;
}