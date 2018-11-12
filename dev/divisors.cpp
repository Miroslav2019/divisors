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

//function forward declarations for functions below main()
long get_whole_number();
void find_and_handle_divisors(long divided_number);
//nested in find_and_handle_divisors()
void handle_divisor(long divisor, long divided);

//String definitions
std::string credits {
"\nAjalle's Natural Divisors Finder v0.1\n\
(c) 2018 by Ajalle Perfej\n"};

std::string introduction {
"\nThis program finds which natural numbers any natural number\n\
you enter is evenly divisible by. For example, for the number 9\n\
it prints:\n\n\t1 * 9 = 9\n\t3 * 3 = 9\n\t9 * 1 = 9\n\n\
Your number must be no larger than 2147483648 (or just more\n\
than 2 billion).\n\
Any decimals you enter are truncated and make your number \
smaller."};

int main()
{
    cout << credits;
    cout << introduction;

    long whole_number;
    whole_number = get_whole_number();

    //This functions nests handle_divisor()
    find_and_handle_divisors(whole_number);

    return 0;
}

//Interface for getting natural number--partly idiotproofed.
long get_whole_number()
{
    while (true)
    {
        cout << "\nEnter a natural number: ";
        long choice;
        cin >> choice;
        cin.ignore(32767, '\n');
        choice = static_cast<long>(choice);

        if (choice >= 1)
        {
            return choice;
        }

        cout << "\nMust be at least +1 to be a natural number.\n";
    }
}

void find_and_handle_divisors(long divided_number)
{
    cout << "\nThe divisors of " << divided_number << " are:\n";
    long divisor{1};
    while (divisor <= divided_number )
    {
        handle_divisor(divisor, divided_number);
        ++divisor;
    }
}

void handle_divisor(long divisor, long divided)
{
    if (divided % divisor == 0)
    {
        cout << divisor << " * " << divided / divisor << " = "
             << divided << "\n";
    }
}