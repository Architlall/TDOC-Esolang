#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include "token_dataset.hpp"
std::unordered_map<std::string, std::pair<std::string, std::string>> varStore;
std::vector<std::string> codeSnippets;
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
std::string removeWhitespace(std::string req){
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
    std::unordered_map<std::string, std::pair<std::string, std::string>>::iterator itr;
    for (int i = 0; i < codeSnippets.size(); i++)
        {

            if (codeSnippets[i] == "printf()" && codeSnippets[i + 2] == ";")
            {

                itr = varStore.find(codeSnippets[i + 1]);
                if (itr != varStore.end())
                {
                    codeSnippets[i] = codeSnippets[i].substr(0, 7) + '"' + varKey.find((varKey.find(itr->second.first))->second)->second + "%c" + '"' + "," + codeSnippets[i + 1] + ',' + "10" + codeSnippets[i].substr(7, 1) + codeSnippets[i + 2];
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
                std::cout <<"helll"<< "\n";
                std::cout << codeSnippets[i+1]<< "\n";
               
                itr = varStore.find(codeSnippets[i + 1]);
                 std::cout << varKey.find((varKey.find(itr->second.first))->second)->second<< "\n";
                // if (itr != varStore.end())
                {
                    codeSnippets[i] = codeSnippets[i].substr(0, 6) + '"' + varKey.find((varKey.find(itr->second.first))->second)->second + '"' + "," + '&' + codeSnippets[i + 1]  + ')' +';' ;
                    std::cout <<codeSnippets[i]<< "\n";
                     codeSnippets.erase(codeSnippets.begin() + i + 1);
                   
                    
                }
            }
        }
}
//Main logic resides here as this part deconstructs each line to fill in the codeSnippets
void fileVectorBuilder(std::string res)
{
    dataSet();
    res = removeWhitespace(res);
     if (res[0] == '<')
        {
            std::cout << res << "\n";
            std::unordered_map<std::string, std::string>::iterator it;
            if (res.substr(1, 4) == "/log")
            {
                res = "/log";
                it = varKey.find(res);
                codeSnippets.push_back(it->second);
            }
            else if (res[1] == '/' && res.substr(2, 3) != "log")
            {

                res = "/";
                it = varKey.find(res);
                codeSnippets.push_back(it->second);
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

                    it = varKey.find(tmp[0]);
                    res = it->second + res.substr(res.find(' '), res.length() - res.find(' ') - 1) + ';';
                    std::cout << res << "\n";
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
                    if (tmp[0] == "in" || tmp[0] == "ch"){
                    it = varKey.find(tmp[0]);
                    // res = it->second + ' ' + tmp[1] + ';';
                    res = it->second + res.substr(res.find(' '), res.length() - res.find(' ') - 1) + ';';
                    std::cout << res[0] << "\n";
                    codeSnippets.push_back(res);
                    std::cout << codeSnippets[codeSnippets.size() - 1] << "\n";
                    varStore.insert({tmp[1], {tmp[0], "NULL"}});
                    }
                    else if(tmp[0] == "take"){
                        it = varKey.find(tmp[0]);
                        res = it->second;
                        codeSnippets.push_back(res);
                        codeSnippets.push_back(tmp[1]);
                        std::cout<<codeSnippets[codeSnippets.size()-1]<<"\n";
                        std::cout<<codeSnippets[codeSnippets.size()-2]<<"\n";
                    }
                }
            }
            else
            {

                it = varKey.find(res);
                codeSnippets.push_back(it->second);
            }
        }
        else
        {
            if (codeSnippets[codeSnippets.size() - 1] == "printf()")
            {
                std::cout << res << "\n";
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
int main()
{
    std::string res;
    std::ifstream readData("input.txt");
    while (getline(readData, res))
    {
        fileVectorBuilder(res);
    }
    printlnParserStream();
    ouputFileReader();
    readData.close();
    return 0;
}





