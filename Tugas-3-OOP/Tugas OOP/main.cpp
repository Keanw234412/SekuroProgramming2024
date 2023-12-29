#include<iostream> 
#include<cmath>
#include<vector>

using namespace std;

float vx, vy, omega;

int indeks = 0;

float xk[10000], yk[10000], theta[10000];
class Matrix
{
private:
    vector<vector<float>>matriks;

public:
    int kolom, baris;

    Matrix(int r, int c): baris(r), kolom(c), matriks(vector<vector<float>>(r, vector<float>(c,0))){}

    void set(int baris, int kolom, float value)
    {
        matriks[baris][kolom] = value;
    }
    float get(int baris, int kolom)
    {
        return matriks[baris][kolom];
    }
    Matrix operator + (Matrix& other)
    {
        Matrix hasil(baris, kolom);
        {
            for(int i = 0; i < baris; i ++)
            {
                for(int j = 0 ; j< kolom; j++)
                {
                    hasil.matriks[i][j] = matriks[i][j] + other.matriks[i][j];
                }
            }
            return hasil;
        }
    }
    Matrix operator * (Matrix& other)
    {
        Matrix hasil(baris, other.kolom);
        {
            for(int i = 0; i<baris; i++)
            {
                for (int j = 0 ; j<other.kolom; j++)
                {
                    float sum = 0 ;
                    for (int k = 0; k < kolom; k++)
                    {
                        sum += matriks[i][j] * other.get(k,j);
                    }
                    hasil.set(i,j,sum);
                }
            }
            return hasil;
        }
    }
};

class Swerve{

private:
    float r1x, r1y, r2x, r2y, r3x, r3y, r4x, r4y;
    Matrix matriks;
    vector<float> arr_vnx;
    vector<float> arr_vny;

    Matrix Pose;

public:
    Swerve() : r1x(0.26363),r2x(0.26363),r3x(0.26363),r4x(0.26363),r1y(0.26363),r2y(0.26363),r3y(0.26363),r4y(0.26363), matriks(8,3), Pose(3,1)
    {
        matriks.set(0,0,1);matriks.set(0,1,0);matriks.set(0,2,-r1y);
        matriks.set(1,0,0);matriks.set(1,1,1);matriks.set(1,2,r1x);
        matriks.set(2,0,1);matriks.set(2,1,0);matriks.set(2,2,-r2y);
        matriks.set(3,0,0);matriks.set(3,1,1);matriks.set(3,2,r2x);
        matriks.set(4,0,1);matriks.set(4,1,0);matriks.set(4,2,-r3y);
        matriks.set(5,0,0);matriks.set(5,1,1);matriks.set(5,2,r3x); 
        matriks.set(6,0,1);matriks.set(6,1,0);matriks.set(6,2,-r4y);
        matriks.set(7,0,0);matriks.set(7,1,1);matriks.set(7,2,r4x);  

        arr_vnx.resize(4);
        arr_vny.resize(4);

        Pose.set(0,0,xk[indeks]);
        Pose.set(1,0,yk[indeks]);
        Pose.set(2,0,theta[indeks]);
    }
    void velocityCommand(float vx, float vy, float omega)
    {
        Matrix inputMatriks(3,1);
        inputMatriks.set(0,0,vx);
        inputMatriks.set(1,0,vy);
        inputMatriks.set(2,0,omega);

        Matrix hasil = matriks * inputMatriks;

        arr_vnx[0] = hasil.get(0,0) ;arr_vnx[1] = hasil.get(2,0); arr_vnx[2] = hasil.get(4,0); arr_vnx[3] = hasil.get(6,0);
        
        arr_vny[0] = hasil.get(1,0);arr_vny[1] = hasil.get(3,0); arr_vny[2] = hasil.get(5,0) ; arr_vny[3] = hasil.get(7,0);

    }
    float calculateResultan(float vnx, float vny)
    {
        return sqrt(vnx * vnx + vny * vny);
    }
    void updatePose(float deltaTime)
    {
        Matrix tambah(3,1);
        tambah.set(0,0, vx * deltaTime);
        tambah.set(1,0,vy * deltaTime);
        tambah.set(2,0,omega * deltaTime);

        Matrix result = Pose + tambah;

        xk[indeks+1] = result.get(0,0);
        yk[indeks+1] = result.get(1,0); 
        theta[indeks+1] = result.get(2,0);

        indeks ++;
    }

};

int main() 
{
    float t = 0.0;
    float stop = 6.3;
    float delta_time = 0.01;

    yk[0] = 5;

    while(t <= stop)
    {

        vx = 48 * cos(t) * pow(sin(t), 2);
        vy = 4 * sin(4*t) + 6 * sin(3*t) + 10 * sin(2*t)-13 * sin(t) ;
        omega = 0;

        Swerve swerve;

        swerve.velocityCommand(vx,vy,omega);

        swerve.updatePose(delta_time);

        t+= delta_time;
    }
}