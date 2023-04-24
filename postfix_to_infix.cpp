#include <iostream>
#include <stack>
#include <string>
#include <cmath>

using namespace std;

int eval(string exp) {
    stack<int> st;
    int op1, op2;

    int cnt = 0;

    while(cnt < exp.length() ) {
        if (isdigit(exp[cnt])) {
            st.push(exp[cnt] - '0');
        } 
        else {
            op2 = st.top();
            st.pop();
            op1 = st.top();
            st.pop();
            switch (exp[cnt]) {
                case '+':
                    st.push(op1 + op2);
                    break;
                case '-':
                    st.push(op1 - op2);
                    break;
                case '*':
                    st.push(op1 * op2);
                    break;
                case '/':
                    st.push(op1 / op2);
                    break;
                case '%':
                    st.push(op1 % op2);
                    break;
                case '^':
                    st.push(pow(op1, op2));
                    break;
            }
        }
        cnt++;
    }
    return st.top();
}

int main() {
    cout << "Enter suffix expression: ";
    string exp;
    cin >> exp;
    cout << "Result: " << eval(exp) << endl;
    return 0;
}