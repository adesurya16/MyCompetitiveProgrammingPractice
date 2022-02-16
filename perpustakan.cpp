#include <bits/stdc++.h>
using namespace std;
int main(){
    map<string, int> maps;
    // map

    // PM peminjaman -1 map

    // PB pengembalian +1 map 

    string n;
    getline(cin , n);
    int m = stoi(n);
    string s;
    for(int i = 0;i < m;i++){
        
        getline(cin, s);
        // to map
        maps[s]++;
        // cout << s << endl;
    }

    string str;
    getline(cin, str);
    int i = 0;
    while(str.compare("CL") != 0){
        i++;
        cout << "Pelanggan ke-"<< i <<" : ";
        string code = str.substr(0, 2);
        str.erase(str.begin(), str.begin() + 3);
        if(code.compare("PB") == 0){
            maps[str]++;
            cout << "Terima Kasih Telah Membaca :)" << endl;
        }else{
            if (maps[str] > 0){
                maps[str]--;
                cout << "Buku Tersedia & Berhasil Dipinjam" << endl;
            }else{
                cout << "Maaf Buku Anda Tidak Tersedia, Silahkan Kembali Minggu Depan" << endl;
            }
        }
        getline(cin, str);
    }
        

    // string s;
    // cin >> s;
    // while(s.compare("CL") != 0){

    // }
    return 0;
}