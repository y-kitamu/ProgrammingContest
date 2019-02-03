#include <iostream>
#include <cmath>


void kochCurve(int n, double startx, double starty, double endx, double endy) {
    if (n == 0) {
        std::cout << endx << " " << endy << std::endl;
        return;
    }

    double dx = (endx - startx) / 3, dy = (endy - starty) / 3;
    double p1x = startx + dx, p1y = starty + dy;
    double p2x = p1x + dx * 0.5 - dy * 0.5 * std::sqrt(3);
    double p2y = p1y + dx * 0.5 * std::sqrt(3) + dy * 0.5;
    double p3x = endx - dx, p3y = endy - dy;
    
    kochCurve(n - 1, startx, starty, p1x, p1y);
    kochCurve(n - 1, p1x, p1y, p2x, p2y);
    kochCurve(n - 1, p2x, p2y, p3x, p3y);
    kochCurve(n - 1, p3x, p3y, endx, endy);
}


int main() {
    int n;
    std::cin >> n;

    std::cout << 0.0 << " " << 0.0 << std::endl;
    kochCurve(n, 0.0, 0.0, 100.0, 0.0);
}
