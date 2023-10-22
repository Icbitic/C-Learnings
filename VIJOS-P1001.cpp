//
// Created by Kalen Suen on 2023/10/5.
//
#include <iostream>
#include <algorithm>

using namespace std;

struct Student {
    string studentName;
    int averageScore = 0;
    int appraisedScore = 0;
    char isCadre = 'N';
    char isWest = 'N';
    int paperNum = 0;
    int scholarship = 0;
};

int calculateScholarship(struct Student& stu) {
    if (stu.averageScore > 80 && stu.paperNum != 0)
        stu.scholarship += 8000;
    if (stu.averageScore > 85 && stu.appraisedScore > 80)
        stu.scholarship += 4000;
    if (stu.averageScore > 90)
        stu.scholarship += 2000;
    if (stu.averageScore > 85 & stu.isWest == 'Y')
        stu.scholarship += 1000;
    if (stu.appraisedScore > 80 && stu.isCadre == 'Y')
        stu.scholarship += 850;
}

int main() {
    Student sch[100];
    int N = 0;
    cin >> N;
    int accumulate = 0;
    int max = 0;
    for (int i = 0; i < N; ++i) {
        cin >> sch[i].studentName >> sch[i].averageScore >> sch[i].appraisedScore >> sch[i].isCadre >> sch[i].isWest >> sch[i].paperNum;
        calculateScholarship(sch[i]);
        accumulate += sch[i].scholarship;
        if (sch[i].scholarship > sch[max].scholarship)
            max = i;
    }
    cout << sch[max].studentName << endl;
    cout << sch[max].scholarship << endl;
    cout << accumulate;

}