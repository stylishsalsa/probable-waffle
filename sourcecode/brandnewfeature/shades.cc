
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// RGB Color Structure
struct RGB {
    int r, g, b;
};

// Set terminal foreground color
void setColor(int r, int g, int b) {
    cout << "\033[38;2;"<< clamp(r, 0, 255) << ";"
         << clamp(g, 0, 255) << ";"
         << clamp(b, 0, 255) << "m";
}

// Reset terminal color
void resetColor() {
    cout << "\033[0m";
}

// Generate a lighter shade
RGB lighten(RGB color, float amount) {
    amount = clamp(amount, 0.0f, 1.0f);

    return {
        int(color.r + (255 - color.r) * amount),
        int(color.g + (255 - color.g) * amount),
        int(color.b + (255 - color.b) * amount)
    };
}

// Generate a darker shade
RGB darken(RGB color, float amount) {
    amount = clamp(amount, 0.0f, 1.0f);

    return {
        int(color.r * (1 - amount)),
        int(color.g * (1 - amount)),
        int(color.b * (1 - amount))
    };
}

// Display a color shade
void showShade(const string& name, RGB color) {
    setColor(color.r, color.g, color.b);
    cout << name << " - RGB("
         << color.r << ", "
         << color.g << ", "
         << color.b << ")" << endl;
    resetColor();
}

int main() {
    RGB baseColor = {100, 150, 255};

    cout << "=== Color Shades ===" << endl;

    showShade("Original", baseColor);
    showShade("Light 25%", lighten(baseColor, 0.25f));
    showShade("Light 50%", lighten(baseColor, 0.50f));
    showShade("Light 75%", lighten(baseColor, 0.75f));

    showShade("Dark 25%", darken(baseColor, 0.25f));
    showShade("Dark 50%", darken(baseColor, 0.50f));
    showShade("Dark 75%", darken(baseColor, 0.75f));

    return 0;
}
