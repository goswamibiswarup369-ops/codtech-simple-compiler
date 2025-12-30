#include <iostream>
#include <fstream>
using namespace std;

int main() {
    // Write to file
    ofstream writeFile("sample.txt");
    writeFile << "This is the first line written to the file.\n";
    writeFile.close();

    // Append to file
    ofstream appendFile("sample.txt", ios::app);
    appendFile << "This line is appended to the file.\n";
    appendFile.close();

    // Read from file
    ifstream readFile("sample.txt");
    string line;
    cout << "Reading file content:\n";
    while (getline(readFile, line)) {
        cout << line << endl;
    }
    readFile.close();

    return 0;
}