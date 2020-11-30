#include <math.h>
#include <stdio.h>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("main.inp", "r", stdin);
#endif
    double accel, maxSpeed;
    double roadLength, signPlacement, signSpeed;
    // input
    scanf("%lf %lf", &accel, &maxSpeed);
    scanf("%lf %lf %lf", &roadLength, &signPlacement, &signSpeed);

    double ans = 0.0;
    if (maxSpeed <= signSpeed) {
        double timeMaxSpeed = 1.0 * maxSpeed / accel;
        double lengthMaxSpeed = 0.5 * accel * timeMaxSpeed * timeMaxSpeed;
        if (lengthMaxSpeed > roadLength) {
            ans = sqrt(2 * roadLength / accel);
        } else {
            ans = timeMaxSpeed + 1.0 * (roadLength - lengthMaxSpeed) / maxSpeed;
        }
    } else {
        double t1 = sqrt(2 * signPlacement / accel);
        if (t1 * accel <= signSpeed) {
            t1 = maxSpeed / accel;
            double x1 = 0.5 * accel * t1 * t1;
            if (x1 >= roadLength) {
                ans = sqrt(2 * roadLength / accel);
            } else {
                double x2 = roadLength - x1;
                double t2 = x2 / maxSpeed;
                ans = t1 + t2;
            }
        } else {
            double det = sqrt(2 * signSpeed * signSpeed + 4 * accel * signPlacement);
            double t2 = (det - 2 * signSpeed) / (2 * accel);
            if (signSpeed + accel * t2 <= maxSpeed) {
                t1 = (signSpeed + accel * t2) / accel;
                ans = t1 + t2;
            } else {
                t1 = maxSpeed / accel;
                t2 = (maxSpeed - signSpeed) / accel;
                double x1 = 0.5 * accel * t1 * t1 + maxSpeed * t2 - 0.5 * accel * t2 * t2;
                double x2 = signPlacement - x1;
                ans = t1 + t2 + x2 / maxSpeed;
            }

            t1 = (maxSpeed - signSpeed) / accel;
            double x1 = signSpeed * t1 + 0.5 * accel * t1 * t1;
            if (x1 > (roadLength - signPlacement)) {
                det = sqrt(signSpeed * signSpeed + 2 * accel * (roadLength - signPlacement));
                ans += (det - signSpeed) / accel;
            } else {
                ans += t1;
                double x2 = roadLength - signPlacement - x1;
                ans += (x2 / maxSpeed);
            }
        }
    }
printAns:
    printf("%0.5f", ans);
}