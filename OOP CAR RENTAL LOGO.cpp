#include<iostream>
#include <windows.h>
using namespace std;


void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
int main() {
    // Printing the logo with colors using SetConsoleTextAttribute
    setColor(13);
   cout << "*********************************************************************************" << endl;

    setColor(9);  
    cout << "           __   __         _   _         _     _   " <<endl;
    cout << "           |  \\/  |       | \\ | |       | |   | |  " << endl;
    cout << "           | |\\/| |       |  \\| |       | |   | |  " << endl;
    cout << "           | |  | |       | |\\  |       | |___| |  " << endl;
    cout << "           |_|  |_|       |_| \\_|        \\_____/   " << endl;


    setColor(13); 
   cout << "*********************************************************************************" << endl;
    cout << endl;

 
    setColor(3); 
    cout << "     Welcome to MnU rental cars ";
    setColor(11);
    cout << "by Mahnoor & Urooj" << endl;
    setColor(3);
    cout << "     Your journey starts here  'Ride in style, Drive with pride!'" << endl;
    cout << endl;



    setColor(13); 
    cout << "*********************************************************************************" << endl;
}







