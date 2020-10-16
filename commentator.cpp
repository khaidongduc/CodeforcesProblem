/// https://codeforces.com/problemset/problem/2/C

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;
struct nod {
    double x,y,r;
}c[3];
double ang[3];
const int dy[4]={-1,0,0,1};
const int dx[4]={0,-1,1,0};
double po(double x) {
    return x*x;
}
 double dis (double x, double y, double xx, double yy) {// find the distance
    return sqrt(po(x-xx)+po(y-yy));
}
 double val (double x, double y) {// valuation function
         for (int i = 0; i <3; ++ i) ang [i] = dis (x, y, c [i] .x, c [i] .y) / c [i] .r; // comparison with Comparative angle value sin
    double v=0;
         for (int i = 0; i <3; ++ i) v += po (ang [i] -ang [(i + 1)% 3]); // with the square of the difference as a cost function and
         return v; // this value is smaller, closer to 0, the closer the angle of view three circles
}
int main() {
    double x=0,y=0;
    for(int i=0;i<3;i++) {
        scanf("%lf%lf%lf",&c[i].x,&c[i].y,&c[i].r);
        x+=c[i].x/3;
                 y += c [i] .y / 3; // first center of gravity as a near optimal solution
    }
    double err=val(x,y);
    double step=1;
         for (int tim = 1; tim <= 1e5; ++ tim) {// five decimal precision
        bool flag=0;
        double X,Y;
                 for (int i = 0; i <4; ++ i) {// advance to the four directions
            double xx=x+dx[i]*step,yy=y+dy[i]*step;
            double v=val(xx,yy);
                         if (v <err) {// If found, continue to follow
                err=v;
                flag=1;
                X=xx;Y=yy;
            }
        }
        if(flag) {
            x=X;
            y=Y;
        }
                 else step /= 2; // half step
    }
    if(err<1e-6) printf("%.5lf %.5lf\n",x,y);
    return 0;
}