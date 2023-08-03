#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main() {
    ifstream inputFile("file2.txt");
    string version;

    if (inputFile.is_open()) {
        getline(inputFile, version);
        inputFile.close();

        int loc = version.rfind('.'); // Find the last occurrence of '.'
        if (loc != string::npos) {//if no position(matches) is false means matches is found
            /*npos means no matche were found in string; if true no matches*/
            string str = version.substr(loc + 1); // Get the substring after '.'
            int versionNumber = stoi(str); // Convert the substring to an integer
            ++versionNumber; // Increment the version number

            // Write the updated version back to the file
            ofstream outputFile("file2.txt");
            if (outputFile.is_open()) {
                outputFile << version.substr(0, loc + 1) << versionNumber;
                outputFile.close();
                cout << "Version incremented to: " << version.substr(0, loc + 1) << versionNumber << endl;
            } else {
                cerr << "Error opening output file." << endl;
                return 1;
            }
        } else {
            cerr << "Invalid version format." << endl;
            return 1;
        }
    } else {
        cerr << "Error opening input file." << endl;
        return 1;
    }

    return 0;
}
