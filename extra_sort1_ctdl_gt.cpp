#include<iostream>
#include<string>

using namespace std;

int main(){
    string s;
    getline(cin, s);
    int temp = s.find(":");
    while(temp != std::string::npos){
        string n = s.substr(0, temp);
        cout << n << "\n";
        s = s.substr(temp + 1);
        temp = s.find(":");
    }
    cout << s;
}