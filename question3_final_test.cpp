#include <iostream>
#include <string>
using namespace std;

void function(string s)
{
    for (int i = 0; i < s.length(); i++)
    {
        int count = 1;
        for (int j = i + 1; j < s.length(); j++)
        {
            if (s[j] == s[i])
            {
                count++;
                s.erase(j, 1);
                j--;
            }
        }
        if (count != 1)
        {
            cout << count << s[i];
        }
        else if (count == 1)
        {
            cout << s[i];
        }
    }
}

int main()
{
    string name;
    cin >> name;
    function(name);
}