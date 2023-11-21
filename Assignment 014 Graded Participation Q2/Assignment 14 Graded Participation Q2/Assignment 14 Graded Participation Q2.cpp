// Assignment 14 Graded Participation Q2.cpp : 
/*
Implement the Player and BasketballPlayer classes as discussed in the videos.  Copying from the pdfs is fine.
Create a new class BaseballPlayer which is derived from Player.  
It should have two private member ints, atBats and hits.
Create a constructor for BaseballPlayer which takes 5 parameters to initialize atBats and hits.  
It should call the Player constructor to initialize its inherited properties (name, height, weight)
In BaseballPlayer, override the pure virtual function printStats() to print out the name, height, weight, and also at bats and hits.  
It should also display batting average, for which you can use the formula: hits / at bats.  Make sure to print out decimal places as appropriate for batting average.
Create a main program which creates a BaseballPlayer and a BasketballPlayer, assigning some reasonable values to their member variables.  
Use a Player pointer to call printStats on each to print out their stats.
*/
// Danny Chan
// CS110B
// 12/5/2020

#include <iostream>

#include <string>

using namespace std;

class Player 
{
    protected:
        string name;
        double weight;
        double height;
    public:
        Player(string n, double w, double h) 
        {
            name = n;
            weight = w;
            height = h;
        }
        virtual void printStats() const = 0;
};

class BaseballPlayer : public Player 
{
    private: int atBats;
        int hits;
    public: BaseballPlayer(string n, double w, double h, int ab, int hi) : Player(n, w, h) 
    {
        atBats = ab;
        hits = hi;
    }
      void printStats() const 
      {
          cout << name << endl << "Weight: " << weight << " Height: " << height << endl;
          cout << "At bats: " << atBats << " Hits: " << hits << " Batting average: " << (double)hits / atBats << endl;
      }
};

class BasketballPlayer : public Player 
{
    private: int fieldgoals;
       int attempts;
    public: BasketballPlayer(string n, double w, double h, int fg, int a) : Player(n, w, h) 
    {
        fieldgoals = fg;
        attempts = a;
    }
      void printStats() const 
      {
          cout << name << endl << "Weight: " << weight << " Height: " << height << endl;
          cout << "FG: " << fieldgoals << " attempts: " << attempts << " Pct: " << (double)fieldgoals / attempts << endl;
      }

};

int main() 
{
    Player* p;
    Player* b;
    BasketballPlayer pointguard("Stephen Curry", 190, 1.91, 2585, 5523);
    BaseballPlayer outfielder("Juan Soto", 220, 1.85, 154, 54);
    p = &pointguard;
    p->printStats();
    b = &outfielder;
    b->printStats();
    return 0;
}