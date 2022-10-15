/*
 Caleb Acree
 C++ Fall 2022
 Due October 14, 2022
 Lab 4 Temperature Output
 Design and write a C++ program that inputs a series of hourly temperatures from a file and outputs
 a bar chart (using stars) of the temperatures. The temperature should be printed to the left of the
 corresponding bar, and there should be a heading that gives the chart's scale. The range of
 temperatures should be from -30 to 120. Because it is hard to display 150 characters on the screen,
 you should have each star represent a range of 3 degrees. That way, the bars will be at most 50
 characters wide. Use meaningful variable names, proper indentation, and appropriate comments.
 Thoroughly test the program using your own data sets. Make sure to set the value from the input file
 */

#include <string>
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

//input from file
string inputFileName = "input.date";

ifstream infile;

int temp;
string star;

void fileOpening();
void getTemp();
void posStarAmount();
void negStarAmount();
void posSide();
void negSide();

int main()
{
    fileOpening();
    
    cout <<"    Temperatures for 24 hours:" << endl;
    cout <<"    -30     0       30      60      90      120" << endl;
    
    getTemp();
    
    return 0;
}

void fileOpening()
{
    infile.open(inputFileName);
    
    if (!infile)
        cout << "Can't find file\n";
}
void getTemp()
{
    infile >> temp;
    while (infile)
    {
        if (temp > 120 || temp < -30)
        {
            
        }
        else
        {
            if (temp >=0)
                posStarAmount();
            else
                negStarAmount();
        }
        infile >> temp;
    }
}
void posSide()
{
    if (temp>=100)
        cout << temp << "           |" << star << endl;
    else if (temp>=10)
    {
        cout << temp << "           |" << star << endl;
    }
    else
        cout <<temp <<"                 |"<< star << endl;
}
void negSide()
{
    int starLen = star.length();
    int spaceAmount = 10 - starLen;
    string space;
    for (int i = 0; i < spaceAmount; i++)
    {
        space = space + ' ';
    }
    if(temp>-10)
        cout << temp << "   " << space << star << '|' << endl;
    else
        cout << temp << "   " << space << star << '|' << endl;
}
void posStarAmount()
{
    int x = temp / 3;
    for (int i = 0; i < x; i++)
        star = star + '*';
    posSide();
    star.clear();
}

void negStarAmount()
{
    int x = (temp*-1 )/ 3;
    for (int i = 0; i < x; i++)
        star = star + '*';
    
    if (temp % 3 > 1)
        star = star + '*';
    
    negSide();
    star.clear();
}
