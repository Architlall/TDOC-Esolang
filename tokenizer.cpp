#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <unordered_map>
int main()
{
    std::string res;
    std::unordered_map<std::string, std::string> varKey;
    std::vector<std::string> objInsert;
    varKey.insert({"in", "int"});
    varKey.insert({"ch", "char"});
    varKey.insert({"take", "scanf()"});
    varKey.insert({"st", "char[]"});
    varKey.insert({"<htpl>", "#include<stdio.h>\n int main()\n{"});
    varKey.insert({"/", "}"});
    varKey.insert({"<log>", "printf()"});
    varKey.insert({"/log", ";"});
    varKey.insert({"int", "%d"});
    varKey.insert({"char", "%c"});
    varKey.insert({"string", "%s"});

    std::ifstream readData("input.txt");
    std::unordered_map<std::string, std::pair<std::string, std::string>> varStore;
    while (getline(readData, res))
    {
        //res.erase(remove(res.begin(), res.end(), ' '), res.end());
        int cnt = 0;
        for (int i = 0; i < res.length(); i++)
        {
            if (res[i] != ' ')
            {
                break;
            }
            cnt++;
        }
        std::cout << res << "\n";
        res = res.substr(cnt, res.length() - cnt);
        if (res[0] == '<')
        {
            std::cout << res << "\n";
            std::unordered_map<std::string, std::string>::iterator it;
            if (res.substr(1, 4) == "/log")
            {
                res = "/log";
                it = varKey.find(res);
                objInsert.push_back(it->second);
            }
            else if (res[1] == '/' && res.substr(2, 3) != "log")
            {

                res = "/";
                it = varKey.find(res);
                objInsert.push_back(it->second);
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
                    objInsert.push_back(res);
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
                    objInsert.push_back(res);
                    std::cout << objInsert[objInsert.size() - 1] << "\n";
                    varStore.insert({tmp[1], {tmp[0], "NULL"}});
                    }
                    else if(tmp[0] == "take"){
                        it = varKey.find(tmp[0]);
                        res = it->second;
                        objInsert.push_back(res);
                        objInsert.push_back(tmp[1]);
                        std::cout<<objInsert[objInsert.size()-1]<<"\n";
                        std::cout<<objInsert[objInsert.size()-2]<<"\n";
                    }
                }
            }
            else
            {

                it = varKey.find(res);
                objInsert.push_back(it->second);
            }
        }
        else
        {
            if (objInsert[objInsert.size() - 1] == "printf()")
            {
                std::cout << res << "\n";
                objInsert.push_back(res);
            }
            else if (objInsert[objInsert.size() - 1] == "scanf()")
            {
                objInsert.push_back(res);
            }

            else
            {
                objInsert[objInsert.size() - 1] += res;
            }
        }
        // for(int i=0;i<objInsert.size();i++){
        //     std::cout<<objInsert[i]<<"\n";
        // }
        // for(auto it: varStore){
        //     std::cout<<it.first<<" "<<(it.second).first<<" "<<it.second.second<<"\n";
        // }
        std::unordered_map<std::string, std::pair<std::string, std::string>>::iterator itr;
        for (int i = 0; i < objInsert.size(); i++)
        {

            if (objInsert[i] == "printf()" && objInsert[i + 2] == ";")
            {

                itr = varStore.find(objInsert[i + 1]);
                if (itr != varStore.end())
                {
                    objInsert[i] = objInsert[i].substr(0, 7) + '"' + varKey.find((varKey.find(itr->second.first))->second)->second + "%c" + '"' + "," + objInsert[i + 1] + ',' + "10" + objInsert[i].substr(7, 1) + objInsert[i + 2];
                    objInsert.erase(objInsert.begin() + i + 1);
                    objInsert.erase(objInsert.begin() + i + 1);
                }
                else
                {
                    objInsert[i + 1] = '"' + objInsert[i + 1] + "%c" + '"' + ',' + "10";
                    objInsert[i] = objInsert[i].substr(0, 7) + objInsert[i + 1] + objInsert[i].substr(7, 1) + objInsert[i + 2];
                    objInsert.erase(objInsert.begin() + i + 1);
                    objInsert.erase(objInsert.begin() + i + 1);
                }
            }

            else if (objInsert[i] == "scanf()")
            {
                std::cout <<"helll"<< "\n";
                std::cout << objInsert[i+1]<< "\n";
               
                itr = varStore.find(objInsert[i + 1]);
                 std::cout << varKey.find((varKey.find(itr->second.first))->second)->second<< "\n";
                // if (itr != varStore.end())
                {
                    objInsert[i] = objInsert[i].substr(0, 6) + '"' + varKey.find((varKey.find(itr->second.first))->second)->second + '"' + "," + '&' + objInsert[i + 1]  + ')' +';' ;
                    std::cout <<objInsert[i]<< "\n";
                     objInsert.erase(objInsert.begin() + i + 1);
                   
                    
                }
            }
        }
    }
    std::ofstream writeIn("output.c");
    for (int i = 0; i < objInsert.size(); i++)
    {
        writeIn << objInsert[i] << "\n";
        //writeIn << "println('\n')"<< "\n";
    }
    writeIn.close();
    readData.close();
    return 0;
}