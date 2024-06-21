#include <iostream>
#include <string>
using namespace std;

int program_1(string s)
{
    int count = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ' ')
        {
            count++;
        }
    }
    return count;
}

int program_2(string s)
{
    int count = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ' ')
        {
            count++;
        }
    }
    return s.length() - count;
}

string program_3(string s)
{
    for (int i = 0; i < s.length(); i++)
    {
        s[i] = toupper(s[i]);
    }
    return s;
}

string program_4(string s)
{
    string s1;
    string s2;
    string ketqua;
    for (int i = 0; i < s.length(); i++)
    {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
        {
            s1 += s[i];
        }
        else if (s[i] >= '0' && s[i] < '9')
        {
            s2 += s[i];
        }
    }
    ketqua = s1 + " " + s2;
    return ketqua;
}

string program_5(string s)
{
    string kq;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            switch (s[i])
            {
            case '0':
                kq += "khong";
                break;
            case '1':
                kq += "mot";
                break;
            case '2':
                kq += "hai";
                break;
            case '3':
                kq += "ba";
                break;
            case '4':
                kq += "bon";
                break;
            case '5':
                kq += "nam";
                break;
            case '6':
                kq += "sau";
                break;
            case '7':
                kq += "bay";
                break;
            case '8':
                kq += "tam";
                break;
            case '9':
                kq += "chin";
                break;
            }
        }
        else
            kq += s[i];
    }
    return kq;
}

void program_6(std::string s) {
    for (int i = 0; i < s.length(); i++) {
        int count = 1;
        for (int j = i + 1; j < s.length(); j++) {
            if (s[i] == s[j]) {
                count++;
                s.erase(j, 1); // Xóa ký tự trùng lặp
                j--; // Giảm chỉ số j để xem xét phần tử tiếp theo sau khi xóa
            }
        }
        if (std::isalpha(s[i])) {
            std::cout << "(" << s[i] << "-" << count << ")";
            if (i < s.length() - 1 && std::isalpha(s[i + 1])) // Kiểm tra nếu ký tự tiếp theo là chữ cái thì in dấu phẩy
                std::cout << ", ";
            else if (!std::isalpha(s[i + 1])) // Kiểm tra nếu ký tự tiếp theo không phải là chữ cái (là số) thì bỏ dấu phẩy
                std::cout << " ";
        }
    }
}

int main()
{
    std::string s;
    std::cout << "Nhap chuoi s: ";
    std::getline(std::cin, s);
    std::cout << "Ket qua 1: " << program_1(s) << "\n";
    std::cout << "Ket qua 2: " << program_2(s) << "\n";
    std::cout << "Ket qua 3: " << program_3(s) << "\n";
    std::cout << "Ket qua 4: " << program_4(s) << "\n";
    std::cout << "Ket qua 5: " << program_5(s) << "\n";
    std::cout << "Ket qua 6: ";
    program_6(s);
}