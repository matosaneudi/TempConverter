#include <iostream>
#include <fstream>
#include <string>
using namespace std; 

/*
read from the text file and save data into variables 
then close the file 
*/

/*
write to a new file named CelsiusTemperature.txt
before closing the file convert the F to C 
C = (F - 32)*(5/9)
*/

// convert Fahrenheit to Celsius 
int FahrenheitToCelsius(int tempF) {
    return static_cast<int>((tempF - 32) * 5.0 / 9.0);
    }
int main(){
    string city; 
    int tempF;
    int tempc;
    ifstream inFS;
    
    ifstream inFile("FahrenheitTemperature.txt"); // opens the file for reading. 
    ofstream outFile("CelsiusTemperature.txt"); // opens a new file for writing. 
    
    if (!inFile.is_open()) { // check if there was an error opening the file. 
        cout << "Could not open file" << endl;
        return 1; // indicates there was an error. 
    }

    while (!inFile.eof()) { //runs until it reaches the end of the file. 
        inFile >> city; 
        inFile >> tempF;

        if (!inFile.fail()){ //when its done reading the file it fails and then outputs the data. 

            int tempC = FahrenheitToCelsius(tempF); // calls the conversion function and stores the converted data in tempC.

            outFile << city << " " << tempC << endl; // writes the data into CelsiusTemperature.txt.
        }
    }
    inFile.close(); // close the "FahrenheitTemperature.txt"
    outFile.close(); //close the "CelsiusTemperature.txt"
    
    return 0;
}
