
#include <iostream>
using namespace std;

int main()
{
    double num1, num2, result;

    try
    {
        cout << "Enter first number: ";
        if (!(cin >> num1))
            throw "Invalid input! Enter a number.";

        cout << "Enter second number: ";
        if (!(cin >> num2))
            throw "Invalid input! Enter a number.";

        if (num2 == 0)
            throw "Division by zero is not allowed.";

        result = num1 / num2;

        cout << "Result = " << result << endl;
    }
    catch (const char *e)
    {
        cout << "Error: " << e << endl;
    }

    cout << "Program terminated gracefully." << endl;

    return 0;
}
