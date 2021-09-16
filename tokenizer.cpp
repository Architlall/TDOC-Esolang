#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include "token_dataset.hpp"
std::unordered_map<std::string, std::pair<std::string, std::string>> varStore;
std::vector<std::string> codeSnippets;
std::vector<std::string> conditionalRender;
//Generates an output C-Lang file
void ouputFileReader()
{
    std::ofstream writeIn("output.c");
    for (int i = 0; i < codeSnippets.size(); i++)
    {
        writeIn << codeSnippets[i] << "\n";
    }
    writeIn.close();
}

//Removes beginning whitespaces from each line
std::string removeWhitespace(std::string req)
{
    int cnt = 0;
    for (int i = 0; i < req.length(); i++)
    {
        if (req[i] != ' ')
        {
            break;
        }
        cnt++;
    }
    req = req.substr(cnt, req.length() - cnt);
    return req;
}

//Adjust Print statements in the vector
void printlnParserStream()
{
    dataSet();
    int switch_btn=0;
    for (int i = 0; i < codeSnippets.size(); i++)
    {

        if (codeSnippets[i] == "printf()" && codeSnippets[i + 2] == ";")
        {

            if (varStore.find(codeSnippets[i + 1]) != varStore.end())
            {
                codeSnippets[i] = codeSnippets[i].substr(0, 7) + '"' + varKey.find((varKey.find(varStore.find(codeSnippets[i + 1])->second.first))->second)->second + "%c" + '"' + "," + codeSnippets[i + 1] + ',' + "10" + codeSnippets[i].substr(7, 1) + codeSnippets[i + 2];
                codeSnippets.erase(codeSnippets.begin() + i + 1);
                codeSnippets.erase(codeSnippets.begin() + i + 1);
            }
            else
            {
                codeSnippets[i + 1] = '"' + codeSnippets[i + 1] + "%c" + '"' + ',' + "10";
                codeSnippets[i] = codeSnippets[i].substr(0, 7) + codeSnippets[i + 1] + codeSnippets[i].substr(7, 1) + codeSnippets[i + 2];
                codeSnippets.erase(codeSnippets.begin() + i + 1);
                codeSnippets.erase(codeSnippets.begin() + i + 1);
            }
        }

        else if (codeSnippets[i] == "scanf()")
        {
            {
                codeSnippets[i] = codeSnippets[i].substr(0, 6) + '"' + varKey.find((varKey.find(varStore.find(codeSnippets[i + 1])->second.first))->second)->second + '"' + "," + '&' + codeSnippets[i + 1] + ')' + ';';
                codeSnippets.erase(codeSnippets.begin() + i + 1);
            }
        }
    }
}
//Main logic resides here as this part deconstructs each line to fill in the codeSnippets
void fileVectorBuilder(std::string res)
{
    dataSet();
    if (res[0] == '<')
    {
        if (res.substr(1, 4) == "/log")
        {
            res = "/log";
            codeSnippets.push_back(varKey.find(res)->second);
        }
        else if (res[1] == '/' && res.substr(2, 3) != "log")
        {

            res = "/";
            codeSnippets.push_back(varKey.find(res)->second);
        }
        else if (res[res.length() - 1] == '>' && res[res.length() - 2] == '/')
        {

            res = res.substr(1, res.length() - 3) + " ";
            std::vector<std::string> tmp;
            std::string stf = "";
            int x = 0;

            for (int i = 0; i < res.length(); i++)
            {
                if (res[i] == '=')
                {
                    x = 1;
                    break;
                }
            }

            if (x == 1)
            {
                for (int i = 0; i < res.length(); i++)
                {
                    if (res[i] != ' ')
                    {
                        stf = stf + res[i];
                    }
                    else
                    {
                        if (stf != "=")
                        {
                            tmp.push_back(stf);
                        }
                        stf = "";
                    }
                }
                res = varKey.find(tmp[0])->second + res.substr(res.find(' '), res.length() - res.find(' ') - 1) + ';';
                codeSnippets.push_back(res);
                varStore.insert({tmp[1], {tmp[0], tmp[2]}});
            }
            else if (x == 0)
            { //for <in val/> and <take val/>

                for (int i = 0; i < res.length(); i++)
                {
                    if (res[i] != ' ')
                    {
                        stf = stf + res[i];
                    }
                    else
                    {
                        tmp.push_back(stf);
                        stf = "";
                    }
                }
                if (tmp[0] == "in" || tmp[0] == "ch")
                {
                    res = varKey.find(tmp[0])->second + res.substr(res.find(' '), res.length() - res.find(' ') - 1) + ';';
                    codeSnippets.push_back(res);
                    varStore.insert({tmp[1], {tmp[0], "NULL"}});
                }
                else if (tmp[0] == "take")
                {
                    res = varKey.find(tmp[0])->second;
                    codeSnippets.push_back(res);
                    codeSnippets.push_back(tmp[1]);
                }
            }
        }
        else
        {
            codeSnippets.push_back(varKey.find(res)->second);
        }
    }
    else
    {
        if (codeSnippets[codeSnippets.size() - 1] == "printf()")
        {
            codeSnippets.push_back(res);
        }
        else if (codeSnippets[codeSnippets.size() - 1] == "scanf()")
        {
            codeSnippets.push_back(res);
        }

        else
        {
            codeSnippets[codeSnippets.size() - 1] += res;
        }
    }
}
std::string addSpaces(std::string stf,int freq){
    for(int i=0;i<freq;i++){
        stf = "\t" + stf;
    }
    return stf;
}
void conditionalBuilder(std::string parse){
    int cnt=0,cnt2=0;
    for(int i=0;i<parse.length();i++){
        if(parse[i]=='?'){
            cnt++;
        }
        if (parse[i] == 'i' || parse[i] == 'e'){
            break;
        }
        cnt2++;
    }
    if(parse[0]!='/' && parse[parse.length()-1]!='>'){
        parse = parse.substr(cnt2,parse.length()-cnt2);
        if(parse.substr(0,2)=="if"){
            parse = parse + "{";
            parse = addSpaces(parse,cnt);
            codeSnippets.push_back(parse);
        }
        else if (parse.substr(0, 4) == "elif")
        {
            std::string sf = "else if";
            parse = sf + parse.substr(4,parse.length()-4) +"{";
            parse = addSpaces(parse,cnt);
            codeSnippets.push_back(parse);
        } else {
            parse = "else {";
            parse = addSpaces(parse,cnt);
            codeSnippets.push_back(parse);
        }
    } else {
        std::string stf = "}";
        stf = addSpaces(stf,cnt);
        codeSnippets.push_back(stf);
    }
}
int main()
{
    std::string res;
    std::ifstream readData("input.txt");
    int switch_btn = 0;
    while (getline(readData, res))
    {
        res = removeWhitespace(res);
        if(res.substr(0,2)=="<?" || res.substr(0,2)=="/?" && res[res.length()-1]=='>'){
            conditionalBuilder(res);
        } else {
            fileVectorBuilder(res);
        }
    }
    printlnParserStream();
    ouputFileReader();
    readData.close();
    return 0;
}
