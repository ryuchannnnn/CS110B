// Assignment 8 C-Strings.cpp
// Danny Chan
// CS110B
// 10/14/2020

/*
Implement the following functions.
Each function deals with null terminated C-strings.
You can assume that any char array passed into the functions will contain valid, null-terminated data.
You may use strlen() (string length), strcmp() (string compare), and strncpy() (string copy), if you wish, but you may not use any of the other C-string library functions such as strstr(), strncat(), etc.
You will not receive credit for solutions which use C++ string objects, you must use C-Strings (null-terminated arrays of chars) for this assignment.
*/

#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

int lastIndexOf(char* s, char target);
void reverse(char* s);
int replace(char* s, char target, char replacementChar);
int findSubstring(char* s, char substring[]);
bool isPalindrome(char* s);

int main()
{
    const int maxChars = 128;
    int option;
    char target;
    char s[maxChars];
    char substring[maxChars];
    char replacementChar;
    cout << "Please enter a phrase of a word" << endl;
    cin.getline(s, maxChars);
    cout << "What would you like to do with " << s << endl;
    cout << "Enter the number next to the choice you want: " << endl;
    cout << "1. last index of " << s << endl;
    cout << "2. reverse " << s << endl;
    cout << "3. replace a character in " << s << endl;
    cout << "4. substring in " << s << endl;
    cout << "5. palindrome " << s << endl;
    cin >> option;
    if (option == 1)
    {
        cout << "You entered: " << s << endl;
        cout << "Enter a letter: " << endl;
        cin >> target;
        if (lastIndexOf(s, target) == -1)
        {
            cout << target << "does not appear in " << s << "." << endl;
        }
        else
        {
            cout << target << " appears at index " << lastIndexOf(s, target) << endl;
        }
    }
    else if (option == 2)
    {
        cout << "Currently, this is " << s << endl;
        cout << "We will now reverse it." << endl;
        reverse(s);
        cout << "Reverse is " << s << endl;
    }
    else if (option == 3)
    {
        cout << "What letter do you want to change" << " in " << s << endl;
        cin >> target;
        cout << "What letter do you want to replace " << target << " with " << endl;
        cin >> replacementChar;
        cout << "Current word is " << s << endl;
        replace(s, target, replacementChar);
        cout << "After targetting " << target << " with " << replacementChar << ", " << endl;
        cout << "The new word is " << s << endl;
    }
    else if (option == 4)
    {
        cout << "Enter substring to find within " << s << endl;
        cin.ignore(100, '\n');
        cin.getline(substring, maxChars);
        cout << "The position of " << substring << " in " << s << " is at " << findSubstring(s, substring) << endl;
    }
    else if (option == 5)
    {
        isPalindrome(s);
        if (isPalindrome(s) == false)
        {
            cout << s << " is not a palindrome." << endl;
        }
        if (isPalindrome(s) == true)
        {
            cout << s << " is a palidrome." << endl;
        }
    }
    else
    {
        cout << "Enter a number from 1 to 5" << endl;
    }
}

/*This function returns the last index where the target char can be found in the string.
it returns -1 if the target char does not appear in the string.
For example, if s is “Giants” and target is ‘a’ the function returns 2.
*/

int lastIndexOf(char* s, char target)
{
    int elementPos = -1;
    for (int i = 0; *s != '\0'; i++)
    {
        if (target == *s)
        {
            elementPos = i;
        }
        s++;
    }
    return elementPos;
}

/*
This function alters any string that is passed in. It should reverse the string.
If “flower” gets passed in it should be reversed in place to “rewolf”.
To be clear, just printing out the string in reverse order is insufficient to receive credit, you must change the actual string to be in reverse order.
*/

void reverse(char* s)
{
    int noNullChar = -1;
    int i = 0;
    for (int i = 0; i < strlen(s); i++)
    {
        noNullChar++;
    }
    char temp = s[noNullChar];
    for (int j = 0; j < noNullChar; j++)
    {
        s[noNullChar] = s[j];
        s[j] = temp;
        noNullChar--;
        temp = s[noNullChar];
    }
}

/*
This function finds all instances of the char ‘target’ in the string and replaces them with ‘replacementChar’.
It also returns the number of replacements that it makes.  If the target char does not appear in the string it returns 0 and does not change the string.
For example, if s is “go giants”, target is ‘g’, and replacement is ‘G’, the function should change s to “Go Giants” and return 2.
*/

int replace(char* s, char target, char replacementChar)
{
    int replaceCounter = 0;
    for (int i = 0; i < strlen(s); i++)
    {
        if (target == s[i])
        {
            s[i] = replacementChar;
            replaceCounter++;
        }
    }
    return replaceCounter;
}

/*
This function returns the index in string s where the substring can first be found.
For example if s is “Skyscraper” and substring is “ysc” the function would return 2.
It should return -1 if the substring does not appear in the string.
*/

int findSubstring(char* s, char substring[])
{
    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] == substring[0])
        {
            for (int j = 0, k = i; j < strlen(substring); j++, k++)
            {
                if (s[k] != substring[j])
                {
                    break;
                }
                if (j == strlen(substring) - 1)
                {
                    return i;
                }
            }
        }
    }
    return -1;
}

/*
This function returns true if the argument string is a palindrome.
It returns false if it is not.
A palindrome is a string that is spelled the same as its reverse.
For example “abba” is a palindrome. So is “hannah”, “abc cba”, and “radar”.
*/

bool isPalindrome(char* s)
{
    int lastElement = strlen(s)-1;
    for (int i = 0; i < strlen(s)-1; i++, lastElement--)
    {
        if (s[i] != s[lastElement])
        {
            return false;
        }
    }
    return true;
}


/*
[dchan89@hills ~]$ ./a.out
Please enter a phrase of a word
Giants
What would you like to do with Giants
Enter the number next to the choice you want:
1. last index of Giants
2. reverse Giants
3. replace a character in Giants
4. substring in Giants
5. palindrome Giants
1
You entered: Giants
Enter a letter:
a
a appears at index 2


[dchan89@hills ~]$ ./a.out
Please enter a phrase of a word
flower
What would you like to do with flower
Enter the number next to the choice you want:
1. last index of flower
2. reverse flower
3. replace a character in flower
4. substring in flower
5. palindrome flower
2
Currently, this is flower
We will now reverse it.
Reverse is rewolf


[dchan89@hills ~]$ ./a.out
Please enter a phrase of a word
giants
What would you like to do with giants
Enter the number next to the choice you want:
1. last index of giants
2. reverse giants
3. replace a character in giants
4. substring in giants
5. palindrome giants
3
What letter do you want to change in giants
g
What letter do you want to replace g with
G
Current word is giants
After targetting g with G,
The new word is Giants


[dchan89@hills ~]$ ./a.out
Please enter a phrase of a word
skyscraper
What would you like to do with skyscraper
Enter the number next to the choice you want:
1. last index of skyscraper
2. reverse skyscraper
3. replace a character in skyscraper
4. substring in skyscraper
5. palindrome skyscraper
4
Enter substring to find within skyscraper
ysc
The position of ysc in skyscraper is at 2[dchan89@hills ~]$

[dchan89@hills ~]$ ./a.out
Please enter a phrase of a word
hannah
What would you like to do with hannah
Enter the number next to the choice you want:
1. last index of hannah
2. reverse hannah
3. replace a character in hannah
4. substring in hannah
5. palindrome hannah
5
hannah is a palidrome.
*/


/*
One way that worked:

#include<iostream>
using namespace std;

int lastIndexOf(char *s, char target) { // This function returns the last index where the target char can be found in the string. It returns -1 if the target char does not appear in the string.

  int location = 0;
  while(*s != '\0') {
    if(target == *s) {
      return location;
    }
    location++;
    s++;
  }
  return -1;
}

void reverse(char *s) { // This function alters any string that is passed in. It reverses the string.
  int count = -1;
  int i = 0;
  while(s[i] != '\0') {
    count++;
    i++;
  }

  char temp = s[count];
  for(int j=0; j<count; j++) {
    s[count] = s[j];
    s[j] = temp;
    count--;
    temp = s[count];
  }
}

int replace(char *s, char target, char replacementChar) { // This function finds all instances of the char ‘target’ in the string and replaces them with ‘replacementChar’. It also returns the number of replacements that it makes. If the target char does not appear in the string it returns 0 and does not change the string.

  int count = 0;
  while(*s != '\0') {
    if(*s == tolower(replacementChar)) {
      *s = replacementChar;
      count++;
    }
    s++;
  }
  return count;
}

int findSubstring(char *s, char substring[]) { // This function returns the index in string s where the substring can first be found.

  int i=0, j=0, k=0, h=0, index=0, count1=0, count2=0;
  while(s[i] != '\0') {
    if(s[i] == substring[j]) {
      if(index == 0)
        index = i;
      if(s[i] == s[index+k]) {
        count1++;
        j++;
        k++;
      }
    }
    i++;
  }

  while(substring[h] != '\0') {
    count2++;
    h++;
  }

  if(count1 == count2)
    return index;
  else
    return -1;
}

bool isPalindrome(char *s) { // This function returns true if the argument string is a palindrome. It returns false if it is not.

  int count = -1;
  int i = 0;
  while(s[i] != '\0') {
    count++;
    i++;
  }

  const int MAX_CHARS_TWO = 128;
  char s2[MAX_CHARS_TWO];
  for(int j=0; j<=count; j++) {
    s2[j] = s[count-j];
  }

  int k=0;
  int count2 = 0;
  while(k != count) {
    if(s[k] == s2[k])
      count2++;
    k++;
  }

  if(count == count2) {
    return true;
  } else
    return false;

}

int main() {
  const int MAX_CHARS = 128;

  char s1[MAX_CHARS] = "Giants";
  char target = 'a';
  cout << "Function findSubstring returns " << lastIndexOf(s1, target) << endl;

  char s2[MAX_CHARS] = "flower";
  reverse(s2);
  cout << "Function reverse changes s2 to " << s2 << endl;

  char s3[MAX_CHARS] = "go giants";
  char target3 = 'g';
  char replacementChar = 'G';
  replace(s3, target3, replacementChar);
  cout << "Function replace changes s3 to " << s3 << endl;

  char s4[MAX_CHARS] = "Skyscraper";
  char substring[MAX_CHARS] = "ysc";
  cout << "Function findSubstring returns " << findSubstring(s4, substring) << endl;

  char s5[MAX_CHARS] = "abba";
  if(isPalindrome(s5))
    cout << "Function isPalindrome returns s5 as true" << endl;
  else
    cout << "Function isPalindrome returns s5 as false" << endl;

  return 0;
}

*/