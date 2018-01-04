#include<bits/stdc++.h>

using namespace std;

map<string, int> data;
int k;

void enum1()
{
    string s;
    s.resize(1);
    for(int i = 0; i < 26; i++)
    {
        s[0] = 97 + i;
        data[s] = k++;
    }
}

void enum2()
{
    string s;
    s.resize(2);
    for(int i = 0; i < 26; i++)
    {
        for(int j = i + 1; j < 26; j++)
        {
            s[0] = i + 97;
            s[1] = j + 97;
            data[s] = k++;
        }
    }
}

void enum3()
{
    string s;
    s.resize(3);
    for(int i = 0; i < 26; i++)
    {
        for(int j = i + 1; j < 26; j++)
        {
            for(int l = j + 1; l < 26; l++)
            {
                s[0] = i + 97;
                s[1] = j + 97;
                s[2] = l + 97;
                data[s] = k++;
            }
        }
    }
}

void enum4()
{
    string s;
    s.resize(4);
    for(int i = 0; i < 26; i++)
    {
        for(int j = i + 1; j < 26; j++)
        {
            for(int l = j + 1; l < 26; l++)
            {
                for(int m = l + 1; m < 26; m++)
                {
                    s[0] = i + 97;
                    s[1] = j + 97;
                    s[2] = l + 97;
                    s[3] = m + 97;
                    data[s] = k++;
                }
            }
        }
    }
}

void enum5()
{
    string s;
    s.resize(5);
    for(int i = 0; i < 26; i++)
    {
        for(int j = i + 1; j < 26; j++)
        {
            for(int l = j + 1; l < 26; l++)
            {
                for(int m = l + 1; m < 26; m++)
                {
                    for(int f = m + 1; f < 26; f++)
                    {
                        s[0] = i + 97;
                        s[1] = j + 97;
                        s[2] = l + 97;
                        s[3] = m + 97;
                        s[4] = f + 97;
                        data[s] = k++;
                    }
                }
            }
        }
    }
}

int main()
{
    k = 1;
    enum1();
    enum2();
    enum3();
    enum4();
    enum5();
    string input;
    while(cin >> input)
    {
        cout << data[input] << "\n";
    }
    return 0;
}
