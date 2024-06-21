#include <iostream>
#include <string>
using namespace std;

bool check_in_thuong(char x)
{
    if (x >= 'a' && x <= 'z')
    {
        return true;
    }
    return false;
}

bool check_in_hoa(char x)
{
    if (x >= 'A' && x <= 'Z')
    {
        return true;
    }
    return false;
}

bool check_ki_tu(char x)
{
    if (check_in_hoa(x) || check_in_thuong(x) || x == ' ')
    {
        return true;
    }
    return false;
}

bool check_dk1(string fullname)
{
    for (int i = 0; i < fullname.length(); i++)
    {
        if (check_ki_tu(fullname[i]) == false)
        {
            return false;
        }
    }
    return true;
}

bool check_dk2(string fullname)
{
    for (int i = 0; i < fullname.length(); i++)
    {
        if (fullname[0] == ' ' || fullname[fullname.length() - 1] == ' ' || (fullname[i] == ' ' && fullname[i + 1] == ' '))
        {
            return false;
            break;
        }
    }
    return true;
}

bool check_dk3(string fullname)
{
    if (check_in_thuong(fullname[0]))
    {
        return false;
    }
    for (int i = 1; i < fullname.length(); i++)
    {
        if (fullname[i - 1] == ' ' && check_in_hoa(fullname[i]) == false)
        {
            return false;
        }
        else if (i > 0 && fullname[i - 1] != ' ' && check_in_hoa(fullname[i]))
        {
            return false;
        }
    }
    return true;
}

bool program_1(string fullname)
{
    // (DK1) Chuỗi chỉ bao gồm các chữ cái và khoảng trắng
    // (DK2) Khoảng trắng ko đứng đầu hoặc đứng cuối chuỗi. Giữa các từ trong chuỗi, chỉ được tối đa 1 khoảng trắng
    // (DK3) Chữ cái đầu mỗi từ phải viết hoa, chữ còn lại phải viết thường.
    // Viết các function sau với input là chuỗi kí tự vừa nhập, có thể chọn char array hoặc std::string tuỳ ý.
    if (check_dk1(fullname) == false || check_dk2(fullname) == false || check_dk3(fullname) == false)
    {
        return false;
    }
    return true;
}

string program_2(string &fullname)
{
    if (program_1(fullname))
        return fullname;
    // Xoa dau cach neu co 2 dau cach
    for (int i = 0; i < fullname.length(); i++)
    {
        if (fullname[0] == ' ')
        {
            fullname.replace(0, 1, "");
            i--;
        }
        if (fullname[fullname.length() - 1] == ' ')
        {
            fullname.replace(fullname.length() - 1, 1, "");
            i--;
        }
        if (fullname[i] == ' ' && fullname[i + 1] == ' ')
        {
            fullname.replace(i, 1, "");
            i--;
        }
    }
    // Xoa cac ki tu dac biet
    for (int i = 0; i < fullname.length(); i++)
    {
        while (i <= fullname.length() - 1 && check_ki_tu(fullname[i]) == false)
        {
            fullname.replace(i, 1, "");
            i--;
        }
    }
    // Viet hoa chu cai dau tien
    fullname[0] = toupper(fullname[0]);
    for (int i = 1; i < fullname.length(); i++)
    {
        fullname[i] = tolower(fullname[i]);
        if (fullname[i - 1] == ' ')
        { // nguyen anh vu
            fullname[i] = toupper(fullname[i]);
        }
    }
    return fullname;
}

string program_3(string s)
{
    string kq;
    string chuoibandau = s;
    int k = s.find(" ");
    while (k != string::npos)
    {
        s = s.substr(k + 1); // cat chuoi tu vi tri k+1 den het chuoi
        k = s.find(" ");
    }
    kq = s;
    int j = chuoibandau.find(" ");
    while (j != string::npos)
    {
        kq += chuoibandau[0];
        chuoibandau = chuoibandau.substr(j + 1);
        j = chuoibandau.find(" ");
    }
    for (int i = 0; i < kq.length(); i++)
    {
        kq[i] = tolower(kq[i]);
    }
    kq += "@gmail.com";
    return kq;
}

int main()
{
    std::string fullname;
    std::cout << "Nhap ho ten day du: ";
    std::getline(std::cin, fullname);
    std::cout << "Ket qua 1: " << program_1(fullname) << "\n";
    std::cout << "Ket qua 2: " << program_2(fullname) << "\n";
    std::cout << "Ket qua 3: " << program_3(fullname) << "\n";
}