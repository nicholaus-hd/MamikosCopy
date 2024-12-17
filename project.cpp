#include <iostream>
#include <iomanip>
using namespace std;

string uname, pass, menu, jadipesan, tglmasuk;
string storetipe[100], storuname[100], storpass[100], namapemilik[100], nopemilik[100];
string namaleng[100], notel[100], email[100], alamatuser[100], genderuser[100];
string namakos[100][100], alamatkos[100][100], fasilitas[100][100], jeniskos[100][100];
int harga[100][100];
int akun[100], inputkos[100], namapem[100];
int akuntemp, tipeakun, input, durasi, pesan1d, pesan2d, akunke, totalkos = 0, jumlahakun = 0, user = 0, i = 0, j = 0;
bool staymain = true, stay = true;

void pause(){
    system("pause");
}
void exitpr(){
    cout << "Keluar dari Program. Terima Kasih!" << endl;
    exit(0);
}

void logout(){
    string logout;
    do{
        cout << "Berhasil Keluar Dari Akun. Kembali Ke Menu Awal? (y/n) : "; cin >>logout;
        if (logout != "y" &&logout != "Y" && logout != "N" &&logout != "n") {
            cout<<"Input Yang Anda Masukkan Salah...\n";
            pause(); 
        } else if (logout == "y" || logout == "Y"){
            staymain = true;
            stay = false; 
        } else if (logout == "n" || logout == "N"){
            staymain = false;
            stay = false;
        }
    } while (logout != "y" &&logout != "Y" &&logout != "N" &&logout != "n"); 
}

void unggah(){
    cout << "UNGGAH" << endl;
    for (i = totalkos; i < (totalkos + 1); i++){
    namapemilik[i] = namaleng[akunke];
    nopemilik[i] = notel[akunke];
    cout<<"\nNama Pemilik : "<< namapemilik[i] << endl;
    cout<<"Nomor Pemilik : "<< nopemilik[i] << endl;
    do
    {
        cout<<"Masukkan Jumlah Kos Yang Akan Diupload : ";cin>>input;
        if (input < 1) {
            cout << "Jumlah Kos yang diupload minimal 1" << endl; }   
    } while (input < 1);
    
        inputkos[i]=input;
        for (int j = 0; j < inputkos[i]; j++){
        cout<<"\n\tData Kos ke-"<< j + 1 <<"\n";
        cout<<"\n\tNama Kos Anda       : ";getline(cin>>ws, namakos[i][j]);
        cout<<"\tAlamat Kos Anda     : ";getline(cin>>ws, alamatkos[i][j]);
        cout<<"\tFasilitas Kos Anda  : ";getline(cin>>ws, fasilitas[i][j]);
        cout<<"\tJenis Kos Anda      : ";getline(cin>>ws, jeniskos[i][j]);
        cout<<"\tHarga Kos Per Bulan : ";cin>>harga[i][j];
        }
    }
    totalkos = i;
    cout << "Berhasil Unggah Data Kos" << endl;
    pause();
    
}

void lihat(){
    if (totalkos < 1) {
        cout << "Belum Ada Data Kos yang Masuk" << endl;
        pause(); 
    } else {
    cout << "LIHAT KOS" << endl;
    
    for (i = 0; i < totalkos; i++){
        cout<<"\nDATA UPLOAD KE-"<< i + 1 <<"\n";
        cout<<"Nama Pemilik : "<< namapemilik[i] << endl;
        cout<<"No Pemilik   : "<< nopemilik[i] << endl;
        for (j = 0; j < inputkos[i]; j++) {
            cout<<"\n\tData Kos ke-"<< j + 1<<"\n";
            cout<<"\tNama Kos            : "<< namakos[i][j] << endl;
            cout<<"\tAlamat Kos          : "<< alamatkos[i][j] << endl;
            cout<<"\tFasilitas Kos       : "<< fasilitas[i][j] << endl;
            cout<<"\tJenis Kos           : "<< jeniskos[i][j] << endl;
            cout<<"\tHarga Kos Per Bulan : "<< harga[i][j] << endl;
        }
    }
    cout << "\nBerhasil Menampilkan Kos" << endl;
    pause();
    }
}

void menupemilik(){
    string menupem;
    do{
        stay = true;
        system("cls");
        cout<<"+"<<setfill('=')<<setw(52)<<"=+\n";
        cout<<"|"<<setfill(' ')<<setw(31)<<"MENU PEMILIK"<<setw(21)<<"|\n";
        cout<<"+"<<setfill('=')<<setw(52)<<"=+\n";
        cout<<"| Pilih Menu" <<setfill(' ')<<setw(41)<<"|\n";
        cout<<"| 1. Unggah Kos "<<setfill(' ')<<setw(37)<<"|\n";
        cout<<"| 2. Lihat Kos "<<setfill(' ')<<setw(38)<<"|\n";
        cout<<"| 3. Log Out "<<setfill(' ')<<setw(40)<<"|\n";
        cout<<"+"<<setfill('=')<<setw(52)<<"=+\n";
        cout<<"Masukkan Pilihan : ";getline(cin>>ws,menupem);
        if (menupem == "1"){
            unggah();
        } else if (menupem == "2"){
            lihat();
        } else if (menupem == "3"){
            logout();
        } else {
            cout<<"Input Yang Anda Masukkan Salah....\n";
            cout<<"Silahkan Coba Lagi!\n";
            pause();
        }
    } while (stay);
}

void pesan(){
    //show array pemilik, pengguna, kos, input tanggal masuk, durasi dlm bulan, show total harga
    lihat();
    cout << "Pilih Upload ke- : "; cin >> pesan1d;
    cout << "Pilih Kos ke- : "; cin >> pesan2d;
    pesan1d -= 1;
    pesan2d -= 1;
    cout<<"\n\tNama Pemilik        : "<< namapemilik[pesan1d] << endl;
    cout<<"\tNo Pemilik          : "<< nopemilik[pesan1d] << endl;
    cout<<"\tNama Kos            : "<< namakos[pesan1d][pesan2d] << endl;
    cout<<"\tAlamat Kos          : "<< alamatkos[pesan1d][pesan2d] << endl;
    cout<<"\tFasilitas Kos       : "<< fasilitas[pesan1d][pesan2d] << endl;
    cout<<"\tJenis Kos           : "<< jeniskos[pesan1d][pesan2d] << endl;
    cout<<"\tHarga Kos Per Bulan : "<< harga[pesan1d][pesan2d] << endl;
    cout<<"Input tanggal masuk (dd/mm/yyyy) : "; getline(cin>>ws, tglmasuk);
    cout<<"Input durasi sewa (dalam bulan) : "; cin >> durasi;
    cout<<"Total Harga yang harus dibayar : " << harga[pesan1d][pesan2d]*durasi << endl;
    cout<<"Silakan Hubungi Pemilik untuk konfirmasi!" << endl;
    pause();
}

void menupenyewa(){
    string menupen;
    do{
        stay = true;
        system("cls");
        cout<<"+"<<setfill('=')<<setw(52)<<"=+\n";
        cout<<"|"<<setfill(' ')<<setw(30)<<"MENU PENYEWA"<<setw(22)<<"|\n";
        cout<<"+"<<setfill('=')<<setw(52)<<"=+\n";
        cout<<"| Pilih Menu" <<setfill(' ')<<setw(41)<<"|\n";
        cout<<"| 1. Lihat Kos "<<setfill(' ')<<setw(38)<<"|\n";
        cout<<"| 2. Pesan Kos "<<setfill(' ')<<setw(38)<<"|\n";
        cout<<"| 3. Log Out "<<setfill(' ')<<setw(40)<<"|\n";
        cout<<"+"<<setfill('=')<<setw(52)<<"=+\n";
        cout<<"Masukkan Pilihan : ";getline(cin>>ws, menupen);
        if(menupen == "1"){
            lihat();
        } else if(menupen == "2"){
            pesan();
        } else if(menupen == "3"){
            logout();
        } else {
            cout<<"Input Yang Anda Masukkan Salah....\n";
            cout<<"Silahkan Coba Lagi!\n";
            pause();
        }
    } while (stay);
}

void login(){
    if (jumlahakun < 1) {
        cout << "Belum ada akun yang dibuat" << endl;
        system("pause");
    } else {
        do {
            stay = true;
            cout << "Username : "; getline(cin>>ws, uname);
            cout << "Password : "; getline(cin>>ws, pass);
            for (int i = 0; i < jumlahakun; i++)
            {
               if ((uname == storuname[i]) && (pass == storpass[i])) {
                cout << "Login Berhasil." << endl;
                akunke = i;
                stay = false;
                if (storetipe[akunke] == "Pemilik Kos") {
                    menupemilik();
                    return;
                } else if (storetipe[akunke] == "Penyewa Kos") {
                    menupenyewa();
                    return;
                }
               } else {
                cout << "Login Gagal. Coba Lagi." << endl;
               }
            }
        } while (stay);
        pause();
    }
}

void createprofile(){
    cout << "Profil pengguna" << endl;
    cout << "Nama Lengkap  : "; getline(cin>>ws, namaleng[user]);
    cout << "No Telepon    : "; getline(cin>>ws, notel[user]);
    cout << "Email         : "; getline(cin>>ws, email[user]);
    cout << "Alamat        : "; getline(cin>>ws, alamatuser[user]);
    cout << "Jenis Kelamin : "; getline(cin>>ws, genderuser[user]);
}

void signin(){
    cout << "Masuk sebagai Pemilik(1) / Penyewa(2)? : "; cin >> tipeakun;
    cout << "Username      : "; getline(cin>>ws, uname);
    cout << "Password      : "; getline(cin>>ws, pass);
    createprofile();
    storuname[user] = uname;
    storpass[user] = pass;
    if (tipeakun == 1) {
        storetipe[user] = "Pemilik Kos";
    } else if (tipeakun == 2) {
        storetipe[user] = "Penyewa Kos";
    }
    user++;
    jumlahakun++;
    cout << "Akun Berhasil dibuat." << endl;
    pause();
}

void mainmenu(){
    menu = "0";
    do
    {
        stay = true;
        system("cls");
        cout<<"+"<<setfill('=')<<setw(52)<<"=+\n";
        cout<<"|"<<setfill(' ')<<setw(34)<<"WELCOME TO MAMIKOS"<<setw(18)<<"|\n";
        cout<<"+"<<setfill('=')<<setw(52)<<"=+\n";
        cout<<"| Pilih Menu" <<setfill(' ')<<setw(41)<<"|\n";
        cout<<"| 1. Sign In "<<setfill(' ')<<setw(40)<<"|\n";
        cout<<"| 2. Log In "<<setfill(' ')<<setw(41)<<"|\n";
        cout<<"| 3. Exit Program "<<setfill(' ')<<setw(35)<<"|\n";
        cout<<"+"<<setfill('=')<<setw(52)<<"=+\n";
        cout << "Pilih Menu : ";getline(cin>>ws, menu);
        if (menu < "1" && menu > "3") {
            cout << "Menu tidak tersedia. Silahkan memilih menu yang ada." << endl; 
            system("pause"); }
        else {
            stay = false; }     
    } while (stay);
}

int main(){
    do
    {
        stay = true;
        mainmenu();
        if (menu == "1") {
            signin();
        } else if (menu == "2") {
            login();
        } else if (menu == "3") {
            exitpr();
        }
    } while (staymain);
    
    
}