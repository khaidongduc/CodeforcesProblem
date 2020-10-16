#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <string.h>
#include <algorithm>

using namespace std;

const double pi = acos(-1);

double mod(double a, double b){
    return a - (int)(a / b) * b;
}

double gcd(double x, double y){
    if (y <= 0.0001)
        return x;
    return gcd(y, mod(x, y));
}
int main(){
    double x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    
    double a = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    double b = sqrt((x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3));
    double c = sqrt((x2 - x3) * (x2 - x3) + (y2 - y3) * (y2 - y3));
    double p = (a + b + c) / 2;
    double r = (a * b * c) / (4 * sqrt(p * (p - a) * (p - b) * (p - c)));
    
    double angle1 = acos(1 - (a * a) / (2 * r * r));
    double angle2 = acos(1 - (b * b) / (2 * r * r));
    double angle3 = 2 * pi - angle1 - angle2;
    double angle = gcd(angle1, gcd(angle2, angle3)) / pi * 180; 
    
    double side = sqrt(2 * r * r - 2 * r * r * cos(angle / 180 * pi));
    double P = (r * 2 + side) / 2;
    double s = sqrt(P * (P - r) * (P - r) * (P - side)) * (360 / angle);

    cout << fixed << setprecision(6) << s;
}