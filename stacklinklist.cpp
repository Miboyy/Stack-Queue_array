#include <iostream>
using namespace std;

// Stack Linked List menggunakan struct
struct Dokumen {
    string namaDokumen;
    string tanggalPembuatan;
    int ukuranDokumen;

    Dokumen* prev;
    Dokumen* next;
};

Dokumen* head = nullptr;
Dokumen* tail = nullptr;
Dokumen* cur = nullptr;
Dokumen* newNode = nullptr;
Dokumen* del = nullptr;

int maksimalDokumen = 5;

// Fungsi untuk menghitung jumlah dokumen dalam stack
int countDokumen() {
    if (head == nullptr) {
        return 0;
    } else {
        int banyak = 0;
        cur = head;
        while (cur != nullptr) {
            cur = cur->next;
            banyak++;
        }
        return banyak;
    }
}

// Cek apakah stack penuh
bool isFullDokumen() {
    return countDokumen() == maksimalDokumen;
}

// Cek apakah stack kosong
bool isEmptyDokumen() {
    return countDokumen() == 0;
}

// Menambahkan dokumen ke dalam stack
void pushDokumen(string namaDokumen, string tanggalPembuatan, int ukuranDokumen) {
    if (isFullDokumen()) {
        cout << "Stack penuh!" << endl;
    } else {
        if (isEmptyDokumen()) {
            head = new Dokumen();
            head->namaDokumen = namaDokumen;
            head->tanggalPembuatan = tanggalPembuatan;
            head->ukuranDokumen = ukuranDokumen;
            head->prev = nullptr;
            head->next = nullptr;
            tail = head;
        } else {
            newNode = new Dokumen();
            newNode->namaDokumen = namaDokumen;
            newNode->tanggalPembuatan = tanggalPembuatan;
            newNode->ukuranDokumen = ukuranDokumen;
            newNode->prev = tail;
            tail->next = newNode;
            newNode->next = nullptr;
            tail = newNode;
        }
    }
}

// Menghapus dokumen dari stack
void popDokumen() {
    if (isEmptyDokumen()) {
        cout << "Stack kosong!" << endl;
    } else {
        del = tail;
        if (tail->prev != nullptr) {
            tail = tail->prev;
            tail->next = nullptr;
        } else {
            head = nullptr;
            tail = nullptr;
        }
        delete del;
    }
}

// Menampilkan dokumen dalam stack
void displayDokumen() {
    if (isEmptyDokumen()) {
        cout << "Stack kosong!" << endl;
    } else {
        cout << "\nData dokumen dalam stack:" << endl;
        cur = tail;
        while (cur != nullptr) {
            cout << "Nama Dokumen: " << cur->namaDokumen << ", Tanggal Pembuatan: " << cur->tanggalPembuatan << ", Ukuran Dokumen: " << cur->ukuranDokumen << " KB" << endl;
            cur = cur->prev;
        }
    }
}

// Mengintip dokumen pada posisi tertentu
void peekDokumen(int posisi) {
    if (isEmptyDokumen()) {
        cout << "Stack kosong!" << endl;
    } else {
        int nomor = 1;
        cur = tail;
        while (nomor < posisi && cur != nullptr) {
            cur = cur->prev;
            nomor++;
        }
        if (cur != nullptr) {
            cout << "Dokumen pada posisi ke-" << posisi << ": " << cur->namaDokumen << ", Tanggal Pembuatan: " << cur->tanggalPembuatan << ", Ukuran Dokumen: " << cur->ukuranDokumen << " KB" << endl;
        } else {
            cout << "Posisi dokumen tidak valid!" << endl;
        }
    }
}

// Mengubah dokumen pada posisi tertentu
void changeDokumen(string namaDokumen, string tanggalPembuatan, int ukuranDokumen, int posisi) {
    if (isEmptyDokumen()) {
        cout << "Stack kosong!" << endl;
    } else {
        int nomor = 1;
        cur = tail;
        while (nomor < posisi && cur != nullptr) {
            cur = cur->prev;
            nomor++;
        }
        if (cur != nullptr) {
            cur->namaDokumen = namaDokumen;
            cur->tanggalPembuatan = tanggalPembuatan;
            cur->ukuranDokumen = ukuranDokumen;
        } else {
            cout << "Posisi dokumen tidak valid!" << endl;
        }
    }
}

// Menghapus semua dokumen dalam stack
void destroyDokumen() {
    cur = head;
    while (cur != nullptr) {
        del = cur;
        cur = cur->next;
        delete del;
    }
    head = nullptr;
    tail = nullptr;
}

int main() {
    // Contoh penggunaan fungsi-fungsi stack dokumen
    pushDokumen("Dokumen1", "2024-06-01", 500);
    displayDokumen();
    pushDokumen("Dokumen2", "2024-06-02", 750);
    pushDokumen("Dokumen3", "2024-06-03", 600);
    pushDokumen("Dokumen4", "2024-06-04", 300);
    pushDokumen("Dokumen5", "2024-06-05", 450);
    displayDokumen();

    pushDokumen("Dokumen6", "2024-06-06", 500);
    displayDokumen();

    popDokumen();
    displayDokumen();

    cout << "Apakah stack dokumen penuh? " << (isFullDokumen() ? "Ya" : "Tidak") << endl;
    cout << "Apakah stack dokumen kosong? " << (isEmptyDokumen() ? "Ya" : "Tidak") << endl;

    peekDokumen(3);

    cout << "Jumlah dokumen dalam stack: " << countDokumen() << endl;

    changeDokumen("DokumenUbah", "2024-06-10", 550, 2);
    displayDokumen();

    destroyDokumen();
    cout << "Apakah stack dokumen penuh? " << (isFullDokumen() ? "Ya" : "Tidak") << endl;
    cout << "Apakah stack dokumen kosong? " << (isEmptyDokumen() ? "Ya" : "Tidak") << endl;
    cout << "Jumlah dokumen dalam stack: " << countDokumen() << endl;

    displayDokumen(); // Tampilkan dokumen setelah destroy untuk memastikan semua terhapus

    return 0;
}
