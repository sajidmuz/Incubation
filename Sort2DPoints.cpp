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
#include<vector>
using namespace std;


class Sort2DPoints
{
private:
    map<double, vector<string>> mp;
    

    //Find distance from origin
    double findDistance(double x, double y){return sqrt(pow(x, 2) + pow(y, 2));}

    //Read file and put 2DPoints in a map
    void readFile(string inputFile)
    {
        fstream inputFileStream;
        inputFileStream.open(inputFile, ios::in);
        if(inputFileStream.is_open()){
            string line;        // Store one line at one iteration
            string word;        // Store one co-ordinate at one iteraton
            string distTostr;   // Store distance in string form 

            double x = -1;      // X Co-ordiate
            double y = 0;       // Y Co-ordinate
            double dist = 0;    // Distance from origin to point
            bool flag = true;

            while (getline(inputFileStream, line)){             // Fetch one line at a time
                stringstream ss(line);
                while (ss >> word){
                    if(flag){x = stod(word); flag=false;}         //Split lines into words 
                    else{y = stoi(word);}                       // Put those words in X and Y variable
                }
        
                dist = findDistance(x,y);                       //Find distance b/w origin and points
                flag = true;                                    // For next iteration flag must be true
                distTostr = to_string(dist); 
                vector<string> res {distTostr,line};            //Put distance and points in vector
                auto i = mp.find(dist);                         // Check key value for uniqueness
                i == mp.end() ? mp.insert({dist, res}) : mp.insert({dist+0.001, res});
                                                            // Insert Didtance and line in map
            }
            inputFileStream.close();
        }
    }
  
    //Write sorted data in a output file
    void writeFile(string outputFile)
    {
        fstream outputFileStream;
        outputFileStream.open(outputFile, ios::out);
        if(outputFileStream.is_open()){
            map<double, vector<string>>::iterator itr;
            outputFileStream << "Distance" <<"\t\t"<< "Points" << endl;
            outputFileStream << "--------" <<"\t\t"<< "------" << endl << endl;
            for(itr=mp.begin(); itr!=mp.end(); ++itr){
                outputFileStream << itr->second[0] <<"\t\t" << itr->second[1] <<endl;
            }
            outputFileStream.close();
        }
    }

public:

    Sort2DPoints(){}
    void getSorted2Points(string inputFile, string outputFile)
    {
        readFile(inputFile);
        writeFile(outputFile);
    }

    //~Sort2DPoints();
};




int main()
{
    string inputFile;
    string outputFile;

    cout << "Enter file path to read " << endl;
    cin >> inputFile;
    cout << endl;

    cout << "Enter file path to write " << endl;
    cin >> outputFile;

    Sort2DPoints points;
    points.getSorted2Points(inputFile, outputFile);

    return 0;
}
