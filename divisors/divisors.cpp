/* Ajalles Natural Divisors Finder v0.1
   (c) 2018 by Ajalle Perfej
   This simple academic console application prints the natural
   number divisors of a natural number entered by the user. 
   For example, for the number 9 it prints:
       The divisors of 9 are:
       1 * 9 = 9
       3 * 3 = 9
       9 * 1 = 9
   
   The number entered by the user can't be more than 1e25.
   Any fractional adjuncts are truncated.*/

#include <iostream>
#include <string>

//For simplicity of printing to and reading from console
//the std namespace is declared for both cout (print to
//console) and cin (read input from console).
using std::cout;
using std::cin;

//Interface for getting natural number.
long getWholeNumber()
{
    
    while (true)
    {
        cout << "\nEnter a natural number: ";

        long input_number;
        cin >> input_number;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(),\
             '\n');
        }
        else if (input_number >= 1)
        {
            return input_number;
        }
        
        cout << "Invalid input.\n";
        cout << "Natural numbers are integers 1 or higher.\n";
    }
}

void handleDivisor(long divisor, long divided)
{
    if (divided % divisor == 0)
    {
        cout << divisor << " * " << divided / divisor << " = "
             << divided << "\n";
    }
}

void findAndHandleDivisors(long divided_number)
{
    cout << "\nThe divisors of " << divided_number << " are:\n";
    long divisor{1};
    while (divisor <= divided_number )
    {
        handleDivisor(divisor, divided_number);
        ++divisor;
    }
}

void printCredits()
{
    std::string credits {
"\nAjalle's Natural Divisors Finder v0.1\n\
(c) 2018 by Ajalle Perfej\n"};

    cout << credits;
}

void printIntro()
{
    std::string introduction {
"\nThis program finds which natural numbers any natural number\n\
you enter is evenly divisible by. For example, for the number 9\n\
it prints:\n\n\t1 * 9 = 9\n\t3 * 3 = 9\n\t9 * 1 = 9\n\n\
A natural number is an integer 1 or larger.\n\
Your number must be no larger than 2147483648 (or just more\n\
than 2 billion).\n\
Any decimals you enter are truncated and make your number \
smaller."};

    cout << introduction;
}

int main()
{
    printCredits();
    printIntro();

    long whole_number;
    whole_number = getWholeNumber();

    //This functions nests handle_divisor()
    findAndHandleDivisors(whole_number);

    return 0;
}
