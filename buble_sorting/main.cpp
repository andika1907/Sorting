#include<iostream>
using namespace std;

// tukar data a ke b dan data b ke a
void tukar(int &a, int &b) {
   int temp;
   temp = a;
   a = b;
   b = temp;
}

// menampilkan setiap data pada array
void tampil(int *array, int jumlah) {
   for(int i = 0; i<jumlah; i++)
      cout << array[i] << " ";
   cout << endl;
}

void bubbleSort(int *array, int jumlah) {
   for(int i = 0; i<jumlah; i++) { // <-- iterasi fase pengurutan
      bool ditukar = false; // memeriksa apakah ada data yang ditukar pada setiap fase

      // jumlah-i artinya data terakhir sudah tidak perlu disorting
      for(int j = 0; j<jumlah-i-1; j++) {// <-- iterasi pengurutan data

        // tukar jika data yang ditunjuk lebih besar dari data selanjutnya [ascending]
         if(array[j] > array[j+1]) {// <-- kondisi pengurutan
            tukar(array[j], array[j+1]);
            ditukar = true;    // tandai bahwa ada data yang di tukar
         }

      }

    // Jika tidak ada data yang ditukar pada fase ini maka keluar dari perulangan
    // Data sudah selesai diurutkan
    if(!ditukar) break;

    // opsional : tidak termasuk dalam logika pengurutan
    cout << "Hasil Pengurutan Fase "<< i+1 << ": ";
    tampil(array,jumlah); // lihat hasil sorting pada setiap fase

   }
}

int main() {
    int jumlah;// jumlah data array
    cout << "Masukkan jumlah data: ";
    cin >> jumlah;

    int array[jumlah];//buat array dengan jumlah data yang telah ditentukan
    for(int i = 0; i<jumlah; i++) {
        cout << "Masukkan Data " << i+1 <<" : ";
        cin >> array[i];
    }
    cout << "Array data sebelum disorting: ";
    tampil(array, jumlah);
    bubbleSort(array, jumlah); // sorting data pada array
    cout << "Array data setelah disorting: ";
    tampil(array, jumlah);
}
