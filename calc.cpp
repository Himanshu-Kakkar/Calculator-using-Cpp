//Terminal based Output
//Code by Himanshu Kakkar (NIT KKR )
// LinkedIn:
//https://www.linkedin.com/in/himanshu-kakkar-8154981b4/

#include <iostream>
#include <limits>
#include <stdexcept>

using namespace std;

class Calculator {
private:
    double a;
    double b;
    char op;

public:
    char getOp();
    double getA();
    void getValue1();
    void getValue2();
    void getOperater();

    void add();
    void mul();
    void div();
    void sub();

} calc;

void Calculator::getValue1() {
    cout << "Enter first value :: ";
    while (!(cin >> a)) {
        cin.clear(); 
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input
        cout << "Invalid input. Enter a numeric value :: ";
    }
}

void Calculator::getValue2() {
    cout << "Enter second value :: ";
    while (!(cin >> b)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Enter a numeric value :: ";
    }
}

void Calculator::getOperater() {
    cout << "Enter Operator :: ";
    while (true) {
        cin >> op;
        if (op == '+' || op == '-' || op == '*' || op == '/' || op == '=') {
            break;
        } else {
            cout << "Invalid operator. Enter a valid operator (+, -, *, /, =) :: ";
        }
    }
}

char Calculator::getOp() {
    return op;
}

double Calculator::getA() {
    return a;
}

void Calculator::add() {
    cout << a << " + " << b << " :: " << a + b << endl;
    a += b;
    b = 0;
}

void Calculator::sub() {
    cout << a << " - " << b << " :: " << a - b << endl;
    a -= b;
    b = 0;
}

void Calculator::mul() {
    cout << a << " * " << b << " :: " << a * b << endl;
    a *= b;
    b = 0;
}

void Calculator::div() {
    if (b == 0) {
        cout << "Division by zero is not allowed." << endl;
        return;
    }
    cout << a << " / " << b << " :: " << a / b << endl;
    a /= b;
    b = 0;
}

int main() {
    try {
        calc.getValue1();
        while (true) {
            calc.getOperater();
            if (calc.getOp() == '=') {
                cout << "Final result :: " << calc.getA() << endl;
                break;
            }
            calc.getValue2();
            switch (calc.getOp()) {
                case '+':
                    calc.add();
                    break;
                case '-':
                    calc.sub();
                    break;
                case '*':
                    calc.mul();
                    break;
                case '/':
                    calc.div();
                    break;
            }
        }
    } catch (const runtime_error& e) {
        cout << "Error: " << e.what() << endl;
    } catch (...) {
        cout << "An unexpected error occurred." << endl;
    }
    return 0;
}
