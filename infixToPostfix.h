

# include <iostream>
# include <stack>


using namespace std;


int Priority ( char operand ){

    switch ( operand){

        case '/':
        case '*': return 2;

        case '+':
        case '-': return 1;

        default: return 0;

    }
}

string MakePostfix ( string equation ){

    string postfix = "";
    stack <char> stack1;

    for ( char i : equation ){

        if ( i == '(') {
            stack1.push(i);
        }

        else if ( i == ')'){
            while ( stack1.top() != '('){
                postfix += stack1.top();
                stack1.pop();
            }
            stack1.pop();
        }

        else if ( !Priority(i)){
            postfix += i;
        }

        else {

            if ( stack1.empty() ){
                stack1.push(i);
            }
            else {
                while ( !stack1.empty() && stack1.top() != '(' && Priority(i) <= Priority(stack1.top()) ){
                    postfix += stack1.top();
                    stack1.pop();
                }
                stack1.push(i);
            }
        }

    }

    while ( !stack1.empty() ){
        postfix += stack1.top();
        stack1.pop();
    }

    return postfix;

}


int main(){

    string equation = "a+b-c*d";

    string postfix = MakePostfix (equation);

    cout << postfix;


    return 0;
}
