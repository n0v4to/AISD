#include <iostream>
#include "image.h"
#include <random>
using namespace std;

int main()
{
    int size_x, size_y;
    cout << "Enter the dimensions of the field" << endl;
    cout << "a: ";
    cin >> size_x;
    cout << "b: ";
    cin >> size_y;
    Image<bool> a(size_x, size_y, false);
    double x1, y1;
    cout << "Enter the coordinates of top left point" << endl;
    cout << "x: ";
    cin >> x1;
    cout << "y: ";
    cin >> y1;
    double x2, y2;
    cout << "Enter the coordinates of down right point" << endl;
    cout << "x: ";
    cin >> x2;
    cout << "y: ";
    cin >> y2;


    for (int i = 0; i < size_x; i++) {
        for (int j = 0; j < size_y; j++) {
            if ((i >= x1 && j >= y1) && (i <= x2 && j <= y2)) {
                a(i, j) = 1;
            }
        }
    }
    cout << a;
}