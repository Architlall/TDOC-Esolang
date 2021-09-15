#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include "token_dataset.hpp"
std::unordered_map<std::string, std::pair<std::string, std::string>> varStore;
std::vector<std::string> codeSnippets;
using std::cout;
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
        //fills the println statment with required result
        if (codeSnippets[i] == "printf()" && (codeSnippets[i + 2] == ";" || codeSnippets[i+3] == ";"))
        { // if its comma seperated then i+3 will be ; not i+2
            if(codeSnippets[i+1][0] != '$') goto string_mode; 
            // $ means its a variable if not then treat as a string

            itr = varStore.find(codeSnippets[i + 1].substr(1)); // the dollar from the variable name needs to be removed as actual name doesnt contain a dollar
            //Deconstructs the print statements to be inserted
            if (itr != varStore.end())
            {
                //For variable types like e.g println("%d",var_name);
                codeSnippets[i] = codeSnippets[i].substr(0, 7) + '"' + varKey.find((varKey.find(itr->second.first))->second)->second + "%c" + '"' + "," + codeSnippets[i + 1].substr(1) + ',' + ((codeSnippets[i+2] == ",")? "32":"10") + codeSnippets[i].substr(7, 1) + ((codeSnippets[i+2] == ",")? codeSnippets[i+3]:codeSnippets[i+2]);
                codeSnippets.erase(codeSnippets.begin() + i + 1);
                codeSnippets.erase(codeSnippets.begin() + i + 1);
            }
            else
            {   string_mode:
                //For variable types like e.g println("_raw_print_");
                codeSnippets[i + 1] = '"' + codeSnippets[i + 1] + "%c" + '"' + ',' + ((codeSnippets[i+2] == ",")? "32":"10");
                codeSnippets[i] = codeSnippets[i].substr(0, 7) + codeSnippets[i + 1] + codeSnippets[i].substr(7, 1) + ((codeSnippets[i+2] == ",")? codeSnippets[i+3]:codeSnippets[i+2]);
                codeSnippets.erase(codeSnippets.begin() + i + 1);
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
        //Searchs for an item by substring and injects it in vectorStream
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
        else
        {
            codeSnippets.push_back(varKey.find(res)->second);
        }
    }
    else
    {
        if (codeSnippets[codeSnippets.size() - 1] == "printf()")
        {
            int firstTime=1;
            int commaEncountered=0;
            std::string tmp="";
            for(int i=0;res[i]!=0;i++)
            {
                if(res[i] == ',')
                {  
                    commaEncountered=1;
                    if(!firstTime)
                    {
                        codeSnippets.push_back("printf()");
                        // this step has been done because for the first time the printf statement check in the previous if makes sure there is a printf before this but thats not the case for all comma seperated values
                    }
                    firstTime=0;
                    codeSnippets.push_back(tmp);
                    codeSnippets.push_back(","); // this step is necessarry as when there is a comma it needs to be space seperated not \n
                    codeSnippets.push_back(";");
                    cout<<tmp<<"\n";
                    
                    tmp="";
                }
                else
                {
                tmp+=res.substr(i,1);
                }
            }
            if(commaEncountered)
            {
            codeSnippets.push_back("printf()");
            codeSnippets.push_back(tmp); // this codeblock doesnt need a ; because the last </log> takes care of the ;
            commaEncountered=0; // to make it functional for a recheck of comma in the input
            }
            else
            {
                codeSnippets.push_back(tmp);
            }

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
    std::ifstream readData("input.htpl");
    while (getline(readData, res))
    {
        fileVectorBuilder(res);
    }
    printlnParserStream();
    ouputFileReader();
    readData.close();
    return 0;
}