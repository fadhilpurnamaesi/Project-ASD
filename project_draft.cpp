#include <iostream>
#include <string>
using namespace std;

struct tamu {
    string nama, jenisKamar;
    string status = "Belum Check-In";
    long int ktp, telp;
    int jmlOrg, lamaInap, noKamar;
    int hari, bulan, tahun;
};

struct Node {
    tamu data;
    Node* next;
};

Node* head_antrian = NULL;
Node* tail_antrian = NULL;
Node* head_riwayat = NULL;
Node* tail_riwayat = NULL;

void insert(tamu data); // Memasukkan data ke antrean sesuai tanggal
void tampilkanantrean(); // Menampilkan antrean saat ini
void prosesantrian(); // Memproses antrean (menghapus dari depan)
void isiantrean(); // Fungsi untuk mengisi antrean
void insertRiwayat(tamu data); // Memasukkan data ke riwayat
void insertEmpty(tamu data); // Memasukkan data ke list kosong
void insertFront(tamu data); // Memasukkan data ke depan list
void insertRear(tamu data); // Memasukkan data ke belakang list
void insertAfter(Node* current, tamu data); // Memasukkan data setelah node terpilih
void deleteFront(); // Menghapus node depan
void tampilkanRiwayat(); // Menampilkan riwayat antrean


int main(){
    int pilihan;
    do{
     cout<<"1.Isi Antrean"<<endl;
     cout<<"2.Tampilkan Antrean"<<endl;
     cout<<"3.Proses Antrean"<<endl;
     cout<<"4.Tampilkan Riwayat Antrean"<<endl;
     cout<<"5.Tutup Program"<<endl;
     cout<<"Isi Pilihan: ";
     cin>>pilihan;
     cout << endl;
     if (pilihan == 1) isiantrean();
        else if (pilihan == 2) tampilkanantrean();
        else if (pilihan == 3) prosesantrian();
        else if (pilihan == 4) tampilkanRiwayat();
        else if (pilihan != 5) cout<<"Pilihan tidak valid, silakan coba lagi."<<endl;
    }while (pilihan != 5);
    return 0;
}

void isiantrean(){
    int isiantreanselesai = 0;
    while(isiantreanselesai!=1){ 
    tamu Tamu;
    cin.ignore();
    cout<<"Masukan Data"<<endl;
    cout<<"1.Nama: ";
    getline(cin,Tamu.nama);
    cout<<"2.No Telp: ";
    cin>>Tamu.telp;
    cout<<"3.No KTP: ";
    cin>>Tamu.ktp;
    cout<<"4.Jumlah Orang: ";
    cin>>Tamu.jmlOrg;
    cout<<"5.Lama Inap: ";
    cin>>Tamu.lamaInap;//satuannya hari
    cout<<"6.Jenis Kamar: ";
    cin>>Tamu.jenisKamar;
    cout<<"7.Tanggal"<<endl;
    cout<<"Hari: ";
    cin>>Tamu.hari;
    cout<<"Bulan: ";
    cin>>Tamu.bulan;
    cout<<"Tahun: ";
    cin>>Tamu.tahun;
    insert(Tamu);
    cout<<"Kembali ke main menu isi 1, jika tidak ketik 0 : ";
    cin>>isiantreanselesai;
     }
     cout<<endl;
}
void tampilkanantrean(){
    Node* temp = head_antrian;
    int tampilkanantreanselesai=1;
    int count=1;
    cout << "Antrean Saat Ini:" << endl;
    if (temp == NULL){
        cout<<"Data Tidak ada\n"<<endl;
        return;
    }
    while(tampilkanantreanselesai != 0){ 
    while(temp != NULL){
        cout<<count<<". ";
        cout<<"Nama: "<<temp->data.nama<<endl;
        cout<<"No Telp: "<<temp->data.telp<<endl;
        cout<<"No KTP: "<<temp->data.ktp<<endl;
        cout<<"Jumlah Orang: "<<temp->data.jmlOrg<<endl;
        cout<<"Lama Inap: "<<temp->data.lamaInap<<endl;
        cout<<"Jenis Kamar: "<<temp->data.jenisKamar<<endl;
        cout<<"Tanggal: "<<temp->data.hari<<"/"<<temp->data.bulan<<"/"<<temp->data.tahun<<endl;
        cout<<"Status: "<<temp->data.status<<endl;
        cout<<endl;
        count++;
        temp=temp->next;
    }
     cout<<"Kembali ke main menu isi 0 jika tidak ketik 1: ";
     temp=head_antrian;
     count=1;
    cin>>tampilkanantreanselesai;
   }
   cout<<endl;
}


bool lebihAwal(tamu t1, tamu t2){
    if (t1.tahun != t2.tahun) return t1.tahun < t2.tahun;
    if (t1.bulan != t2.bulan) return t1.bulan < t2.bulan;
    return t1.hari < t2.hari;
}

void insert(tamu data){
    if (head_antrian == NULL) {
        insertEmpty(data);
        return;
    }
    Node* temp = head_antrian;
    if (lebihAwal(data, temp->data)) {
        insertFront(data);
        return;
    } else {
        while (temp->next != NULL && !lebihAwal(data, temp->next->data)) {
            temp = temp->next;
        }
        insertAfter(temp, data);
    }
}
void prosesantrian(){
    int prosesantreanselesai=1;
    while(prosesantreanselesai != 0){
      cout<<"Antrean Saat Ini:"<<endl;
      Node* temp = head_antrian;
      int count=1;
      if (temp == NULL){
        cout<<"Data Tidak ada\n"<<endl;
        return;
      }
    while(temp != NULL){
        if(head_antrian != NULL){ 
        cout<<count<<". ";
        cout<<"Nama: "<<temp->data.nama<<endl;
        cout<<"No Telp: "<<temp->data.telp<<endl;
        cout<<"No KTP: "<<temp->data.ktp<<endl;
        cout<<"Jumlah Orang:"<<temp->data.jmlOrg<<endl;
        cout<<"Lama Inap:"<<temp->data.lamaInap<<endl;
        cout<<"Jenis Kamar:"<<temp->data.jenisKamar<<endl;
        cout<<"Tanggal:"<<temp->data.hari<<"/"<<temp->data.bulan<<"/"<<temp->data.tahun<<endl;
        cout<<"Status: "<<temp->data.status<<endl;
        cout<<endl;
        count++;
        temp=temp->next;
        }
    }
    cout<<"Proses antrian? Jika Iya ketik 1 jika tidak ketik 0 : ";
    temp=head_antrian;
    count=1;
    cin>>prosesantreanselesai;
    cout<<endl;
    if(prosesantreanselesai==1){
        cout <<"Masukan No Kamar untuk "<<head_antrian->data.nama<<": ";
        cin>>head_antrian->data.noKamar;
        insertRiwayat(head_antrian->data);
        deleteFront();
        cout <<"[[ Antrean berhasil diproses dan dipindahkan ke riwayat ]]"<<endl;
    }
   }
   cout<<endl;
}

void tampilkanRiwayat(){
    Node* temp = head_riwayat;
    int tampilkanriwayatselesai=1;
    int count=1;
    cout << "Riwayat Antrean:" << endl;
    if (temp == NULL){
        cout<<"Data Tidak ada\n"<<endl;
        return;
    }
    while(tampilkanriwayatselesai != 0){ 
    while(temp != NULL){
        cout<<count<<". ";
        cout<<"Nama: "<<temp->data.nama<<endl;
        cout<<"No Telp: "<<temp->data.telp<<endl;
        cout<<"No KTP: "<<temp->data.ktp<<endl;
        cout<<"Jumlah Orang: "<<temp->data.jmlOrg<<endl;
        cout<<"Lama Inap: "<<temp->data.lamaInap<<endl;
        cout<<"Jenis Kamar: "<<temp->data.jenisKamar<<endl;
        cout<<"No Kamar: "<<temp->data.noKamar<<endl;
        cout<<"Tanggal: "<<temp->data.hari<<"/"<<temp->data.bulan<<"/"<<temp->data.tahun<<endl;
        cout<<"Status: "<<temp->data.status<<endl;
        cout<<endl;
        count++;
     temp=temp->next;
    }
    cout<<"Kembali ke main menu isi 0 jika tidak isi 1: ";
    temp=head_riwayat;
    count=1;
    cin>>tampilkanriwayatselesai;
   }
   cout<<endl;
}

void insertRiwayat(tamu data){
    Node* newNode = new Node();
    newNode->data = data;
    newNode->data.status = "Sudah Check-in";
    if (head_riwayat == NULL) {
        newNode->next = NULL;
        head_riwayat = newNode;
        tail_riwayat = newNode;
        return;
    }
    newNode->next = head_riwayat;
    head_riwayat = newNode;
}

void insertEmpty(tamu data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = NULL;
    head_antrian = newNode;
    tail_antrian = newNode;
    cout << "[[ Data berhasil dimasukkan ke dalam antrean ]]" << endl;
}

void insertFront(tamu data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = head_antrian;
    head_antrian = newNode;
    cout << "[[ Data berhasil dimasukkan ke dalam antrean ]]" << endl;
}

void insertRear(tamu data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = NULL;

    tail_antrian->next = newNode;
    tail_antrian = newNode;
    cout << "[[ Data berhasil dimasukkan ke dalam antrean ]]" << endl;
}

void insertAfter(Node* current, tamu data) {
    if (current == tail_antrian) {
        insertRear(data);
        return;
    }

    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = current->next;
    current->next = newNode;
    cout << "[[ Data berhasil dimasukkan ke dalam antrean ]]" << endl;
}

void deleteFront(){
    if (head_antrian == NULL) return;
    
    Node* temp = head_antrian;
    
    if (head_antrian == tail_antrian) {
        head_antrian = NULL;
        tail_antrian = NULL;
    } else {
        head_antrian = head_antrian->next;
    }
    delete temp;
}
