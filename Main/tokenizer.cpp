#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <unordered_map>
std::unordered_map<std::string, std::pair<std::string, std::string>> varStore;
std::vector<std::string> codeSnippets;
std::vector<std::string> conditionalRender;
std::unordered_map<std::string, std::string> varKey;
std::unordered_map<std::string, std::string> variable_DataMapper;
std::vector<std::string> function_Signatures;
void dataSet()
{
    varKey.insert({"in", "int"});
    varKey.insert({"ch", "char"});
    varKey.insert({"st", "char[]"});
    varKey.insert({"<htpl>", "#include<stdio.h>\n"});
    varKey.insert({"<main>", "int main()\n{"});
    varKey.insert({"take", "scanf()"});
    varKey.insert({"/", "}"});
    varKey.insert({"<log>", "printf()"});
    varKey.insert({"/log", ";"});
    varKey.insert({"int", "%d"});
    varKey.insert({"char", "%c"});
    varKey.insert({"string", "%s"});
}
//Generates an output C-Lang file
void ouputFileReader()
{
    std::ofstream writeIn("output.c");
    for (int i = 0; i < codeSnippets.size(); i++)
    {
        writeIn << codeSnippets[i] << "\n";
        if (i == 0)
        {
            for (int j = 0; j < function_Signatures.size(); j++)
            {
                writeIn << (function_Signatures[j] + ";") << "\n";
            }
        }
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
    int switch_btn = 0;
    for (int i = 0; i < codeSnippets.size(); i++)
    {
        if (codeSnippets[i] == "printf()" && (codeSnippets[i + 2][0] == ';'))
        {
            int pos;
            std::string formatSpecifiers = "", varNames = "";
            for (int j = 0; j < codeSnippets[i + 1].size(); j++)
            {
                if (codeSnippets[i + 1].substr(j, 2) == "${")
                {
                    pos = codeSnippets[i + 1].substr(j).find('}') + j;
                    std::string varname = codeSnippets[i + 1].substr(j + 2, pos - (j + 2));
                    if (variable_DataMapper.find(varname) != variable_DataMapper.end())
                    {
                        formatSpecifiers += varKey.find((varKey.find(variable_DataMapper.find(varname)->second))->second)->second;
                        varNames += ((varNames == "") ? "" : ",") + varname;
                    }
                    else
                    {
                        formatSpecifiers += codeSnippets[i + 1].substr(j, pos - j + 1);
                    }
                    j = pos;
                }
                else
                {
                    formatSpecifiers += codeSnippets[i + 1][j];
                }
            }
            codeSnippets[i] = codeSnippets[i].substr(0, 7) + '"' + formatSpecifiers + '"' + ((varNames == "") ? "" : ",") + varNames + codeSnippets[i].substr(7, 1) + codeSnippets[i + 2];
            codeSnippets.erase(codeSnippets.begin() + i + 1);
            codeSnippets.erase(codeSnippets.begin() + i + 1);
        }

        else if (codeSnippets[i] == "scanf()")
        {
            std::string varname = "", varNames = "", formatSpecifier = "";
            codeSnippets[i + 1] += ' ';
            for (int j = 0; j < codeSnippets[i + 1].size(); j++)
            {

                if ((codeSnippets[i + 1][j] != ',') && (codeSnippets[i + 1][j] != ' '))
                {
                    varname += codeSnippets[i + 1][j];
                }
                else
                {
                    formatSpecifier += varKey.find((varKey.find(variable_DataMapper.find(varname)->second))->second)->second + " ";
                    varname = "&" + varname;
                    varNames += ((varNames == "") ? "" : ",") + varname;
                    varname = "";
                }
            }
            formatSpecifier = formatSpecifier.substr(0, formatSpecifier.length() - 1);
            codeSnippets[i] = codeSnippets[i].substr(0, 6) + '"' + formatSpecifier + '"' + "," + varNames + ')' + ';';
            codeSnippets.erase(codeSnippets.begin() + i + 1);
        }
    }
}
//Main logic resides here as this part deconstructs each line to fill in the codeSnippets
void fileVectorBuilder(std::string res)
{
    dataSet();
    if (res[0] == '<')
    {
        if (res == "<main>")
        {
            codeSnippets.push_back(varKey.find("<main>")->second);
        }
        else if (res.substr(1, 2) == "fx")
        {
            std::string stf = "";
            std::string string_builder = "";
            int pos = res.find('x');
            res = res.substr(pos + 1, res.length() - pos - 1);
            if (res[res.length() - 1] == '>' && res[res.length() - 2] == '/')
            {
                res = res.substr(0, res.length() - 2);
                for (int i = 0; i < res.length(); i++)
                {
                    if (res[i] == '(' || res[i] == ')' || res[i] == ',')
                    {
                        string_builder = string_builder + ' ' + res[i] + ' ';
                    }
                    else
                    {
                        string_builder += res[i];
                    }
                }
                res = ' ' + string_builder;
                string_builder = "";
                for (int i = 0; i < res.length(); i++)
                {
                    if (res[i] != ' ')
                    {
                        string_builder += res[i];
                    }
                    else
                    {
                        if (string_builder == "in" || string_builder == "ch")
                        {
                            stf += varKey.find(string_builder)->second + ' ';
                        }
                        else if (string_builder == "void")
                        {
                            stf += string_builder + ' ';
                        }
                        else
                        {
                            stf += string_builder;
                        }
                        string_builder = "";
                    }
                }
                stf += ";";
                codeSnippets.push_back(stf);
            }
            else
            {
                //std::cout << res << '\n';
                res = res.substr(0, res.find('>'));
                for (int i = 0; i < res.length(); i++)
                {
                    if (res[i] == '(' || res[i] == ')' || res[i] == ',')
                    {
                        string_builder = string_builder + ' ' + res[i] + ' ';
                    }
                    else
                    {
                        string_builder += res[i];
                    }
                }
                res = string_builder;
                //std::cout << res << '\n';
                //std::cout << res << '\n';
                string_builder = "";
                for (int i = 0; i < res.length(); i++)
                {
                    if (res[i] != ' ')
                    {
                        string_builder += res[i];
                    }
                    else
                    {
                        if (string_builder == "in" || string_builder == "ch")
                        {
                            stf += varKey.find(string_builder)->second + ' ';
                        }
                        else if (string_builder == "void")
                        {
                            stf += string_builder + ' ';
                        }
                        else
                        {
                            stf += string_builder;
                        }
                        string_builder = "";
                    }
                }
                function_Signatures.push_back(stf);
                stf += "{";
                codeSnippets.push_back(stf);
            }
            // std::cout << res << "\n";
        }
        else if (res.substr(1, 5) == "throw")
        {
            // std::cout << res[7] << "\n";
            // std::cout << "whoaaa" << "\n";
            std::string stf = "";
            std::string tmp = "";
            for (int i = 7; i < res.length(); i++)
            {

                if (res[i] == '/')
                    break;
                tmp = tmp + res[i];
            }
            stf = stf + "return " + tmp + ';';
            codeSnippets.push_back(stf);
        }

        else if (res != "<log>" && (res.substr(0, 5) == "<log>" && (res.substr(5, res.length() - 5)).substr((res.substr(5, res.length() - 5)).length() - 6, 6) == "</log>"))
        {
            codeSnippets.push_back(varKey.find("<log>")->second);
            int pos1 = res.find('>');
            std::string instant_var = res.substr(pos1 + 1, res.length() - pos1 - 7);
            codeSnippets.push_back(instant_var);
            codeSnippets.push_back(";");
        }
        else if (res.substr(1, 4) == "/log")
        {
            res = "/log";
            codeSnippets.push_back(varKey.find(res)->second);
        }
        else if (res == "</htpl>")
        {
            std::cout << " " << "\n";
        }
        else if (res[1] == '/' && res.substr(2, 3) != "log")
        {
            res = "/";
            codeSnippets.push_back(varKey.find(res)->second);
        }
        else if (res[1] == '%')
        {
            std::vector<std::string> tmp;
            std::string stf = "";
            for (int i = 2; i < res.length() - 1; i++)
            {
                if (res[i] != '%')
                {
                    stf = stf + res[i];
                }
                else
                {
                    break;
                }
            }
            stf = stf + ';';
            codeSnippets.push_back(stf);
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
                std::string helper_string = "";
                std::vector<int> comma_separators;
                for (int i = 0; i < res.length(); i++)
                {
                    if (res[i] == '=')
                    {
                        helper_string += ' ';
                        helper_string += res[i];
                        helper_string += ' ';
                    }
                    else
                    {
                        helper_string += res[i];
                    }
                    if (helper_string == "in" || helper_string == "ch")
                    {
                        helper_string += ' ';
                    }
                }
                res = helper_string;
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
                    std::string help_string = "";
                    std::vector<std::string> ins_vector;
                    for (int i = 0; i < res.length(); i++)
                    {
                        if ((res[i] >= 'a' && res[i] <= 'z') || (res[i] >= 'A' && res[i] <= 'Z') || (res[i] >= '0' && res[i] <= '9'))
                        {
                            help_string += res[i];
                        }
                        else
                        {
                            ins_vector.push_back(help_string);
                            help_string = "";
                        }
                    }
                    std::string stf;
                    for (auto it : varKey)
                    {
                        if (it.second == ins_vector[0])
                        {
                            stf = it.first;
                            break;
                        }
                    }
                    for (int i = 1; i < ins_vector.size(); i++)
                    {
                        variable_DataMapper.insert({ins_vector[i], stf});
                    }
                }
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
                    std::string help_string = "";
                    std::vector<std::string> ins_vector;
                    for (int i = 0; i < res.length(); i++)
                    {
                        if ((res[i] >= 'a' && res[i] <= 'z') || (res[i] >= 'A' && res[i] <= 'Z') || (res[i] >= '0' && res[i] <= '9'))
                        {
                            help_string += res[i];
                        }
                        else
                        {
                            ins_vector.push_back(help_string);
                            help_string = "";
                        }
                    }
                    std::string stf;
                    for (auto it : varKey)
                    {
                        if (it.second == ins_vector[0])
                        {
                            stf = it.first;
                            break;
                        }
                    }
                    for (int i = 1; i < ins_vector.size(); i++)
                    {
                        variable_DataMapper.insert({ins_vector[i], stf});
                    }
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
std::string addSpaces(std::string stf, int freq)
{
    for (int i = 0; i < freq; i++)
    {
        stf = "\t" + stf;
    }
    return stf;
}
void conditionalBuilder(std::string parse)
{
    int cnt = 0, cnt2 = 0;
    for (int i = 0; i < parse.length(); i++)
    {
        if (parse[i] == '?')
        {
            cnt++;
        }
        if (parse[i] == 'i' || parse[i] == 'e')
        {
            break;
        }
        cnt2++;
    }
    if (parse[parse.length() - 1] != '>')
    {
        parse = parse.substr(cnt2, parse.length() - cnt2);
        if (parse.substr(0, 2) == "if")
        {
            parse = parse + "{";
            parse = addSpaces(parse, cnt);
            codeSnippets.push_back(parse);
        }
        else if (parse.substr(0, 4) == "elif")
        {
            std::string sf = "else if";
            parse = sf + parse.substr(4, parse.length() - 4) + "{";
            parse = addSpaces(parse, cnt);
            codeSnippets.push_back(parse);
        }
        else
        {
            parse = "else {";
            parse = addSpaces(parse, cnt);
            codeSnippets.push_back(parse);
        }
    }
    else
    {
        std::string stf = "}";
        stf = addSpaces(stf, cnt);
        codeSnippets.push_back(stf);
    }
}
void loopBuilders(std::string parse)
{
    int cnt = 0, cnt2 = 0;
    for (int i = 0; i < parse.length(); i++)
    {
        if (parse[i] == '#')
        {
            cnt++;
        }
        if (parse[i] == 'f' || parse[i] == 'w')
        {
            break;
        }
        cnt2++;
    }
    if (parse[parse.length() - 1] != '>')
    {
        parse = parse.substr(cnt2, parse.length() - cnt2);
        if (parse[0] == 'f')
        {
            for (int i = 1; i < parse.length(); i++)
            {
                if (parse[i] == ',')
                {
                    parse[i] = ';';
                }
            }
            parse = "for" + parse.substr(1, parse.length() - 1) + "{";
            parse = addSpaces(parse, cnt);
            codeSnippets.push_back(parse);
        }
        else if (parse[0] == 'w')
        {
            parse = "while" + parse.substr(1, parse.length() - 1) + "{";
            parse = addSpaces(parse, cnt);
            codeSnippets.push_back(parse);
        }
    }
    else
    {
        std::string stf = "}";
        stf = addSpaces(stf, cnt);
        codeSnippets.push_back(stf);
    }
}
int main(int argc, char const *argv[])
{
    std::string res;
    std::ifstream readData(argv[1]);
    int switch_btn = 0;
    while (getline(readData, res))
    {
        res = removeWhitespace(res);
        if (res.length() == 0)
        {
            continue;
        }
        else if (res.substr(0, 2) == "<?" || res.substr(res.length() - 2, 2) == "?>")
        {
            conditionalBuilder(res);
        }
        else if (res.substr(0, 2) == "<#" || res.substr(res.length() - 2, 2) == "#>")
        {
            loopBuilders(res);
        }
        else
        {
            fileVectorBuilder(res);
        }
    }
    printlnParserStream();
    ouputFileReader();
    readData.close();
    return 0;
}
