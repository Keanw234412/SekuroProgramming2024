# SekuroProgramming2024
<br> 
Deskripsi <br> 
<br> 
Nama     : Keane Dylan Tandean <br> 
NIM      : 16523061 <br> 
Fakultas : STEI-R <br>
<br> 

URO_ Tugas Post Day 2 
<br> <br> 
Di dalam program ini ada terdapat beberapa fungsi sebagai berikut: 
- lokasi()
- gerak(x,y) 
- gerak_2 $(v,t,\theta)$
- undo()
- redo()
- save()
- load()

## lokasi() 
Fungsi ini akan mengeluarkan koordinat dari drone dalam bentuk koordinat kartesius 
#### Example
```C++=
#include<iostream>
using namespace std;

int main()
{
    // lokasi awal (0.00, 0.00) 
    lokasi() ;
    return 0;
}
```
#### Output

```
Lokasi Drone : (0.00, 0.00) 
```

## gerak(x,y)

Fungsi ini akan menggerakan posisi drone dan mengubah nilai x dan y pada drone

#### Example 
```C++= 
#include<iostream> 
using namespace std;
int main() 
{
    // Lokasi awal Drone (0, 0)
    gerak(2,3);  // Lokasi Drone (2, 3) 
    gerak(-2,4); //  Lokasi Drone (0, 7)
    lokasi();
    return 0;
}
```

#### Output 
```
Lokasi Drone : (0.00, 7.00)
```

## gerak_2 $(v,t,\theta)$
Fungsi gerak_2 akan memberi simulasi seolah-olah drone bergerak dengan kecepatan v kotak/s 
selama t detik. Arah yang ditempuh oleh drone adalah theta derajat dari horizontal positif 
counter clockwise.
<br>
 $x_{akhir} = x_{awal} + v * t * cos(\theta)$ <br> 
 $y_{akhir} = y_{awal} + v * t * sin(\theta)$
#### Example 
```C++= 
#include<iostream> 
#include<iomanip>

using namespace std;

int main() 
{
    cout << fixed << setprecision(2);
    gerak_2(10, 10, 30); // v : 10 , t : 10 , theta : 30
    lokasi();
    return 0;
}
```
#### Output 
```
Lokasi Drone : (86.60, 50.00)
```

## undo() 
Fungsi undo adalah fungsi yang mengubah nilai x,y (koordinat drone) dengan nilai x, y pada 
history sebelumnya. Jika history sudah berada di history awal, maka undo tidak dapat 
dijalankan.

#### Example 
```C++= 
#include<iostream> 
#include<iomanip> 
using namespace std;
int main() 
{    
    //Lokasi Awal (0,0)
    cout << fixed << setprecision(2);
    gerak(2,3); 
    lokasi() 
    gerak(3,2) ;
    lokasi();
    undo();
    lokasi();
    return 0;
}
```

#### Output 
```
Lokasi Drone : (2.00, 3.00)
Lokasi Drone : (5.00, 5.00)
Undo berhasil
Lokasi Drone : (2.00, 3.00)
```

## redo() 
Fungsi redo adalah fungsi yang mengembalikan nilai x, y yang telah diundo. 
Undo beberapa kali memungkinkan redo beberapa kali. Jika setelah melakukan Undo dilakukan gerak/gerak_2, maka redo tidak dapat dilakukan.

#### Example 
```C++= 
#include<iostream> 
#include<iomanip>
using namespace std;
int main() 
{
    cout << fixed << setprecision(2);
    // Lokasi Awal (0, 0)
    gerak(3,4);
    lokasi();
    undo();
    lokasi();
    redo();
    redo();
    lokasi();
    return 0;
}
```

#### Output
```
Lokasi Drone : (3.00, 4.00)
Undo berhasil
Lokasi Drone : (0.00, 0.00)
Redo berhasil
Tidak dapat redo 
Lokasi Drone : (3.00, 4.00)
```

## save() 
Fungsi ini yang dapat mencatat koordinat terakhir drone pada sebuah "name_file".txt.

#### Example 
```C++= 
#include<iostream>
#include<fstream>
using namespace std;
int main() 
{
    int x = 1, y = 2;
    ofstream cout("file.txt");
    cout << x << " "<< y << "\n";
    return 0;
}
```

#### Pada file.txt
```
1 2 
```

## load()
Saat program ditutup dan dibuka lagi, fungsi ini dapat dijalankan dan drone akan berada pada koordinat yang di save!<br> 
**Fungsi ini juga hanya bisa di jalankan pada awal perintah!** 

#### Example 
Pada file.txt diatas terdapat 2 nilai 1 dan 2 
```C++= 
#include<iostream> 
#include<fstream> 
using namespace std;
int main() 
{
    int x , y;
    ifstream cin("file.txt");
    cout << x << " " << y << "\n";
    return 0;
}

```

#### Output 
```
1 2 
```

## Cara Menjalankan Program 

```
lokasi 
gerak_2 10 10 30 
gerak 10 13 
undo 
redo 
save 
load 
```
- lokasi <br> 
   Fungsi ini akan menampilkan koordinat drone 

- gerak_2 10 10 30 <br>
    Fungsi ini akan menggerakan drone ke(86.60, 50.00)
- gerak 10 13 <br>
    Fungsi ini membuat drone bergerak 10 ke kanan dan 13 ke atas sehingga kordinatnya (96.60, 63.00)
- undo <br>
    Fungsi ini akan mengubah nilai x,y (koordinat drone) dengan nilai x,y pada history sebelumnya. (86.60, 50.00)
- redo <br>
Fungsi ini akan mengembalikan nilai x,y(koordinat drone) yang telah di undo. (96.60, 63.00)
- save<br>
Fungsi ini akan menyimpan nilai x,y(koordinat drone) terakhir pada sebuah file.txt.
- load <br>
Fungsi ini akan mengambil nilai x,y(koordinat drone) terakhir pada sebuah file.txt.

