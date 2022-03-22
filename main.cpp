#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class Student {
private:
    string name;
    string surname;
    int album_number{};
    vector<float> grades;
public:
    void inputation() {
        cout << "Input name ";
        cin >> name;
        cout << "Input surname ";
        cin >> surname;
        cout << "Input album number ";
        album_number = cheaker_of_valid_alnum();
        cout << "Input grades\n";
        vector<float> data_grades;
        int i;
        for (i = 0; i <= 4; i++) {
            cout << "Input" << i + 1 << "-th mark " << endl;
            float j = 0;
            cin >> j;
            if (j >= 2.0 && j <= 5) {
                grades.emplace_back(j);
            }
        }
    }

    void storing_data(string &data_name, string &data_surname, int &data_album_number, vector<float> &data_grades) {
        name = data_name;
        surname = data_surname;
        album_number = data_album_number;
    }

    void display_summary() {
        cout << "Name - " << name << endl;
        cout << "Surname - " << surname << endl;
        cout << "Album number -  " << album_number << endl;
        cout << "Grades" << endl;
        for (int k = 0; k < grades.size(); k++) {
            cout << grades[k] << " ";
        }
        cout << endl;
    }

    void add_new_grades() {
        int g = 0;
        cout << "Enter how many grades you want to add";
        cin >> g;
        for (int d = 0; d < g; d++) {
            float m;
            cout << "Enter" << d + 1 << "mark:" << endl;
            cin >> m;
            if (m >= 2.0 || m <= 5.0) {
                grades.emplace_back(m);
            }
        }
    }

    void mean_grade() {
        float sum = 0;
        sum = accumulate(grades.begin(), grades.end(), 0.0f);
        cout << "The mean grade is " << sum / grades.size() << endl;
    }

    void cheaker_of_2() {
        int twoes = 0;
        int l;
        for (l = 0; l <= grades.size(); l++) {
            if (l == 2.0) {
                twoes++;
            }
        }
        if (twoes < 1) {
            cout << "You haven`t passed the semester" << endl;
        } else {
            cout << " You have passed. Congratulations";
        }
    }

    int cheaker_of_valid_alnum() {
        int amount = 0;
        int i;
        int alnum;
        bool it = true;
        while (it) {
            cin >> alnum;
            int al = alnum;
            while (al % 10 > 0) {
                al /= 10;
                amount++;
            }
            if (amount == 5 || amount == 6) {
                it = false;
            }
            else {
                it = true;
                 cout << "You must write number consisted of 5 or 6 digits";
                 amount = 0;
            }
        }
        return alnum;
    }
};
    int main() {
        Student student;
        student.inputation();
        student.add_new_grades();
        student.display_summary();
        student.mean_grade();
        student.cheaker_of_2();
        student.cheaker_of_valid_alnum();
}
