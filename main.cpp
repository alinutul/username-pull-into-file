#include <iostream>
#include <fstream>
using namespace std;

#include <windows.h>
#include <Lmcons.h>

int main()
{
TCHAR name [ UNLEN + 1 ];
DWORD size = UNLEN + 1;

if (GetUserName( (TCHAR*)name, &size ))
wcout << L"Hello, " << name << L"!\n";
else
cout << "Hello, NONAME";
    std::string filename = "output.txt";
    std::ofstream outputFile(filename);
    if (outputFile.is_open()) {
        // Redirect the standard output stream (cout) to the file
        std::streambuf* originalCoutBuffer = std::cout.rdbuf(outputFile.rdbuf());
        std::cout <<"Hello, "<<name<<"!"<< std::endl;

        // Restore the original cout buffer to print to the console again
        std::cout.rdbuf(originalCoutBuffer);
        outputFile.close();
    } else {
        std::cerr << "Error: Unable to open the output file." << std::endl;
        return 1;
    }
    return 0;
}
