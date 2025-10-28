#include <iostream>
using namespace std;

struct Produk {
    int id;
    string nama;
    int stok;
    Produk* berikut;
};

Produk* head = NULL;
void TambahDepan(int id, string nama, int stok){
    Produk* baru = new Produk;
    baru->id=id;
    baru->nama=nama;
    baru->stok=stok;

    if(head==NULL){
        head=baru;
        baru->berikut=head;
    } else {
        Produk* temp = head;
        while(temp->berikut !=head){
            temp = temp->berikut;
        }
        baru->berikut=head;
        temp->berikut=baru;
        head=baru;
    }
}

void TambahBelakang(int id, string nama, int stok){
    Produk* baru = new Produk;
    baru->id=id;
    baru->nama=nama;
    baru->stok=stok;

    if(head==NULL){
        head=baru;
        baru->berikut=head;
    } else {
        Produk* temp = head;
        while(temp->berikut !=head){
            temp = temp->berikut;
        }
        temp->berikut=baru;
        baru->berikut=head;
    }
}

void Tampilkanproduk(){
    Produk* temp = head;
     cout << "\n====== DAFTAR PRODUK ======\n";
    do {
        cout << "ID Produk   : " << temp->id << endl;
        cout << "Nama Produk : " << temp->nama << endl;
        cout << "Qty Produk  : " << temp->stok << endl;
        cout << "---------------------------\n";
        temp = temp->berikut;
    } while (temp != head);
}


int main(){
int pilih, id, stok;
    string nama;

    do {
        cout << "\n=== MENU PRODUK ===\n";
        cout << "1. Tambah Depan\n";
        cout << "2. Tambah Belakang\n";
        cout << "3. Tampilkan Produk\n";
        cout << "4. Keluar\n";
        cout << "Pilih: ";
        cin >> pilih;

        switch (pilih) {
            case 1:
                cout << "Masukkan ID Produk   : ";
                cin >> id;
                cin.ignore();
                cout << "Masukkan Nama Produk : ";
                getline(cin, nama);
                cout << "Masukkan Qty Produk  : ";
                cin >> stok;
                TambahDepan(id, nama, stok);
                break;
            case 2:
                cout << "Masukkan ID Produk   : ";
                cin >> id;
                cin.ignore();
                cout << "Masukkan Nama Produk : ";
                getline(cin, nama);
                cout << "Masukkan Qty Produk  : ";
                cin >> stok;
                TambahBelakang(id, nama, stok);
                break;
            case 3:
                Tampilkanproduk();
                break;
            case 4:
                cout << "Keluar...\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
        }
    } while (pilih != 4);

    return 0;
}

