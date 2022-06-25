#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{

    // Basic Variables declaration
    int nop;
    int nos;
    int sum = 0;
    int cutoff;

    cout << "Welcome to Administrative program" << endl
         << "Enter the Number of students: " << endl;
    cin >> nop;
    
    cout << "Enter the number of Subjects: " << endl;
    cin >> nos;
    
    // Declaring necessary Variables and arrays
    string name, spam;
    string names[nop];
    string transfer_str;
    long int subjects[nop][nos + 2];
    int transfer[1][nos + 2];
    getline(cin, spam);
    
    cout<<endl;
    cout << "Enter the Names of the students and their subjects in the respective Marks (out of 100)" << endl
         << "If any mistake is made, input next name as 'redo'." << endl;
    cout<<endl;
    // Taking input of Names and their respective Marks
    for (int i = 0; i < nop; i++)
    {
        cout << "Name: ";
        getline(cin, name);
        names[i] = name;

        if (name == "redo")
        {
            cout << "Re enter the previous Name and Marks " << endl
                 << "Name: ";
            i--;
            getline(cin, name);
            names[i] = name;
        }

        cout << "Subject Marks of " << name << " (in order):" << endl;
        for (int j = 0; j < nos; j++)
        {
            cout<<"Subject "<<(j+1)<<" marks:"<<endl;
            cin >> subjects[i][j];
        }
        cout << "------------------------------------" << endl;
        getline(cin, spam);
    }

    cout << endl
         << "Input complete..." << endl
         << "Processing total marks out of " << (nos * 100) << endl;

    // Finding the Sum of marks
    for (int k = 0; k < nop; k++)
    {
        for (int l = 0; l < nos; l++)
        {
            sum += subjects[k][l];
        }
        subjects[k][nos] = sum;
        subjects[k][nos + 1] = (sum / nos);
        sum = 0;
    }

    for (int time = 0; time <= 100000; time++)
    {
    }

    // Asking for Cutoff
    cout << endl
         << "Enter the cutoff marks (out of " << (nos * 100) << "):" << endl;
    cin >> cutoff;

    // Sorting the marks according to total
    for (int m = 0; m < (nop - 1); m++)
    {
        for (int n = 0; n < (nop - 1 - m); n++)
        {
            if (subjects[n][nos] > subjects[n + 1][nos])
            {
                transfer_str = names[n];
                names[n] = names[n + 1];
                names[n + 1] = transfer_str;

                for (int o = 0; o < (nos + 2); o++)
                {
                    transfer[1][o] = subjects[n][o];
                    subjects[n][o] = subjects[n + 1][o];
                    subjects[n + 1][o] = transfer[1][o];
                }
            }
        }
    }

    // Printing out the table with grades:
    //  A+ = >=95%
    //  A  = >=90%
    //  B+ = >=85%
    //  B  = >=80%
    //  C+ = >=75%
    //  C  = >=70%
    //  D  = >=60%
    //  E  = >=50%
    //  F  = >=0%

    cout << "The Students that clear the cutoffs are:" << endl;
    cout << left;
    cout << setfill('.');
    int q = 1;
    string grade = "error";
    cout << endl
         << "S.no.." << setw(30) << "Name " << setw(10) << "Total M" << setw(10) << "Grade" << endl;
    for (int p = (nop - 1); p >= 0; p--)
    {
        if (subjects[p][nos] >= cutoff)
        {
            if (subjects[p][nos + 1] >= 95)
            {
                grade = "A+";
            }
            else if (subjects[p][nos + 1] >= 90)
            {
                grade = "A";
            }
            else if (subjects[p][nos + 1] >= 85)
            {
                grade = "B+";
            }
            else if (subjects[p][nos + 1] >= 80)
            {
                grade = "B";
            }
            else if (subjects[p][nos + 1] >= 75)
            {
                grade = "C+";
            }
            else if (subjects[p][nos + 1] >= 70)
            {
                grade = "C";
            }
            else if (subjects[p][nos + 1] >= 60)
            {
                grade = "D";
            }
            else if (subjects[p][nos + 1] >= 50)
            {
                grade = "E";
            }
            else
            {
                grade = "F";
            }

            cout << (q) << ")...." << setw(30) << names[p] << setw(10) << subjects[p][nos] << setw(10) << grade << endl;
            q++;
        }
    }

    return 0;
}
