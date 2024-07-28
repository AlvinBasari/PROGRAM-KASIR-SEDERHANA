#include <iostream.h>
#include <conio.h>
#include <stdio.h>
#include <string.h>

int main() {
    const int MAX_BARANG = 100;
    char namaBarang[MAX_BARANG][50];
    long double hargaBarang[MAX_BARANG];
    int jumlahBarang[MAX_BARANG];
    long double subTotal[MAX_BARANG];
    float diskon = 0;

    int inpt;
    long double totalHarga = 0;
    long double totalDiskon = 0;
    long double totalBayar = 0;
    long double bayar = 0;
    long double kembali = 0;
    
    clrscr();

    cout << "---------------------------" << endl;
    cout << " PROGRAM KASIR ALVIN BASARI" << endl;
    cout << "---------------------------" << endl;

    cout << endl;

    cout << "Jumlah barang yang dibeli: ";
    cin >> inpt;
    cout << endl;

    if (inpt > MAX_BARANG) {
        cout << "Maaf, jumlah barang melebihi batas maksimal." << endl;
        return 1;
    }

    for (int i = 0; i < inpt; ++i) {
        cout << "Barang ke-" << i + 1 << ":\n";
        cout << "Nama barang: ";
        cin >> namaBarang[i];
        cout << "Jumlah     : ";
        cin >> jumlahBarang[i];
        cout << "Harga      : Rp.";
        cin >> hargaBarang[i];
        cout << endl;

        subTotal[i] = hargaBarang[i] * jumlahBarang[i];
        totalHarga += subTotal[i];
    }

    // Menentukan diskon berdasarkan total harga
    if (totalHarga >= 100000) {
        diskon = 5;
    } else if (totalHarga >= 50000) {
        diskon = 3;
    } else if (totalHarga >= 25000) {
        diskon = 1;
    } else {
        diskon = 0;
    }

    totalDiskon = totalHarga * (diskon / 100);
    totalBayar = totalHarga - totalDiskon;

    clrscr();

    cout <<"===========================" << endl;
    cout <<"PROGRAM KASIR ALVIN BASARI " << endl;
    cout <<"===========================" << endl;
    gotoxy(1, wherey()); cout << "No";
    gotoxy(6, wherey()); cout << "Barang";
    gotoxy(22, wherey()); cout << "Jumlah";
    gotoxy(31, wherey()); cout << "Harga";
    gotoxy(43, wherey()); cout << "Sub Total" << endl;
    cout << "----------------------------------------------------" << endl;
    for (int i = 0; i < inpt; ++i) {
        gotoxy(1, wherey()); cout << i + 1;
        gotoxy(6, wherey()); cout << namaBarang[i];
        gotoxy(22, wherey()); cout << jumlahBarang[i];
        gotoxy(31, wherey()); cout << hargaBarang[i];
        gotoxy(43, wherey()); cout << subTotal[i] << endl;
    }
    cout << "----------------------------------------------------" << endl;
    cout << "Jumlah Bayar : Rp." << totalHarga << endl;
    cout << "Diskon       : Rp." << totalDiskon << " (" << diskon << "%)" << endl;
    cout << "Total Bayar  : Rp." << totalBayar << endl;

    cout << "Bayar        : Rp.";
    cin >> bayar;
    cout << endl;

    if (bayar >= totalBayar) {
        kembali = bayar - totalBayar;
        cout << "Kembali      : Rp." << kembali << endl;
    } else {
        kembali = totalBayar - bayar;
        cout << "Pembayaran Kurang : Rp." << kembali << endl;
    }

    getch();
    return 0;
}

