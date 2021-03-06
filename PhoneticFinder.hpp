#pragma once
#include <stdexcept>
#include <iostream>
using namespace std;
namespace phonetic{
// custom exception for not finding the given word in text
class noWordExp : public exception
{
    private:
    string error;
    public:
    noWordExp(string s){
        error = "Did not find the word '";
        error.append(s);
        error.append("' in the text");
    }
    const char * what () const throw ()
    {
        return error.c_str();
    }
    
};
string find(string t,string w);
}