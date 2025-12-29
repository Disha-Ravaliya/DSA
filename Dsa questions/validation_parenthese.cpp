#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
   vector<char>vec;
    bool isValid(char s) {
        
        if(s == '(' || s =='[' || s == '{')
        {
            return true;

        }else
        return false;

    }

    void push(char s){
        
            vec.push_back(s);
        }

    
    void pop(){

        if(!vec.empty()){
           
            vec.pop_back();
            
        }else{
           cout<<"stack is empty";
        }
    }
    int vaild_para(string s)
    {
       for (char c:s) {
        if(isValid(c)){
            
            vec.push_back(c);
        }
        else if(top()=='(' && c==')' || top()=='[' && c==']' || top()=='{' && c== '}'){
            vec.pop_back();}
            else{
                return 0;
            }
        

       }
       return 1;

    }

    char top(){
        if(!vec.empty()){
        int lastindex=vec.size()-1;
        return vec[lastindex];
        }else{
            cout<<"stack is empty ";
            return '\0';
        }
    }




};

int main(){
    Solution s;
     cout<<s.vaild_para("({[]}){{{{{{{{((((((()))))))))}}}}}}}}");
} 