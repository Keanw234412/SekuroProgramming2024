#include<bits/stdc++.h>
#include<vector>

using namespace std;
class Matrix
{
private:
    vector<vector<float>>matriks;

public:
    int kolom, baris;

    Matrix(vector<vector<float>> & input_matriks) : matriks(input_matriks){
        baris = input_matriks.size();
        kolom = input_matriks[0].size();
    }
    Matrix(int r, int c): baris(r), kolom(c), matriks(vector<vector<float>>(r, vector<float>(c,0))){}

    Matrix operator+(const Matrix& other  )
    {
        if(baris != other.baris || kolom != other.kolom){
            cout << "The matrix dimension is not valid!\n";
            Matrix hasil(1,1);
            hasil.matriks[0][0] = 0 ;
            return hasil ;  
        }
        else
        {
            Matrix hasil(baris, kolom);
            for (int i = 0; i<baris;i++)
            {
                for (int j = 0; j < kolom; j++)
                {
                    hasil.matriks[i][j] = matriks[i][j] + other.matriks[i][j];
                }
            }
            return hasil;
        }
    }

    Matrix operator-(const Matrix &other)
    {
        if(baris != other.baris || kolom != other.kolom){
            cout << "The matrix dimension is not valid!\n";
            Matrix hasil(1,1);
            hasil.matriks[0][0] = 0 ;
            return hasil ;
        }
        else {
            Matrix hasil(baris, kolom);
            for(int i = 0 ; i<baris; i++)
            {
                for(int j = 0 ; j < kolom; j++)
                {
                    hasil.matriks[i][j] = matriks[i][j] - other.matriks[i][j];
                }
            }
            return hasil ;
        }
    }
    Matrix operator* (const Matrix & other ) {
        if (kolom != other.baris)
        {
            cout << "Multiplication cannot be done. The number of columns in \nthe first matrix should be equal to the number of rows in \nthe second.\nReturn 1 by 1 zeros matrix\n";
            Matrix hasil(1,1);
            hasil.matriks[0][0] = 0 ;
            return hasil ;
        }
        else 
        {
            Matrix hasil (baris, other.kolom);
            {
                for(int i = 0 ; i < baris; i++)
                {
                    for(int j = 0 ; j < other.kolom; j++)
                    {
                        for(int k = 0; k < kolom; k++)
                        {
                            hasil.matriks[i][j] += matriks[i][k] * other.matriks[k][j];
                        }
                    }
                }
                return hasil;
            }
        }
    }
    void display() {
        for (int i = 0 ; i<baris; i++)
        {
            for(int j = 0 ; j< kolom ; j++)
            {
                cout << matriks[i][j] << " ";
            }
            cout << endl ;
        }
    }
};
int main()
{
    vector<vector<float>> Ar = {{1, 2, 3}, {2, 3, 1}};
    vector<vector<float>> Br= {{0, 2, 4}, {1, 2, 5}, {8, 2, 1.2}};

    Matrix A(Ar);
    Matrix B(Br);
    Matrix C (2, 3); // Parameter constructor adalah (banyak baris, banyak kolom) dan isi dari matrix ini adalah angka nol
    cout << "Matrix A\n";
    A.display(); // print matrix A
    cout << "Matrix B\n";
    B.display(); // print matrix B
    cout << "Matrix C\n";
    C.display();    // Print matriks C
    cout << '\n';

    Matrix C1 = A + C;
    cout << "Matrix C1\n";
    C1.display();

    cout << '\n';
    Matrix C2 = A - C;
    cout << "Matrix C2\n";
    C2.display();

    cout << '\n';
    Matrix C3 = A * B;
    cout << "Matrix C3\n";
    C3.display();

    cout << '\n';
    Matrix C4 = B * A;
    cout << "Matrix C4\n";
    C4.display();

    cout << '\n';
    return 0;
}
