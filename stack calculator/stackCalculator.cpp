#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Stack
{
public:
    vector<char> vec;
    vector<int>cal;

    void push(char c)
    {
        vec.push_back(c);
    }

    void pop()
    {
        if (!vec.empty())
        {
            vec.pop_back();
        }
    }
    char top()
    {

        return vec[vec.size() - 1];
    }

    int checkpresedency(char c)
    {
        if (c == '^' || c == '$')
        {
            return 3;
        }
        else if (c == '*' || c == '/')
        {
            return 2;
        }
        else if (c == '+' || c == '-')
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    string infixtopostfix(string s)
    {
        string result;
        char c;
        for (int i = 0; i < s.length(); i++)
        {
            c = s[i];

            if (c == '(')
            {
                push(c);
            }
            else if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || isdigit(c))
            {
                result += c;
            }
            else
            {
                if (c == ')')
                {
                    while (!vec.empty() && top() != '(')
                    {
                        result += top();
                        pop();
                    }
                    pop();//this for '( ' to pop this
                    continue;
                }
                while (!vec.empty() && (checkpresedency(top()) >= checkpresedency(c)))
                {
                    result += top();
                    pop();
                }

                push(c);
            }
        }
        while (!vec.empty())
        {
            result += top();
            pop();
        }
        return result;
    }

    int calc(string s){
        string s2 = infixtopostfix(s);
        int result;
        int op1;
        int op2;
        vec.clear();

        for(char c : s2)
        {
            if(isdigit(c))
            {
                cal.push_back(c - '0');
            }
            else{
                op2 = cal.back() ; cal.pop_back();
                op1 = cal.back() ; cal.pop_back();


            if (c == '+') cal.push_back(op1 + op2) ;
            else if (c == '-') cal.push_back(op1 - op2);
            else if (c == '*') cal.push_back(op1 * op2);
            else if (c == '/') cal.push_back(op1 / op2);
            }
        }
        result = cal.back();
        return result;
        
    }
};

int main()
{
    Stack s;
    cout << s.calc("8/4+2");

    return 0;
}