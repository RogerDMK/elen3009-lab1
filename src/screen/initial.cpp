#include "screen.h"
#include <iostream>

using namespace std;

int main()
{
	auto myScreen = Screen{6,6};
    myScreen.clear(' '); // Set background to ' '
    myScreen.set("****"); // Top line of R
    myScreen.move(2,1); // start of second row
    myScreen.set('*');
    myScreen.move(2,5); // end of second row
    myScreen.set('*');
    myScreen.move(3,1); //bottomw horizontal line of R
    myScreen.set("****");
    myScreen.move(6,1); // left horizontal line
    myScreen.set("*");
    myScreen.move(6,5); // diagonal bottom
    myScreen.set('*');
    myScreen.move(5,1); // left horizontal line
    myScreen.set("*");
    myScreen.move(5,4); // diagonal middle
    myScreen.set('*');
    myScreen.move(4,1); // left horizontal line
    myScreen.set("*");
    myScreen.move(4,3); // diagonal top
    myScreen.set('*');
    myScreen.display();
    return 0;
}