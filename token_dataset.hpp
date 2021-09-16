//Holds preset key-value pairs for reading and inserting appropriate snippets of code needed.
#include <unordered_map>
std::unordered_map<std::string, std::string> varKey;
void dataSet()
{
    varKey.insert({"in", "int"});
    varKey.insert({"ch", "char"});
    varKey.insert({"st", "char[]"});
    varKey.insert({"<htpl>", "#include<stdio.h>\nint main()\n{"});
    varKey.insert({"take", "scanf()"});
    varKey.insert({"/", "}"});
    varKey.insert({"<log>", "printf()"});
    varKey.insert({"/log", ";"});
    varKey.insert({"int", "%d"});
    varKey.insert({"char", "%c"});
    varKey.insert({"string", "%s"});
}