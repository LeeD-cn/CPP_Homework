#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iterator>
#include <iomanip>
using namespace std;
class Student {
 public:
    int sno;
    string name;
    int get_score() const
    {
        return score;
    }
    Student(int sno, string name, int score)
    {
        this->sno = sno;
        this->name = name;
        this->score = score;
    }
 private:
    int score;
};
bool cmp(const Student& s1, const Student& s2)
{
    if(s1.get_score() > s2.get_score()) return 1;
    else if(s1.get_score() < s2.get_score()) return 0;
    else if(s1.name < s2.name) return 1;
    else if(s1.name > s2.name) return 0;
    else if(s1.sno < s2.sno) return 1;
    return 0;
}
int main()
{
    int n;
    cout << "输入学生人数:";
    cin >> n;
    vector<Student> a;
    int sno, score;
    string name;
    for(int i = 0; i < n; i++)
    {
        cout << "输入学生学号:";
        cin >> sno;
        cout << "输入学生姓名:";
        cin >> name;
        cout << "输入学生成绩:";
        cin >> score;
        a.push_back(Student(sno, name, score));
    }
    sort(a.begin(), a.end(), cmp);
    for(int i = 0, rank = 1; i < n; i++)
    {
        if(i >= 1 && a[i].get_score() != a[i-1].get_score()) rank++;
        cout << left << setw(4) << rank << "--" << setw(8) << a[i].name << "--" 
        << setw(4) << a[i].get_score() << "--" << a[i].sno << endl;
    }
    return 0;
}