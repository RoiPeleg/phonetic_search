#include <stdexcept>
#include <iostream>
using namespace std;
namespace phonetic{
class noWordExp : public exception
{
    private:
    string notfound;
    public:
    noWordExp(string word){notfound = word;}
    const char * what () const throw ()
    {
        string s = "Did not find the word '";
        //s.append(notfound);
        s.append("' in the text");
        //cout << s << endl;
        return s.c_str();
    }
    
};
string find(string t,string w);
}