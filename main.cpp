
#include <iostream>
#include <string>
using namespace std;

string binExplorer(int number)
{
    if (number == 0) return "";
    return binExplorer(number >>= 1) + to_string(number & 0x01);
}

string hexExplorer(int number)
{
    if (number == 0) return "";
    string residue = to_string(number & 0xF);
    
    if (residue == "10") residue = "A";
    if (residue == "11") residue = "B";
    if (residue == "12") residue = "C";
    if (residue == "13") residue = "D";
    if (residue == "14") residue = "E";
    if (residue == "15") residue = "F";
    
    return hexExplorer(number >> 4) + residue;
}

string bin(int number)
{
    return "0b" + binExplorer(number);
}

string hex(int number)
{
    return "0x" + hexExplorer(number);
}

int main()
{
    int a[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,255};
    
    for (int i : a)
    {
        cout << i << " ";
        cout << bin(i) << " ";
        cout << hex(i) << endl;
    }

    return 0;
}