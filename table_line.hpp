#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

class table_line{
    public:
    string name;
    std::pair<string,vector<string> > type;//will hold type of var at first string, and var of function vars at vec
    int offset;
    table_line(string _name, string _type, int _offset):
                name(_name),type(_type, vector<string>()),offset(_offset){}//for vars
    
    table_line(string _name, string _type, vector<string> vec, int _offset):
                name(_name),type(_type, vec),offset(_offset){//for func
        
    }
};
