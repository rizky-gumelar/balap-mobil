#include <iostream>

using namespace std;

string arrayNama[15];
int arrayNomor[15];
int arrayWaktu[15];
int i = 0;
char lanjut;
int pilih;
void dataPembalap();
void juara();
void pencarian();


int main()
{



    do{
        cout << "\t==========================================================================================\n";
        cout << "\t|>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> PROGRAM BALAP MOBIL <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<|\n";
        cout << "\t------------------------------------------------------------------------------------------\n";
        cout << "\t|                            1. Masukkan Data Pembalap (15)                              |\n";
        cout << "\t|                            2. Cari Pembalap                                            |\n";
        cout << "\t|                            3. Urutan Juara                                             |\n";
        cout << "\t|                            4. Selesai                                                  |\n";
        cout << "\t==========================================================================================\n";
        cout << "\tMasukkan Pilihan : ";
        cin >> pilih;

        switch(pilih){
            case 1:
                dataPembalap();
                break;
            case 2:
                pencarian();
                break;
            case 3:
                juara();
                break;
            case 4:
                return 0;
                break;
            default:
                cout << "\n\tPilihan Anda salah." << endl;
                break;
        }

    }while(1);


}

void dataPembalap(){
    while(i < 15){
        cout << "\n\tMasukkan Nama Peserta ke-" << i+1 << " = ";
        cin >> arrayNama[i];
        arrayNomor[i] = i+1;
        cout << "\tMasukkan Waktu Tempuh = ";
        cin >> arrayWaktu[i];
        i = i+1;
    }



    //CETAK
    cout << "\n\t==========================================================================================\n";
    cout << "\t           Nama             |           Nomor Urut          |         Waktu Tempuh        \n";
    cout << "\t==========================================================================================\n";
    for(int j=0; j<i; j++){
        cout << "\t\t    " << arrayNama[j] << "\t\t\t  " << arrayNomor[j] <<"\t\t\t\t "<< arrayWaktu[j]<<" detik  \t\n";
        cout << "\t------------------------------------------------------------------------------------------\n";
    }
}
void pencarian(){
    int x = 0;
    string cari;
    cout << "\tMasukkan nama pembalap yang ingin dicari : ";
                cin >> cari;

                while(x<15){
                    if(arrayNama[x]==cari){
                        break;
                    }
                    x++;
                }

                if(x<i){
                    cout << "\n\t==========================================================================================\n";
                    cout << "\t            Nama             |           Nomor Urut          |         Waktu Tempuh       \n";
                    cout << "\t==========================================================================================\n";
                    cout << "\t\t    " << arrayNama[x] << "\t\t\t  " << arrayNomor[x] <<"\t\t\t\t "<< arrayWaktu[x]<<" detik  \t\n";
                    cout << "\t------------------------------------------------------------------------------------------\n";
                }else{
                    cout<< "\tNama yang anda cari tidak ditemukan!" <<endl;
                }



}
void juara(){
    int x = 1;
    int y;
    string keyNama;
    int keyNomor,keyWaktu;

    while(x<i){
        keyNama = arrayNama[x];
        keyNomor = arrayNomor[x];
        keyWaktu = arrayWaktu[x];

        y = x-1;
        while(y>=0 && arrayWaktu[y] > keyWaktu){
            arrayWaktu[y+1] = arrayWaktu[y];
            arrayNama[y+1] = arrayNama[y];
            arrayNomor[y+1] = arrayNomor[y];
            y = y - 1;
        }
        arrayWaktu[y+1] = keyWaktu;
        arrayNama[y+1] = keyNama;
        arrayNomor[y+1] = keyNomor;
        x = x + 1;
    }

    cout << "\n\t================================================================================\n";
    cout << "\t           Juara         |           Nama             |        Nomor Urut       \n";
    cout << "\t================================================================================\n";
    for(int j=0; j<i; j++){
        cout <<"\t\t    "<< j+1 <<"\t\t\t   "<< arrayNama[j] << "\t\t\t    " << arrayNomor[j] <<"  \t\t\n";
        cout << "\t--------------------------------------------------------------------------------\n";
    }
}
