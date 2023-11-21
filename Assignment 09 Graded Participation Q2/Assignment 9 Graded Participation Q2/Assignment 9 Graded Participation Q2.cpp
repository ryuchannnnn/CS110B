// Assignment 9 Graded Participation Q2.cpp
// Danny Chan
// CS110B
// 10/23/2020
/*
Add on to your taqueria program from Question 2 above.  
Just like in the videos and pdfs, create a new struct named Cost which contains two doubles: wholesale and retail.  
Add one of these to the your SalesRecord struct, so it now has three fields — the name, the number sold, and the Cost struct.  
Modify your input loop from Question 1 to input both wholesale and retail costs for each burrito type.
Write a function which takes a SalesRecord as a parameter (by value), 
and returns the total profit from selling all the burritos of this type (unitProfit = retail - wholesale; totalProfit = unitProfit * numSold).
*/

#include <iostream>

using namespace std;

struct Cost
{
    double wholeSale;
    double retail;
};

struct SalesRecord
{
    int numSold;
    string burritoName;
    Cost cost;
};

float getProfit(SalesRecord);
void printReport(SalesRecord*, int);

int main()
{
    cout << "Enter how many types of burritos you are selling: ";
    int numTypes;
    cin >> numTypes;
    SalesRecord* dailySales = new SalesRecord[numTypes];

    for (int i = 0; i < numTypes; i++)
    {
        cout << "Enter name of burrito: ";
        cin >> dailySales[i].burritoName;
        cout << "Enter number of burritos sold: ";
        cin >> dailySales[i].numSold;
        cout << "Enter the wholesale price of the burrito: ";
        cin >> dailySales[i].cost.wholeSale;
        cout << "Enter the retailprice: ";
        cin >> dailySales[i].cost.retail;
    }

    cout << "--------------------" << endl;
    cout << "Daily Sales Record: " << endl;
    cout << "--------------------" << endl;
    int totalSales;
    for (int i = 0; i < numTypes; i++)
    {
        cout << dailySales[i].burritoName << ": " << dailySales[i].numSold << endl;
        totalSales += dailySales[i].numSold;
    }
    cout << "Total burritos sold: " << totalSales << endl;
    printReport(dailySales, numTypes);
    delete[] dailySales;
}

float getProfit(SalesRecord record)
{
    float unitProfit = record.cost.retail - record.cost.wholeSale;
    return (unitProfit * record.numSold);
}

void printReport(SalesRecord* records, int size)
{
    double totalProfit = 0;
    cout << "-------------" << endl;
    cout << "Total Profit:" << endl;
    cout << "-------------" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << (records + i)->burritoName << " $" << getProfit(*(records + i)) << endl;
        totalProfit += getProfit(*(records + i));
    }
    cout << "Total profit: $" << totalProfit << endl;
}