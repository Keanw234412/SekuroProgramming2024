#include<iostream> 

using namespace std;
class Shape
{
private:
    float area;
    float keliling;

public:
    virtual float calculateArea() 
    {
        return 0;
    }
    virtual float calculateKeliling() 
    {
        return 0;
    }
};
class Rectangle : public Shape
{
private : 
    float width;
    float length;

public:
    Rectangle(float width, float length)
    {
        this-> width = width;
        this-> length = length;
    }
    float calculateArea()
    {
        return this->width * this->length;
    }
    float calculateKeliling()
    {
        return 2 * (this->width + this-> length);
    }
};
int main() 
{
    Rectangle rect(5.0, 4.0);
    Shape* shape1 = &rect ;

    cout << "Area : " << shape1->calculateArea() << "\n";
    cout << "Keliling : " << shape1->calculateKeliling() << "\n";
    return 0;
}