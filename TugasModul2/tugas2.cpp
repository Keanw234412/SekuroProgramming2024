#include<bits/stdc++.h>
using namespace std;

float x=0.00, y=0.00;

void lokasi()
{
    cout << "("<<setprecision(3) << x << ", " << setprecision(3) << y<< ")" << endl;
    return ;
}
float gerak(float delta_x, float delta_y)
{
    x += delta_x;
    y += delta_y;
    return x,y;
}
int main()
{
    gerak(4,2);
    gerak(-3, -1);
    lokasi();

    return 0;
}