// Assignment 4 Poker Hands.cpp
/*
Write a program that reads five cards from the user, then analyzes the cards and prints out the category of poker hand that they represent.  
Poker hands are categorized according to the following labels: Straight flush, four of a kind, full house, straight, flush, three of a kind, two pairs, pair, high card.
To simplify the program we will ignore card suits, aces, and face cards. The values that the user inputs will be integer values from 2 to 9.  
When your program runs it should start by collecting five integer values from the user.
*/
// Danny Chan
// CS110B
// 9/18/2020

#include <iostream>
using namespace std;


void numberSwitcher(int& a, int& b)
{
    // This switches up the numbers to help selectionSort.
    int temp = a;
    a = b;
    b = temp;
}

void selectionSort(int hand[], int numCard)
{
    // This sorts out the integers ranging from 2-9 in the array.
    int minIndex, minValue;
    for (int start = 0; start < numCard - 1; start++)
    {
        minIndex = start;
        minValue = hand[start];
        for (int index = start + 1; index < numCard; index++)
        {
            if (hand[index] < minValue)
            {
                minValue = hand[index];
                minIndex = index;
            }
        }
        numberSwitcher(hand[minIndex], hand[start]);
    }
}

bool containsPair(int hand[])
{
    // This checks if the user inputted only one pair.
    const int numCard = 5;
    int hand[numCard];
    selectionSort(hand, numCard);
    int pairCounter = 0;
    for (int i = 0; i < numCard; i++)
    {
        for (int j = i + 1; j < numCard; j++)
        {
            if (hand[i] == hand[j])
            {
                pairCounter++;
            }
        }
    }
    if (pairCounter == 1)
    {
        return true;
    }
    return false;
}

bool containsTwoPair(int hand[])
{
    // This checks if he user inputed 2 pairs. 
    const int numCard = 5;
    int hand[numCard];
    selectionSort(hand, numCard);
    int twoPairCounter = 0;
    int runThru = 0;
    for (int i = 0; i < numCard; i++)
    {
        for (int j = i + 1; j < numCard; j++)
        {
            if (hand[i] == hand[j])
            {
                twoPairCounter++;
            }
            if (hand[i] != hand[j])
            {
                runThru++;
            }
        }
        if (twoPairCounter == 2)
        {
            return true;
        }
    }
    return false;
}

bool containsThreeOfaKind(int hand[])
{
    //This checks for if the user has 3 of the same number in his hand
    const int numCard = 5;
    int hand[numCard];
    selectionSort(hand, numCard);
    for (int i = 0; i < numCard; i++)
    {
        for (int j = i + 1; j < numCard; j++)
        {
            for (int k = j + 1; k < numCard; k++)
            {
                if (hand[i] == hand[j] && hand[j] == hand[k])
                {
                    return true;
                }
            }
        }
    }
    return false;
}

bool containsStraight(int hand[])
{
    // This checks if a player has cards each of 1 value or higher in the array.
    const int numCard = 5;
    int hand[numCard];
    selectionSort(hand, numCard);
    int straightCheck = 0;
    for (int i = 0; i < numCard; i++)
    {
        if (hand[i + 1] - hand[i] == 1)
        {
            straightCheck++;
        }
        if (straightCheck == 4)
        {
            return true;
        }
    }
    return false;
}

bool containsFullHouse(int hand[])
{
    const int numCard = 5;
    int hand[numCard];
    selectionSort(hand, numCard);
    if (hand[0] == hand[1] && hand[1] == hand[2] && hand[3] == hand[4])   
    {
        if ((hand[2] != hand[3]) && hand[3] == hand[4])
        {
            return true;
        }
    }
    else if (hand[0] == hand[1] && hand[2] == hand[3] && hand[3] == hand[4]) 
    {
        if ((hand[1] != hand[2]) && (hand[0] == hand[1])) 
        {
            return true;
        }
    }
    else
    {
        return false;
    }
    
}

bool containsFourOfaKind(int hand[])
{
    // This checks if they have a four of one card. 
    const int numCard = 5;
    int hand[numCard];
    selectionSort(hand, numCard);
    for (int i = 0; i < numCard; i++)
    {
        int fourOfTheSame = 1;
        for (int j = i + 1; j < numCard + 1; j++)
        {
            if (hand[i] == hand[j])
            {
                fourOfTheSame = fourOfTheSame + 1;
            }
        }
        if (fourOfTheSame == 4)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    const int numCard = 5;
    int hand[numCard];
    cout << "Enter five numeric cards, no face cards. Use 2 - 9." << endl;
    for (int i = 0; i < numCard; i++)
    {
        cout << "Card " << i + 1 << ":";
        cin >> hand[i];
    }
    if (containsFourOfaKind(hand) == true)
    {
        cout << "Four of a Kind!" << endl;
    }
    else if (containsFullHouse(hand) == true)
    {
        cout << "Full house!" << endl;
    }
    else if (containsStraight(hand) == true)
    {
        cout << "Straight" << endl;
    }
    else if (containsThreeOfaKind(hand) == true)
    {
        cout << "Three of a Kind!" << endl;
    }
    else if (containsTwoPair(hand) == true)
    {
        cout << "Two pairs!" << endl;
    }
    else if (containsPair(hand) == true)
    {
        cout << "Pair!" << endl;
    }
    else
    {
        cout << "High Card!" << endl;
    }
}
/*
[dchan89@hills ~]$ ./a.out
Enter five numeric cards, no face cards. Use 2 - 9.
Card 1:7
Card 2:6
Card 3:5
Card 4:8
Card 5:2
High Card!

[dchan89@hills ~]$ ./a.out
Enter five numeric cards, no face cards. Use 2 - 9.
Card 1:7
Card 2:7
Card 3:5
Card 4:8
Card 5:2
Pair!

[dchan89@hills ~]$ ./a.out
Enter five numeric cards, no face cards. Use 2 - 9.
Card 1:9
Card 2:9
Card 3:6
Card 4:5
Card 5:6
Two pairs!

[dchan89@hills ~]$ ./a.out
Enter five numeric cards, no face cards. Use 2 - 9.
Card 1:7
Card 2:5
Card 3:4
Card 4:7
Card 5:7
Three of a Kind!

[dchan89@hills ~]$ ./a.out
Enter five numeric cards, no face cards. Use 2 - 9.
Card 1:5
Card 2:6
Card 3:7
Card 4:8
Card 5:4
Straight

[dchan89@hills ~]$ ./a.out
Enter five numeric cards, no face cards. Use 2 - 9.
Card 1:6
Card 2:6
Card 3:6
Card 4:8
Card 5:8
Full house!

[dchan89@hills ~]$ ./a.out
Enter five numeric cards, no face cards. Use 2 - 9.
Card 1:8
Card 2:8
Card 3:8
Card 4:8
Card 5:6
Four of a Kind!
*/