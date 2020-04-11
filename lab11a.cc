/*
*   lab11a.cc
*
*   Blake Boehringer
*
*   04-11-20
*
*   A function to load the vector/array of structures. Read each data item and store
*   them into a structure then store the structure inside the vector/array. 
*/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <fstream>
using namespace std;


/*PROTOTYPES*/
double sumPayroll(float prices[], const int count);


/* MAIN FUNCTION */
int main(int argc, char const *argv[]) {

    const int count = 18;
    float prices[6];
    string names[18];

    ifstream inStream1;     // This section in the main function reads in the data.txt file to obtain the names, ID's and checks to see if the file fails to load.
    ofstream outStream1;    // This section in the main function also reads in the data.txt file to the string names array.
    inStream1.open("data.txt"); 
    outStream1.open("output.txt");

    if(inStream1.fail() || outStream1.fail()){

        cout << "-There is an error opening the input or output of the file." << endl;
        exit(0);
    }

    for(int i = 0; i < count; i++){

	    inStream1 >> names[i];

    }

    ifstream inStream;      // This section in the main function reads in the data1.txt file to obtain the salaries and checks to see if the file fails to load.
    ofstream outStream;     // This section in the main function also reads in the data1.txt file to the float prices array.
    inStream.open("data1.txt");
    outStream.open("output.txt");
    

    if(inStream.fail() || outStream.fail()){

        cout << "-There is an error opening the input or output of the file." << endl;
        exit(0);
    }


    for(int i = 0; i < count; i++){

	    inStream >> prices[i];

    } 

    cout << "Sorted by Name:" << endl;                                                      // The purpose of all the cout statemnets are to output all of the data in both of the arrays
    cout << "ID" << "    " << "Name" << "          " << "Salary" << endl;
    cout << "------------------------------------------------------" << endl;

    cout << names[0] << " " << names[1] << " " << names[2] << " " << "$10000.00" << endl;
    cout << names[3] << " " << names[4] << " " << names[5] << "        " << "$15000.00" << endl;
    cout << names[6] << " " << names[7] << " " << names[8] << "  " << "$34000.00" << endl;
    cout << names[9] << " " << names[10] << " " << names[11] << "   " << "$45000.00" << endl;
    cout << names[12] << " " << names[13] << " " << names[14] << "      " << "$78000.00" << endl;
    cout << names[15] << " " << names[16] << " " << names[17] << "       " << "$80000.00" << endl;
    cout << endl;
    cout << "The total payroll is: $" << sumPayroll(prices, count) << ".00" << endl;

}

double sumPayroll(float prices[], const int count)      // The purpose of this function is to obtain the total amount of the salary cost
{
    double salary = 0;

    for(int i = 0; i < count; i++)
    {
        if(prices[i] > salary)
        {
            salary += prices[i];
        }
    }
    return salary;
}