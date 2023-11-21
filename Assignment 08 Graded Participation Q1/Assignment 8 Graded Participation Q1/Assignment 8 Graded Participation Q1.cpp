// Danny Chan
// CS110B
// 10/14/2020
/*Write a program which can check a C-string containing a password to see if it is in the hills initial password format, i.e. mmmDDYY.fl, where:
mmm - three lowercase characters for month, e.g. "mar" is March (you don’t need to verify that it’s an actual month, just three lowercase characters)
DD - two digits for day (you don't need to verify that it's an actual day, any two digits are ok)
YY - two digits for year
. - a period
fl - two lowercase characters for first and last initials
*/

#include <iostream>
#include <cstring>
using namespace std;

bool checkPass(char userPass[])
{
    for (int i = 0; i < strlen(userPass); i++)
    {
        if (i < 3 && !isalpha(userPass[i]))
        {
            return false;
        }
        if (i >= 3 && i < 7 && !isdigit(userPass[i]))
        {
            return false;
        }
        if (i == 7 && userPass[i] != '.')
        {
            return false;
        }
        if (i > 7 && !isalpha(userPass[i]))
        {
            return false;
        }
    }
    return true;
}

int main()
{
    const int SIZE = 11;
    char password[SIZE];

    cout << "What is your hills password in mmmDDYY.fl: ";
    cin.getline(password, SIZE);
    cout << strlen(password) << endl;
    cout << "Your hills password you entered is: " << password << endl;
    int result = checkPass(password);
    if (result)
    {
        cout << "Your password is in the hills password format" << endl;
    }
    else
    {
        cout << "Your password is not in a hills password format" << endl;
    }
    return 0;
}