
#include <iostream>
#include <string>
using namespace std;

// ANSI color codes
namespace Color {
    const string RESET   = "\033[0m";
    const string RED     = "\033[31m";
    const string GREEN   = "\033[32m";
    const string YELLOW  = "\033[33m";
    const string BLUE    = "\033[34m";
    const string PURPLE  = "\033[35m";
    const string CYAN    = "\033[36m";
    const string WHITE   = "\033[37m";
}

// Print text with color
void printColor(const string& text, const string& color) {
    cout << color << text << Color::RESET << endl;
}

int main() {
    printColor("Error Message", Color::RED);
    printColor("Success Message", Color::GREEN);
    printColor("Warning Message", Color::YELLOW);
    printColor("Information", Color::BLUE);
    printColor("Purple Text", Color::PURPLE);
    printColor("Cyan Text", Color::CYAN);

    return 0;
}
