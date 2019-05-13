#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <stack>
#include "table.hpp"

using namespace std;

class symbol_table{
    public:
    stack<table> tables_stack;
    stack<int> offset_stack;
    symbol_table(){}
    //actions needed from symbol table:
    void add_table(){
        //adds a new table when a new scope is starting
        table t;
        tables_stack.push(t);
        offset_stack.push(0);
    }
    void add_table(vector<string> vec, string type){
        //adds a new table when a new scope of a function is starting
        //vec represents parameters to that function
        table t;
        for(int i=0;i<vec.size();i++){
            t.add_line(vec[i],type,(-i)-1);
        }
        tables_stack.push(t);
    }
    void add_line(string name, string type){//for vars
        tables_stack.top().add_line(name,type);
        offset_stack.top()++;
    }
    void add_line(string name, string type, vector<string> vec){//for funcs
        tables_stack.top().add_line(name,type,vec);
        add_table(vec,type);//push new table for function
        offset_stack.push(0);
    }
    void remove(){
        tables_stack.pop();
        offset_stack.pop();
    }
};
