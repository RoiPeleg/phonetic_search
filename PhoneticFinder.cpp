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
        if(c1 == 'w' && c2 =='v')return true;
        if(c1 == 'v' && c2 =='w')return true;

        if(c1 == 'z' && c2 =='s')return true;
        if(c1 == 's' && c2 =='z')return true;

        if(c1 == 'y' && c2 =='i')return true;
        if(c1 == 'i' && c2 =='y')return true;

        if(c1 == 'g' && c2 =='j')return true;
        if(c1 == 'j' && c2 =='g')return true;

        if(c1 == 'o' && c2 =='u')return true;
        if(c1 == 'u' && c2 =='o')return true;

        if(c1 == 'd' && c2 =='t')return true;
        if(c1 == 't' && c2 =='d')return true;

        if(c1 == 'b' && (c2 == 'f' || c2 == 'p'))return true;
        if(c1 == 'f' && (c2 == 'b' || c2 == 'p'))return true;
        if(c1 == 'p' && (c2 == 'f' || c2 == 'b'))return true;

        if(c1 == 'c' && (c2 == 'k' || c2 == 'q'))return true;
        if(c1 == 'k' && (c2 == 'c' || c2 == 'q'))return true;
        if(c1 == 'q' && (c2 == 'c' || c2 == 'k'))return true;
        return false;
    }
    //gets a string and word to search in if the word(or simllar one) is found returns it.
     string find(string text,string word){
         string temp;
         int start = 0;//will hold the index of the last word in the text
         bool found = false,stopw = false;
         //jumps over spaces at the begining if exists.
         while(text[start]==' ' && start < text.length())start++;


         for(size_t i=start;i<text.length() && !found;i++){//runs over the text and splits it to sub strings by spces or end of text 
             
             if(text[i]==' ' || i == text.length()-1){
                 if(i==text.length()-1 && text[i]!=' '){//substr cuts the last character otherwise
                     temp = text.substr(start);
                 }else
                 {
                     temp = text.substr(start,i-start);
                 }
                 start = i+1;
                 if(temp.length() != word.length())continue;//if the words are'nt the same length no need to compare them
                 stopw = false;
                 
                 for(size_t ind = 0;ind<temp.length()&&!stopw;ind++){
                     if(!alike(temp[ind],word[ind]) || !alike(word[ind],temp[ind])){
                         stopw =true;
                     }
                 }

                 if(!stopw)found = true;
             }
         }


         if(!found){//will thorw exption if the given word does'nt exist in the text
             throw noWordExp(word);
         }
         
        return temp;
    }
    

    }