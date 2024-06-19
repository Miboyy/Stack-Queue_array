#include <iostream>
using namespace std;

struct Dokumen {
    string namaDokumen;
    string tanggalPembuatan;
    int ukuranDokumen;
};

// array Antrian
int maksimalAntrianArray = 3, front = 0, back = 0;
// ruang antrian array
Dokumen antrianDokumen[3];

// isFull / cek data antrian penuh atau tidak
bool isFull() {
    return back == maksimalAntrianArray;
}

// isEmpty
bool isEmpty() {
    return back == 0;
}

// tambahdokumen / penambahan data antrian
void tambahdokumen(Dokumen data) {
    if (isFull()) {
        cout << "Antrian penuh!!" << endl;
    } else {
        antrianDokumen[back] = data;
        back++;
    }
}

// hapusdokumenawal / penghapusan data depan
void hapusdokumenawal() {
    if (isEmpty()) {
        cout << "Antrian kosong!!" << endl;
    } else {
        for (int i = 0; i < back - 1; i++) {
            antrianDokumen[i] = antrianDokumen[i + 1];
        }
        back--;
    }
}

// menghitung / menghitung banyak data yg ngantri
int menghitung() {
    return back;
}

// hapusdokumen / clear
void hapusdokumen() {
    if (isEmpty()) {
        cout << "Antrian kosong!!" << endl;
    } else {
        back = 0;
        front = 0;
    }
}

// cetakdokumen / View
void cetakdokumen() {
    cout << "Jumlah data yg ngantri : " << menghitung() << " data." << endl;
    cout << "Data Antrian Dokumen : " << endl;
    if (isEmpty()) {
        cout << "Antrian kosong!!" << endl;
    } else {
        for (int i = 0; i < maksimalAntrianArray; i++) {
            // cek apakah ruang kosong atau tidak
            if (i < back) {
                cout << i + 1 << ". " << antrianDokumen[i].namaDokumen << " - " << antrianDokumen[i].tanggalPembuatan << " - " << antrianDokumen[i].ukuranDokumen << " KB" << endl;
            } else {
                cout << i + 1 << ". (kosong)" << endl;
            }
        }
    }
    cout << "\n" << endl;
}

int main() {
    Dokumen dok1 = {"Dokumen1", "2024-06-01", 500};
    Dokumen dok2 = {"Dokumen2", "2024-06-02", 750};
    Dokumen dok3 = {"Dokumen3", "2024-06-03", 600};
    Dokumen dok4 = {"Dokumen4", "2024-06-04", 300};
    Dokumen dok5 = {"Dokumen5", "2024-06-05", 450};

    tambahdokumen(dok1);
    cetakdokumen();

    tambahdokumen(dok2);
    tambahdokumen(dok3);
    tambahdokumen(dok4);
    tambahdokumen(dok5);
    cetakdokumen();

    Dokumen dok6 = {"Dokumen6", "2024-06-06", 500};
    tambahdokumen(dok6);
    cetakdokumen();

    hapusdokumenawal();
    cetakdokumen();

    hapusdokumen();
    cetakdokumen();

    cout << "Jumlah dokumen dalam antrian: " << menghitung() << endl;

    return 0;
}
