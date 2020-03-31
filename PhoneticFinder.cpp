/**
 * phonetic search function
 * AUTHOR: RoiPeleg
 * */

#include "PhoneticFinder.hpp"
using namespace phonetic;
namespace phonetic{
    //checks if given letters counld be interchanged bt rules given in README
    // if so returns true
    bool alike(char c1 , char c2){
        c1 = tolower(c1);
        c2 = tolower(c2);
        if(c1 == c2)return true;
        if(c1 == 'w' && c2 !='v')return false;
        if(c1 == 'v' && c2 !='w')return false;

        if(c1 == 'y' && c2 !='i')return false;
        if(c1 == 'i' && c2 !='y')return false;

        if(c1 == 'g' && c2 !='j')return false;
        if(c1 == 'j' && c2 !='g')return false;

        if(c1 == 'o' && c2 !='u')return false;
        if(c1 == 'u' && c2 !='o')return false;

        if(c1 == 'd' && c2 !='t')return false;
        if(c1 == 't' && c2 !='d')return false;

        if(c1 == 'b' && c2 != 'f' && c2 != 'p')return false;
        if(c1 == 'f' && c2 != 'b' && c2 != 'p')return false;
        if(c1 == 'p' && c2 != 'f' && c2 != 'b')return false;

        if(c1 == 'c' && c2 != 'k' && c2 != 'q')return false;
        if(c1 == 'k' && c2 != 'c' && c2 != 'q')return false;
        if(c1 == 'q' && c2 != 'c' && c2 != 'k')return false;
        return true;
    }
    //gets a string and word to search in if the word(or simllar one) is found returns it.
     string find(string text,string word){
         string temp;
         int start = 0;
         bool found = false,stopw = false;
         //jumps over spaces at the begining if exists.
         while(text[start]==' ' && start == text.length())start++;


         for(size_t i=start;i<text.length() && !found;i++){
             if(text[i]==' ' || i == text.length()-1){
                 if(i==text.length()-1){//substr cuts the last character otherwise
                     temp = text.substr(start);
                 }else
                 {
                     temp = text.substr(start,i-start);
                 }
                 start = i+1;
                 if(temp.length() != word.length())continue;//if the words are'nt the same length no need to compare them
                 stopw = false;
                 
                 for(size_t ind = 0;ind<temp.length()&&!stopw;ind++){
                     if(!alike(temp[ind],word[ind])){
                         stopw =true;
                     }
                 }

                 if(!stopw)found = true;
             }
         }


         if(!found){//will thorw exption 
             throw noWordExp(word);
         }
         
        return temp;
    }
    

    }