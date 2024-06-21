#include <iostream>
#include <string>
using namespace std;

int program_1(string s1, string s2)
{
    if (s1.length() > s2.length())
        return 1;
    else if (s1.length() < s2.length())
        return -1;
    else
        return 0;
}

void program_2(string s1, string s2)
{
    string kq;
    for (int i = 0; i < s1.length(); i++)
    {
        for (int j = 0; j < s2.length(); j++)
        {
            if (s1[i] == s2[j] && s1[i] != ' ')
            {
                kq += s1[i];
                s2.replace(j, 1, "");
                i--;
                j--;
            }
        }
    }
    for (int i = 0; i < kq.length(); i++)
    {
        for (int j = i + 1; j < kq.length(); j++)
        {
            if (kq[i] == kq[j])
            {
                kq.replace(j, 1, "");
                j--;
            }
        }
    }
    for (int i = 0; i < kq.length(); i++)
    {
        for (int j = i + 1; j < kq.length(); j++)
        {
            if (kq[j] < kq[i])
            {
                char temp = kq[i];
                kq[i] = kq[j];
                kq[j] = temp;
            }
        }
    }
    for (int i = 0; i < kq.length(); i++)
    {
        cout << kq[i];
        if (kq[i] != kq[kq.length() - 1])
        {
            cout << ", ";
        }
    }
}

string program_3(string s1, string s2)
{
    string s3;
    int i = s1.find(' ');
    while (i != string::npos)
    {
        s1 = s1.substr(i + 1);
        i = s1.find(' ');
    }
    int j = s2.find(' ');
    while (j != string::npos)
    {
        s2 = s2.substr(j + 1);
        j = s2.find(' ');
    }
    s3 = s1 + " love " + s2;
    return s3;
}

int program_4(string s1, string s2)
{
    int i = s1.find(' ');
    while (i != string::npos)
    {
        s1 = s1.substr(i + 1);
        i = s1.find(' ');
    }
    int j = s2.find(' ');
    while (j != string::npos)
    {
        s2 = s2.substr(j + 1);
        j = s2.find(' ');
    }
    int count;
    if (s1.length() < s2.length())
    {
        count = s1.length();
    }
    else
        count = s2.length();
    for (int i = 0; i < count; i++)
    {
        if (s1[i] > s2[i])
        {
            return 1;
            break;
        }
        else if (s1[i] < s2[i])
        {
            return -1;
            break;
        }
    }
    return 0;
}

int main()
{
    string s1, s2;
    std::cout << "Nhap ten nguoi 1: ";
    std::getline(std::cin, s1);
    std::cout << "Nhap ten nguoi 2: ";
    std::getline(std::cin, s2);
    std::cout << "Ket qua 1: " << program_1(s1, s2) << "\n";
    std::cout << "Ket qua 2: ";
    program_2(s1, s2);
    std::cout << endl;
    std::cout << "Ket qua 3: " << program_3(s1, s2) << "\n";
    std::cout << "Ket qua 4: " << program_4(s1, s2) << "\n";
}