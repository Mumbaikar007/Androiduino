

//# include <iostream>
//# include <stack>
#include <StackArray.h>


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

String MakePostfix ( String equation ){

    String postfix = "";
    StackArray <char> stack1;

    for ( char i : equation ){

        if ( i == '(') {
            stack1.push(i);
        }

        else if ( i == ')'){
            while ( stack1.peek() != '('){
                postfix += stack1.pop();
                
            }
            stack1.pop();
        }

        else if ( !Priority(i)){
            postfix += i;
        }

        else {

            if ( stack1.isEmpty() ){
                stack1.push(i);
            }
            else {
                while ( !stack1.isEmpty() && stack1.peek() != '(' && Priority(i) <= Priority(stack1.peek()) ){
                    postfix += stack1.pop();
                    ;
                }
                stack1.push(i);
            }
        }

    }

    while ( !stack1.isEmpty() ){
        postfix += stack1.pop();
        
    }

    return postfix;

}

int SolvePostfix( String postfix){

    StackArray <int> theNumbers;
    int a, b;

    for ( char i : postfix ){

        switch ( i ){

            case '+':   a = theNumbers.pop();
                        
                        b = theNumbers.pop();
                     
                        theNumbers.push(b+a);
                        break;

            case '-':
                        a = theNumbers.pop();
                        
                        b = theNumbers.pop();
                        
                        theNumbers.push(b-a);
                        break;

            case '*':   a = theNumbers.pop();
                        
                        b = theNumbers.pop();
                        
                        theNumbers.push(b*a);
                        break;

            case '/':   a = theNumbers.pop();
                        
                        b = theNumbers.pop();
                        
                        theNumbers.push(b/a);
                        break;
                        
            default :   theNumbers.push( i-'0' );
        }
    }

    return theNumbers.pop();

}

/*
int main(){

    string equation = "a+b-c*d";

    string postfix = MakePostfix (equation);

    cout << postfix;


    return 0;
}
*/
