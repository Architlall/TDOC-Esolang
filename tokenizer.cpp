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
    varKey.insert({"st", "char[]"});
    varKey.insert({"<htpl>", "#include<stdio.h>\nint main()\n{"});
    varKey.insert({"/", "}"});
    varKey.insert({"<log>", "printf()"});
    varKey.insert({"/log", ";"});
    std::ifstream readData("input.txt");
    while (getline(readData, res))
    {
        res.erase(remove(res.begin(), res.end(), ' '), res.end());
        if (res[0] == '<')
        {
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
                objInsert.push_back(res);
            }
            else
            {
                objInsert[objInsert.size() - 1] += res;
            }
        }
    }
    for (int i = 0; i < objInsert.size(); i++)
    {
        if (objInsert[i] == "printf()" && objInsert[i + 2] == ";")
        {
            objInsert[i + 1] = '"' + objInsert[i + 1] + '"';
            objInsert[i] = objInsert[i].substr(0, 7) + objInsert[i + 1] + objInsert[i].substr(7, 1) + objInsert[i + 2];
            objInsert.erase(objInsert.begin() + i + 1);
            objInsert.erase(objInsert.begin() + i + 1);
        }
    }
    std::ofstream writeIn("output.c");
    for (int i = 0; i < objInsert.size(); i++)
    {
        writeIn << objInsert[i] << "\n";
    }
    writeIn.close();
    readData.close();
    return 0;
}