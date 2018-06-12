#include <bits/stdc++.h>
using namespace std;

class student;
class secret{
    bool comp(int marks, int totalMarks);
    friend student;
};
bool secret::comp(int marks, int totalMarks)
{
    float perc=(float)marks/totalMarks;
    if(perc>=.40)
        return true;
    else
        return false;
}

class student{
private:
    char name[20];
    int marks;
    int totalMarks;
    secret secob;
public:
    bool readData();

};
bool student::readData()
{
    cin>>name>>marks>>totalMarks;
    bool res=secob.comp(marks,totalMarks);
    return res;
}



int main()
{
    student s;
    bool res=s.readData();
    if(res)
        cout<<"\nPASS";
    else
        cout<<"\nFAIL";
    return 0;
}
