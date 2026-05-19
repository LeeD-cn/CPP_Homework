#include <iostream>
#include <cstring>
using namespace std;
class String{
 public:
    String(const char *s = "");
    String(const String&);
    ~String();
    void Set(const char *s);
    void Print() const;
    friend String operator +(const String&, const String&);
    String& operator =(const String&);
    String& operator +=(const String&);
 private:
    char *str;
};
String::String(const char *s)
{
    str = new char[strlen(s) + 1];
    strcpy(str, s);
}
String::String(const String& S)
{
    str = new char[strlen(S.str) + 1];
    strcpy(str, S.str);
}
String::~String()
{
    delete []str;
}
void String::Set(const char *s)
{
    delete []str;
    str = new char[strlen(s) + 1];
    strcpy(str, s);
}
void String::Print() const
{
    cout << str << endl;
}
String operator +(const String& S1, const String& S2)
{
    char *st = new char[strlen(S1.str) + strlen(S2.str) + 1];
    strcpy(st, S1.str);
    strcat(st, S2.str);
    String St(st);
    delete []st;
    return St;
}
String& String::operator =(const String& S)
{
    if(&S != this) Set(S.str);
    return *this;
}
String& String::operator +=(const String& S)
{
    char *p = new char[strlen(S.str) + strlen(str) + 1];
    strcpy(p, str);
    strcat(p, S.str);
    delete []str;
    str = p;
    return *this;
}
int main()
{
    String s1("abcd"), s2("efghij"), s3("lmnop");
    s1 += s2;
    s1.Print();
    s3 += s3 += s2;
    s3.Print();
    return 0;
}