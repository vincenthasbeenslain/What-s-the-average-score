/** Vincent Nguyen
    Febrauary 18, 2018
    The program reads four scores and drops the highest
    and lowest scores to find the average of the two
    remaining scores.
*/

#include <iostream>
#include <iomanip>
using namespace std;

void getJudgeData(int &);
void calcScore(int &, int &, int &, int &);
double findLowest(int &, int &, int &, int &);
double findHighest(int &, int &, int &, int &);

int main()
{
    int judge1, judge2, judge3, judge4;

    getJudgeData(judge1);

    getJudgeData(judge2);

    getJudgeData(judge3);

    getJudgeData(judge4);

    calcScore (judge1, judge2, judge3, judge4);


}

void getJudgeData(int &score)
{
    cout << "Enter the judge's score: ";
    cin >> score;
    while (score < 0 || score > 20)
    {
        cout << "That is an invalid score. Please try again.\n"
             << "The score must be from 0 to 20.\n"
             << "Enter the judge's score: ";
        cin >> score;
    }
}

double findLowest(int &n1, int &n2, int &n3, int &n4)
{
    int lowest = n1;
    if (n2 < lowest)
        lowest = n2;
    if (n3 < lowest)
        lowest = n3;
    if (n4 < lowest)
        lowest = n4;
    return lowest;
}

double findHighest(int &n1, int &n2, int &n3, int &n4)
{
    int highest = n1;
    if (n2 > highest)
        highest = n2;
    if (n3 > highest)
        highest = n3;
    if (n4 > highest)
        highest = n4;
    return highest;
}

void calcScore(int &n1, int &n2, int &n3, int &n4)
{
    int highest, lowest;
    double num1, num2;
    highest = findHighest(n1, n2, n3, n4);
    lowest = findLowest (n1, n2, n3, n4);

    if (n1 == highest || n1 == lowest)
    {
        if (n2 == lowest || n2 == highest)
        {
            num1 = n3;
            num2 = n4;
        }
        if (n3 == lowest || n3 == highest)
        {
            num1 = n2;
            num2 = n4;
        }
        if (n4 == lowest || n4 == highest)
        {
            num1 = n2;
            num2 = n3;
        }
    }

    if (n2 == highest || n2 == lowest)
    {
        if (n1 == lowest || n1 == highest)
        {
            num1 = n3;
            num2 = n4;
        }
        if (n3 == lowest || n3 == highest)
        {
            num1 = n1;
            num2 = n4;
        }
        if (n4 == lowest || n4 == highest)
        {
            num1 = n1;
            num2 = n3;
        }
    }

    if (n3 == highest || n3 == lowest)
    {
        if (n2 == lowest || n2 == highest)
        {
            num1 = n1;
            num2 = n4;
        }
        if (n1 == lowest || n1 == highest)
        {
            num1 = n2;
            num2 = n4;
        }
        if (n4 == lowest || n4 == highest)
        {
            num1 = n2;
            num2 = n1;
        }
    }

    cout << setprecision(1) << fixed << "The performer's final score is "
         << (num1 + num2) / 2 << ".";


/** Sample run:
Enter the judge's score: 6
Enter the judge's score: 70
That is an invalid score. Please try again.
The score must be from 0 to 20.
Enter the judge's score: 19
Enter the judge's score: 10
Enter the judge's score: 8
The performer's final score is 9.0.
Process returned 0 (0x0)   execution time : 11.771 s
Press any key to continue.
*/
}
