
#ifndef __PRINTUTILS_HPP__
#define __PRINTUTILS_HPP__

#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;

//Display config

const int order_columm_width = 8;
const int name_columm_width = 20;
const int age_columm_width = 8;
const int score_columm_width = 8;

const string corner_char = "+";
const string vertical_border_char = "|";
const string horizontal_border_char = "-";

void print_row ( string order, string name, string age, string score) {
    cout << "\t" << std :: left 
         << vertical_border_char << setw(order_columm_width) << " " + order 
         << vertical_border_char << setw(name_columm_width) << " " + name
         << vertical_border_char << setw(age_columm_width) << " " + age
         << vertical_border_char << setw(score_columm_width) << " " + score
         << "|\n";
}

//Cơ chế Function Overloading : Cùng tên nhưng mà khác tham số nên đây được coi là 2 hàm khác nhau
void print_row ( int order, string name, int age, float score) {
    std:: stringstream score_ss;
    score_ss << std:: setprecision(3) << score;
    print_row(to_string(order), name, to_string(age),score_ss.str());
}

//Tạo ra khung bảng
std:: string line (int border_width, string c ) {
    string s;
    for ( int i = 0; i < border_width; i++) {
        s += c;
    }
    return s;
}

//Cơ chế Function Overloading : Cùng tên nhưng mà khác tham số nên đây được coi là 2 hàm khác nhau
void print_row () {
    cout << "\t" 
         << corner_char << line (order_columm_width, horizontal_border_char)
         << corner_char << line (name_columm_width , horizontal_border_char)
         << corner_char << line (age_columm_width , horizontal_border_char)
         << corner_char << line (score_columm_width , horizontal_border_char)
         << corner_char;
}
#endif