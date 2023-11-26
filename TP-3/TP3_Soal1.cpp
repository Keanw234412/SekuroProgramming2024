#include <iostream> 

using namespace std;

class LinearLine 
{
private:
    float x1;
    float x2; 
    float y1; 
    float y2;

 public:
    LinearLine(float x1, float y1, float x2, float y2){
        this-> x1 = x1;
        this-> x2 = x2;
        this-> y1 = y1;
        this-> y2 = y2;
    }
    LinearLine() = default ;
    float gradient(){
        float hasil;
        hasil = (this->y2 - this-> y1) / (this-> x2 - this-> x1);
        return hasil;
    }
    float y_intercept ()
    {
        return -(gradient() * this-> x1) + this-> y1;
    }
    void operator + (float a)
    {
        this-> x1 =  x1 + a;
        this-> x2 = x2+ a;
    }

    void printEquation()
    {
        cout <<"y = " << gradient()<<" x + "<<y_intercept()<<endl;
    }

    void printPoints() 
    {
        cout << "(x1, y1) = (" << this->x1 << ", " << this-> y1 << ")\n";
        cout << "(x2, y2) = (" << this->x2 << ", " << this-> y2 << ")\n";
        
    }
};

int main() 
{
    LinearLine line(1.0f, 8.0f, 2.0f, 3.0f);
    int a= 3;
    line.printPoints();
    cout << "Sehingga didapatkan\n";
    cout << "gradient = "<<line.gradient()<<endl;
    cout << "y_intercept = "<< line.y_intercept()<<endl;
    line.printEquation();

    cout << "\n\n";
    cout << "Setelah digeser sejauh a, didapatkan persamaan baru:\n";
    line.operator+(a);
    line.printEquation();
    return 0;
}