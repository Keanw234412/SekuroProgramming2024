#include<iostream> 
#include<vector>
#include<math.h>
#include<iomanip> 
#include<fstream> 
#include<stdio.h>
#include<windows.h>
#include<string>
#include<stdlib.h>

using namespace std;

#define ld long double

ld pi = acos(-1);

vector<pair<ld,ld>> operation;

int posisi = 0 ;

bool red0 = false, start = true, command = false  ;

void delay(void)
{
    int delay = 1;
    while (delay < 10000000)
    {
        delay++;
    }
}
void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void loading() 
{
    for (int i = 40; i <=75 ; i++)
    {
        gotoxy(i, 12);
        cout << "-";
        gotoxy(i, 14);
        cout << "-";
        delay();
    }

    for (int i = 1; i <= 100; i++)
    {
        gotoxy(40, 13);
        cout << " L O A D I N G     " << i << "%";
        delay();
    }
    system("cls");
}
void animation()
{

    for(int i = 1; i<= 100; i++)
    {
        gotoxy(i, 1);
        cout << "#";
        gotoxy(i, 4);
        cout<< "#";
        gotoxy(i, 20);
        cout << "#";
        gotoxy(i, 24);
        cout << "#"; 
        delay();
    }

    for (int i = 1; i<= 24; i++)
    {
        gotoxy(1, i);
        cout << "#";
        gotoxy(100, i);
        cout << "#";
        delay();
    }

    for(int i = 4; i<= 20; i++)
    {
        gotoxy(40, i);
        cout << "#";
        delay();
    }

    gotoxy(35, 3);
    cout << "Sistem Kendali Drone";

    gotoxy(3,6);
    cout << "1. Lokasi ";
    gotoxy(3,8);
    cout << "2. Gerak ";
    gotoxy(3,10);
    cout << "3. Gerak_2";
    gotoxy(3,12);
    cout << "4. Undo";
    gotoxy(3, 14);
    cout << "5. Redo";
    gotoxy(3, 16);
    cout << "6. Save";
    gotoxy(3, 18);
    cout << "7. Load";
}

void frame() 
{
    for(int i = 1; i<= 100; i++)
    {
        gotoxy(i, 1);
        cout << "#";
        gotoxy(i, 4);
        cout<< "#";
        gotoxy(i, 20);
        cout << "#";
        gotoxy(i, 24);
        cout << "#"; 
    }

    for (int i = 1; i<= 24; i++)
    {
        gotoxy(1, i);
        cout << "#";
        gotoxy(100, i);
        cout << "#";
    }

    for(int i = 4; i<= 20; i++)
    {
        gotoxy(40, i);
        cout << "#";
    }

    gotoxy(35, 3);
    cout << "Sistem Kendali Drone";

    gotoxy(3,6);
    cout << "1. Lokasi ";
    gotoxy(3,8);
    cout << "2. Gerak ";
    gotoxy(3,10);
    cout << "3. Gerak_2";
    gotoxy(3,12);
    cout << "4. Undo";
    gotoxy(3, 14);
    cout << "5. Redo";
    gotoxy(3, 16);
    cout << "6. Save";
    gotoxy(3, 18);
    cout << "7. Load";
}
void lokasi() 
{
    cout << "Lokasi Drone : " << "("<<operation[posisi].first << ", " << operation[posisi].second <<")" << endl;
    return ;
}

void gerak(ld delta_x, ld delta_y)
{
    pair<ld,ld>baru = operation[posisi] ;
    red0 = false;
    baru.first += delta_x; baru.second += delta_y;
    if (posisi == operation.size()-1)
    {
        operation.push_back(baru);
        posisi ++;
    }
    else 
    {
        posisi++;
        operation[posisi] = baru;
    }
    return;
}
void gerak_2(ld v, ld t, ld theta)
{
    pair<ld,ld>baru = operation[posisi] ;
    red0 = false;
    theta = theta * pi / 180.00;
    baru.first += v * t * cos(theta);
    baru.second += v * t * sin(theta);
    if (posisi == operation.size()-1)
    {
        operation.push_back(baru);
        posisi ++;
    }
    else 
    {
        posisi++;
        operation[posisi] = baru;
    }
    return;
}
void undo()
{
    if (posisi > 0)
    {
        red0 = true ;
        posisi --;
        cout <<  "Undo Berhasil" << endl;
    }
    else 
    {
        cout << "Tidak Berhasil Undo" << endl;
    }
}
void redo()
{
    if(posisi < operation.size() -1 && red0)
    {
        cout << "Berhasil Redo" << endl;
        posisi ++;
    }
    else
    {
        cout << "Tidak Berhasil Redo"<< endl;
    }
}

void save()
{
    cout << "Berhasil Tersimpan";
    ofstream cout("last_position.txt");
    cout << operation[posisi].first << " "<<operation[posisi].second;
}

void load()
{
    cout << "Berhasil DiLoad";
    ifstream cin("last_position.txt");
    cin >> operation[posisi].first >> operation[posisi].second;
}
int main() 
{
    cout << fixed << setprecision(2);
    string s = "";
    operation.push_back(make_pair(0,0));
    loading();
    animation();
    while(s != "exit")
    {
        frame();
        gotoxy(42, 6);
        cout << "Masukkan Pilihan Anda : ";
        cin >> s; 
        gotoxy(3, 21);
        if (s != "gerak_2")
        {
            system("cls");
        }
        
        frame();
        gotoxy(3, 21);
        if (s == "lokasi")
        {
            lokasi();
            command = true;
        }
        else if (s == "gerak")
        {
            ld dx, dy;
            cin >> dx >> dy;
            gerak(dx,dy);
            command = true;

        }
        else if (s == "undo")
        {
            undo();
            command = true;

        }
        else if (s == "redo")
        {
            redo();
            command = true;

        }
        else if (s == "gerak_2")
        {
            ld v,t,theta;
            gotoxy(42, 7);
            cout << "v : ";
            cin >> v;
            gotoxy(42, 8);
            cout << "t : ";
            cin >> t;
            gotoxy(42, 9);
            cout << "theta : ";
            cin >> theta;
            gerak_2(v,t,theta);
            system("cls");
            command = true;
        }
        else if(s == "load" && start )
        {
            load();
            command = true;
        }
        else if (s == "save")
        {
            save();
            command = true;
        }
        else if (s != "exit")
        {
            cout << "Masukan Tidak Valid" << endl;
            command = false;
        }
        if (start && command)
        {
            start = false;
        }
    }
    system("cls");
    return 0;
}