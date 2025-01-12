#include<iostream>
using namespace std;

struct Datetime {
    int day;
    int month;
    int year;
    
    // Constructor mặc định
    Datetime() : day(1), month(1), year(2000) {} 

    // Constructor có tham số
    Datetime(int a, int b, int c) : day(a), month(b), year(c) {}
};


class Hosobenhnhan{
    private: 
    int mabenhnhan;
    string fullname;
    Datetime ngaynhapvien;
    string mabenh;
    float vienphi;
    public:
    void setmabenhnhan(int a){
        mabenhnhan = a;
    }
    int getmabenhnhan(){
        return mabenhnhan;
    }
    void setfullname(string fn){
        fullname = fn;
    }
    string getfullname(){
        return fullname;
    }
    bool checkdatetime(int a, int b, int c){
        if(a > 31 || a < 0){
            return false;
        }else if(b > 12 || b < 0){
            return false;
        }else if(c < 2000){
            return false;
        }
        return true;
    }
    void setDatetime(int a, int b, int c){
        if(checkdatetime(a, b, c)){
            Datetime* dt = new Datetime(a, b, c);
        }
    }
    void getDatetime(){
        cout << ngaynhapvien.day << "/" << ngaynhapvien.month << "/" << ngaynhapvien.year << endl;
    }
    void setmabenh(string s){
        mabenh = s;
    }
    string getmabenh(){
        return mabenh;
    }
    void setvienphi(float vp){
        vienphi = vp;
    }
    float getvienphi(){
        return vienphi;
    }
    Hosobenhnhan(int a, string fn){
        setmabenhnhan(a);
        setfullname(fn);
    }
};