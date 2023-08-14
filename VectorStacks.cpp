#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int Prioritaet(string zZeichen);

void Phase1(const vector<string> &tokens);
void Phase2();
void OperatorAktion();

stack<int> ValStack;
stack<string> OpStack;

int main(void)
{
    vector<string> tokens;
    tokens.push_back("3");
    tokens.push_back("*");
    tokens.push_back("2");
    tokens.push_back("+");
    tokens.push_back("1");

Phase1(tokens);
Phase2();

cout << ValStack.top() << endl;
}

void Phase1(const vector<string> &tokens)
{
    for(int i = 0; i < tokens.size(); i++)
    {
        if(tokens[i] == "+" || tokens[i] == "*")
        {
            while(!OpStack.empty() && Prioritaet(tokens[i]) <= Prioritaet(OpStack.top()))
                OperatorAktion();
            OpStack.push(tokens[i]);
        }
        else
            ValStack.push(stoi(tokens[i]));
    }
}

void Phase2()
{
    while(!OpStack.empty())
        OperatorAktion();
}

void OperatorAktion()
{
    int     zWert = 0;
    int     op2 = ValStack.top(); ValStack.pop();
    int     op1 = ValStack.top(); ValStack.pop();
    string  op = OpStack.top(); OpStack.pop();

    if(op == "+")
        zWert = (op1 + op2);
    else if(op == "*")
        zWert = (op1 * op2);
    ValStack.push(zWert);
}

int Prioritaet(string zZeichen)
{
    if(zZeichen == "*")
        return 2;
    else if(zZeichen == "+")
        return 1;
}
