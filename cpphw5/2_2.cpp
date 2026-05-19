#include <iostream>
#include <cstring>
using namespace std;
class String{
 public:
    String(const char *str = "")
    {
        cout << "调用字符串构造函数" << endl;
        s = new char[strlen(str) + 1];
        strcpy(s, str);
    }
    String(const String& S)
    {
        cout << "调用复制构造函数" << endl;
        s = new char[strlen(S.s) + 1];
        strcpy(s, S.s);
    }
    ~String()
    {
        cout << "调用析构函数" << endl;
        delete []s;
    }
    friend bool operator ==(const String, const String);
    friend bool operator >(const String, const String);
    friend bool operator <(const String, const String);
    friend bool operator !=(const String, const String);
    friend bool operator >=(const String, const String);
    friend bool operator <=(const String, const String);
    friend ostream& operator <<(ostream&, const String);
    friend istream& operator >>(istream&, String&);
 private:
    char *s;  
    friend int cmp(const String S, const String another) 
    {
        int i = 0;
        while(S.s[i] && another.s[i])
        {
            if(S.s[i] - another.s[i] != 0) return S.s[i] - another.s[i];
            i++;
        }
        return S.s[i] - another.s[i];
    }
};
bool operator ==(const String S, const String another) 
{
    bool result = false;
    if(cmp(S, another) == 0) result = true;
    return result;
}
bool operator !=(const String S, const String another) 
{
    bool result = false;
    if(cmp(S, another)) result = true;
    return result;
}
bool operator >(const String S, const String another)
{
    bool result = false;
    if(cmp(S, another) > 0) result = true;
    return result; 
}
bool operator <(const String S, const String another) 
{
    bool result = false;
    if(cmp(S, another) < 0) result = true;
    return result;
}
bool operator >=(const String S, const String another) 
{
    bool result = false;
    if(cmp(S, another) >= 0) result = true;
    return result;
}
bool operator <=(const String S, const String another) 
{
    bool result = false;
    if(cmp(S, another) <= 0) result = true;
    return result;
}
ostream& operator <<(ostream&, const String S)
{
    cout << S.s;
    return cout;
}
istream& operator >>(istream&, String& S)
{
    char str[100] = "";
    cin >> str;
    delete []S.s;
    S.s = new char[strlen(str) + 1];
    strcpy(S.s, str);
    return cin;
}
int main()
{
    String s1, s2;
    cout << "输入两个字符串" << endl;
    cin >> s1 >> s2;
    if(s1 == s2) cout << s1 << "等于" << s2 << endl;
    else if(s1 != s2) 
    {
        cout << s1 << "不等于" << s2 << endl;
        if(s1 >= s2) cout << s1 << "大于等于" << s2 << endl;
        if(s1 <= s2) cout << s1 << "小于等于" << s2 << endl;
        if(s1 > s2) cout << s1 << "大于" << s2 << endl;
        if(s1 < s2) cout << s1 << "小于" << s2 << endl;
    }
    return 0;
}