#include <iostream>
#include <stack>
using namespace std;
class check
{
private:
    string postfix;

public:
    check()
    {
        input();
        cout << "Answer is " << evaluate();
    }
    void input()
    {
        cout << "Enter the postfix expression : ";
        getline(cin, postfix);
    }
    int compute(int x, int y, char operat)
    {
        int result = 0;
        switch (operat)
        {
        case '+':
            result = x + y;
            break;
        case '-':
            result = x - y;
            break;
        case '*':
            result = x * y;
            break;
        case '/':
            result = x / y;
            break;
        case '^':
            result = x ^ y;
            break;
        }
        return result;
    }
    int evaluate()
    {
        stack<int> st;
        for (int i = 0; i < postfix.length(); i++)
        {
            if (postfix[i] >= '0' && postfix[i] <= '9')
            {
                st.push((postfix[i] - '0'));
            }
            else if (postfix[i] == '+' || postfix[i] == '-' ||
                     postfix[i] == '*' || postfix[i] == '/' || postfix[i] == '^')
            {
                int op1 = st.top();
                st.pop();
                int op2 = st.top();
                st.pop();
                int ans = compute(op2, op1, postfix[i]);
                st.push(ans);
            }
        }
        int resu = st.top();
        st.pop();
        return resu;
    }
};
int main()
{
    check c;
    return 0;
}