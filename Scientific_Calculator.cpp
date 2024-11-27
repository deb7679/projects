#include <iostream>
#include <cmath>
#include <windows.h> // For `system("cls")`
using namespace std;

// Function to display the calculator menu
void show_calculator() {
    cout << "----------------------------------------------" << endl;
    cout << "---                                       ----" << endl;
    cout << "-                 SCIENTIFIC                 -" << endl;
    cout << "-                 CALCULATOR                 -" << endl;
    cout << "---                                        ---" << endl;
    cout << "----------------------------------------------" << endl;
    cout << "-      +      |       -       |       *      -" << endl;
    cout << "-     Add     |     Minus     |   Multiply   -" << endl;
    cout << "----------------------------------------------" << endl;
    cout << "-      /      |       m       |       L      -" << endl;
    cout << "-   Divide    |      Mod      |      Log     -" << endl;
    cout << "----------------------------------------------" << endl;
    cout << "-      S      |       C       |       P      -" << endl;
    cout << "-   Square    |      Cube     |     Power    -" << endl;
    cout << "----------------------------------------------" << endl;
    cout << "-      s      |       c       |       t      -" << endl;
    cout << "-     sin     |      cos      |      tan     -" << endl;
    cout << "----------------------------------------------" << endl;
    cout << "-      r      |       d       |       .      -" << endl;
    cout << "-   sq root   |      DEL      |     Close    -" << endl;
    cout << "----------------------------------------------" << endl;
}

// Function to display the current output
void display_output(double answer) {
    cout<<"----------------------------------------------"<<endl;
    cout<<"---                    -----------------------"<<endl;
    cout<<"-    CURRENT           |      "<<endl;
    cout<<"-    OUTPUT IS:        |   "<<answer<<endl;
    cout<<"---                    -----------------------"<<endl;
    cout<<"----------------------------------------------"<<endl;
    cout<<"-      +      |       -       |       *      -"<<endl;
    cout<<"-     Add     |     Minus     |   Multiply   -"<<endl;
    cout<<"----------------------------------------------"<<endl;
    cout<<"-      /      |       m       |       L      -"<<endl;
    cout<<"-   Divide    |      Mod      |      Log     -"<<endl;
    cout<<"----------------------------------------------"<<endl;
    cout<<"-      S      |       C       |       P      -"<<endl;
    cout<<"-   Square    |      Cube     |     Power    -"<<endl;
    cout<<"----------------------------------------------"<<endl;
    cout<<"-      s      |       c       |       t      -"<<endl;
    cout<<"-     sin     |      cos      |      tan     -"<<endl;
    cout<<"----------------------------------------------"<<endl;
    cout<<"-      r      |       d       |       .      -"<<endl;
    cout<<"-   sq root   |      DEL      |     Close    -"<<endl;
    cout<<"----------------------------------------------"<<endl;
}

// Main function
int main() {
    double num1 = 0.0, num2 = 0.0, answer = 0.0;
    char input;
    bool displayOnly = false;

    show_calculator();

    while (true) {
        if (displayOnly) {
            cout << "Enter operation: ";
            cin >> input;
        } else {
            cout << "Enter operation: ";
            cin >> input;

            // For binary operations, take two inputs
            if (input == '+' || input == '-' || input == '*' || input == '/' || input == 'm' || input == 'P') {
                cout << "Enter num1: ";
                cin >> num1;
                cout << "Enter num2: ";
                cin >> num2;
            } else if (input == '.' || input == 'd') {
                // Special operations: no input needed
                break;
            } else {
                // For unary operations, take one input
                cout << "Enter num1: ";
                cin >> num1;
            }
        }

        // Perform the operation
        switch (input) {
            case '+': answer = num1 + num2; break;
            case '-': answer = num1 - num2; break;
            case '*': answer = num1 * num2; break;
            case '/': answer = num2 != 0 ? num1 / num2 : 0; break;
            case 'm': answer = static_cast<int>(num1) % static_cast<int>(num2); break;
            case 'L': answer = log(num1); break;
            case 'S': answer = num1 * num1; break;
            case 'C': answer = num1 * num1 * num1; break;
            case 'P': answer = pow(num1, num2); break;
            case 's': answer = sin(num1); break;
            case 'c': answer = cos(num1); break;
            case 't': answer = tan(num1); break;
            case 'r': answer = sqrt(num1); break;
            case 'd': system("cls"); show_calculator(); continue;
            case '.': exit(0); // Close the program
            default: 
                cout << "~~~~ You Entered an Invalid Operation! ~~~~" << endl;
                continue;
        }

        // Clear the screen and display the output
        system("cls");
        display_output(answer);
    }

    return 0;
}
