#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <vector>
#include "table_line.hpp"

using namespace std;

class table{
    public:
    vector<table_line> table_elements;
    int offset_counter;
    table():offset_counter(0){}
    void add_line(string name, string type){//for vars
        table_line line(name,type,offset_counter++);
        table_elements.push_back(line);
    }
    void add_line(string name, string type, int _offset){//for func vars
        table_line line(name,type,_offset);
        table_elements.push_back(line);
    }
    void add_line(string name, string type, vector<string> vec){//for funcs
        table_line line(name,type,vec,INT_MAX);//functions have no offset
        table_elements.push_back(line);
    }
};
