#include <iostream>
#include <string>
using namespace std;

int main()
{

string input;

cout << "input comand from choices [-d, -f, -b]: " << endl;
cin >> input;

if(input == "-d")
{cout << "directories" << endl;}
else if (input == "-f")
{cout << "file" << endl;}
else if (input == "-b")
{cout << "bytes" << endl;}
else
{cout << "invalid!" << endl; }

return 0;
}

