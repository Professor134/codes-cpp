
#include <iostream>
#include <stdexcept>
using namespace std;

int main()
{
    double num1, num2, result;

    try
    {
        cout << "Enter first number: ";
        if (!(cin >> num1))
            throw invalid_argument("Invalid input! Enter a number.");

        cout << "Enter second number: ";
        if (!(cin >> num2))
            throw invalid_argument("Invalid input! Enter a number.");

        if (num2 == 0)
            throw runtime_error("Division by zero is not allowed.");

        result = num1 / num2;

        cout << "Result = " << result << endl;
    }
    catch (const invalid_argument &e)
    {
        cout << "Input Error: " << e.what() << endl;
    }
    catch (const runtime_error &e)
    {
        cout << "Runtime Error: " << e.what() << endl;
    }

    cout << "Program terminated gracefully." << endl;

    return 0;
}

