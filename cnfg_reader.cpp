//
// Created by IT-Unterrichtsraum on 31.05.2022.
//
#include "cnfg_reader.h"



string rsc(string file_name,string path,string einheit)
{
    ifstream input;
    input.open(file_name,ios::in);
    string paths [2];
    size_t lol = path.find('.');
    if(lol != string::npos) {
        paths[0] = path.substr(0, lol);
        paths[1] = path.substr(lol + 1, path.length());
    }
    else {
        paths[0] = path;
        paths[1] = "";
    }
    if(!input)
        return "";
    int line = 0;
    string lines[23];
    string liner;
    string g;

    while(getline(input,g))
    {
        lines[line] = g;
        line++;
    }

    int pos_y = -1;
    int pos_x = -1;
    for (int i = 0; i < sizeof(lines);i++)
    {
        size_t index = lines[i].find(paths[0]);
        if(index != string::npos ) {
            pos_x = index + paths[0].length();
            pos_y = i;
            break;
        }
    }
    if(pos_y == -1)
        return "error";

    if(paths[1].length() > 0)
    {
        int changed = 0;
        for (int i = pos_y + 1; i < sizeof(lines);i++)
        {
            if(lines[i].find("            ") != string::npos) {
                size_t index = lines[i].find(paths[1]);
                if (index != string::npos) {
                    pos_x = index + paths[1].length();
                    pos_y = i;
                    changed = 1;
                    break;
                }
            }
            else
            {
                return "0";
            }

        }
        if(changed == 0)
            return "-1";
    }
    string part = lines[pos_y].substr(pos_x + 3,lines[pos_y].length() - pos_x);
    if(einheit != "") {
        size_t  value_end = part.find(einheit);
        part = part.substr(0,value_end - 1);
    }
    return part;
}

/**
 * --asdasd-_klkl
 * @param file_name
 * @param typ
 * @param path -- zum Beispiel
 * @return
 */
float rfc(string file_name,string path,string einheit)
{

    return stof(rsc(file_name,path,einheit));
}
int ric(string file_name,string path,string einheit)
{

    return stoi(rsc(file_name,path,einheit));
}
double rdc(string file_name,string path,string einheit)
{

    return stod(rsc(file_name,path,einheit));
}
long rlc(string file_name,string path,string einheit)
{

    return stol(rsc(file_name,path,einheit));
}