#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Stack{
    public:

    vector<char>vec;
    string result;

    void push(char c){
      vec.push_back(c);
    }

    void pop(){
        if(!vec.empty()){
            vec.pop_back();
        }
    }
   char top(){
     
     return vec[vec.size()-1];
   }

   int checkpresedency(char c){
        if(c=='^' ||c== '$'){
            return 3;
        }else if (c=='*' || c=='/'){
            return 2;
        }
        else if(c=='+' || c=='-'){
            return 1;
        }else{
            return 0;
        }
   }
   string infixtopostfix(string s){
    char c;
    for(int i=0;i<s.length();i++){
        c=s[i];

        if(c=='('){
            push(c);
        
        }
        else if(c >='a'|| c>='A' || c <='z'|| c<='Z'){
            result+=c;
        }
        else if(c=='+' || c=='-'|| c=='/' || c=='*' || c=='$' || c=='^'){
            while(checkpresedency(top())>=checkpresedency(c)){
                result+=top();
                pop();
             }
            if(checkpresedency(top())<=checkpresedency(c)){
                push(c);
            }
            if(c==')'){
                while(c!='('){
                    result+=top();
                    pop();
                }
                pop();
            }
             
            
        }
         
        


    }
    while(!vec.empty()){
        result+=top();
                pop();
 }
 return result;
   }


};

int main() {
    Stack s;
    cout << s.infixtopostfix("a+b");


    
    return 0;
}