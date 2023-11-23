#include<iostream> 
#include<vector>
#include<math.h>
#include<iomanip> 
#include<fstream> 

using namespace std;

#define ld long double

ld pi = acos(-1);

vector<pair<ld,ld>> operation;

int posisi = 0 ;

bool red0 = false, start = true, command = false  ;

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

void UI(int x, char s)
{
    for(int i = 1; i<= x ; i++)
    {
        cout << s;
    }
    return;
}

void save()
{
    ofstream cout("last_position.txt");
    cout << operation[posisi].first << " "<<operation[posisi].second;
}

void load()
{
    ifstream cin("last_position.txt");
    cin >> operation[posisi].first >> operation[posisi].second;
}
int main() 
{
    string id;
    UI(70, '=');
    cout << endl;
    UI(25, ' ');
    cout << "Drone\n";
    UI(70, '=');
    cout << "\n\n";
    cout << "Masukkan ID Drone : ";
    cin >> id;
    system("cls");
    UI(70,'=');
    cout<<endl;
    UI(25, ' ');
    cout << id << "\n";
    UI(70, '=');
    cout << "\n\n";
    cout << fixed << setprecision(2);
    string s = "";
    operation.push_back(make_pair(0,0));
    while(s != "exit")
    {
        cin >> s; 
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
            cin >> v >> t >> theta;
            gerak_2(v,t,theta);
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
    
    return 0;
}