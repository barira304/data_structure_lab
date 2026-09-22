
#include <iostream>
using namespace std;

int main()
{
    int marks[6][4] = {
        {85, 90, 78, 88},
        {75, 80, 85, 70},
        {92, 95, 90, 94},
        {60, 65, 70, 68},
        {88, 82, 91, 86},
        {70, 75, 80, 78}
    };

    string subjects[4] = {
        "English",
        "Mathematics",
        "Programming",
        "AI"
    };

    int totals[6];
    float averages[6];

    cout << "Student Marks Table\n\n";

    cout << "Student\tEnglish\tMath\tProgramming\tAI\n";

    for (int i = 0; i < 6; i++)
    {
        cout << "Student " << i + 1 << "\t";

        for (int j = 0; j < 4; j++)
        {
            cout << marks[i][j] << "\t";
        }

        cout << endl;
    }

    cout << "\nTotal and Average Marks\n\n";

    for (int i = 0; i < 6; i++)
    {
        totals[i] = 0;

        for (int j = 0; j < 4; j++)
        {
            totals[i] += marks[i][j];
        }

        averages[i] = totals[i] / 4.0;

        cout << "Student " << i + 1
             << " - Total: " << totals[i]
             << ", Average: " << averages[i] << endl;
    }

    cout << "\nHighest Marks in Each Subject\n\n";

    for (int j = 0; j < 4; j++)
    {
        int highest = marks[0][j];

        for (int i = 1; i < 6; i++)
        {
            if (marks[i][j] > highest)
            {
                highest = marks[i][j];
            }
        }

        cout << subjects[j] << ": " << highest << endl;
    }

    int highestTotal = totals[0];
    int highestStudent = 0;

    for (int i = 1; i < 6; i++)
    {
        if (totals[i] > highestTotal)
        {
            highestTotal = totals[i];
            highestStudent = i;
        }
    }

    cout << "\nStudent with Highest Total Marks\n";
    cout << "Student " << highestStudent + 1
         << " has the highest total marks: "
         << highestTotal << endl;

    return 0;
}

