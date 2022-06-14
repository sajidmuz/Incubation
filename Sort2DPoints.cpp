/*
  Sort 2d points 

Write a program which will sort the list of 2d points based on distance from the origin 
There should be a command-line interface which will accept file path as input 
There should be a command-line interface which will accept a path to write the output file 
You have to decide the schema of the text file in which 2d points are stored;; 
You have to write a list in a file and stored it at provided output path 
Output file should contain a list of point with distance form origin 
Consider all possible test cases 
*/


//Code

/*
  Schema
  -------
    Input file := x y
                  1 2
                  3 4
     Here x and y are co-ordinates
     
    Output filr := Distance   Co-ordinates
                   5            3 4
                   13           12 5
*/



#include<iostream>
#include<cstdlib>
#include<fstream>
#include<sstream>
#include<string>
#include<cstring>
#include<cmath>
#include<iomanip>
#include<map>
using namespace std;


int main()
{
    string inputFile;
    string outputFile;
    fstream inputFileStream;
    fstream outputFileStream;
    map<double, string> mp;

    cout << "Enter file path to read " << endl;
    cin >> inputFile;
    cout << endl;

    cout << "Enter file path to write " << endl;
    cin >> outputFile;

    //Read file and put 2DPoints in a map
    inputFileStream.open(inputFile, ios::in);
    if(inputFileStream.is_open()){
        string line;
        string word;

        double x = -1; // X Co-ordiate
        double y = 0;  // Y Co-ordinate
        double dist = 0;  // Distance from origin to point
        
        while (getline(inputFileStream, line)){             // Fetch one line at a time
            stringstream ss(line);
            while (ss >> word){                             //Split lines into words 
                x == -1 ? x = stoi(word) : y = stoi(word);  // Put those words in X and Y variable
            }
            dist = sqrt(pow(x, 2) + pow(y, 2));             //Find distance b/w origin and points
            x=-1;                                           // For next iteration reset value of x
            mp.insert({dist,line});                         // Insert Didtance and line in map
        }
        inputFileStream.close();
    }


    //Write sorted data in a output file
    outputFileStream.open(outputFile, ios::out);
    if(outputFileStream.is_open()){
        map<double, string>::iterator itr;
        for(itr=mp.begin(); itr!=mp.end(); ++itr){
            outputFileStream << itr->first <<"\t\t"<<itr->second<<endl;
        }
        outputFileStream.close();
    }
    
   return 0;
}
