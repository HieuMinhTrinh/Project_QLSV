#include <iostream>
#include <string>
#include <fstream>
#include "printutils.hpp"
using namespace std;
const string file_name = "DSach.txt";

struct Student {
    string name;
    int age;
    float point;
    Student* next = NULL;
};
struct StudentList {
    Student* head = NULL;
    
    /************************* MAIN FUNCTION ***********************/
    //1- Khởi tạo dữ liệu cho cấu trúc (Dữ liệu này load từ file lên)
    void init(int& member) {
        std:: ifstream data(file_name);
        string line;
        while (getline(data, line)) {
            int count = 0;
            string person[2];
            int i = line.find(";");
            while ( i != string:: npos) {
                person[count] = line.substr(0,i);
                count++;
                line = line.substr(i+1);
                i = line.find(";");
            }
            person[2] = line;
            Student* student = new Student;
            student->name = person[0];
            student->age = stoi(person[1]);
            student->point = stof(person[2]);
            append(student);
            member++;
        }
        data.close();
    }
    //2- Thêm 1 cái node vào trong danh sach liên kết
    void append(Student* student_append) {
        if ( head == NULL ) {
            head = student_append;
            return;
        }
        Student* p = head;
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = student_append;
    }
    //3- In danh sách liên kết 
    void print_list (Student* student_head) {
        print_row();
        cout << endl;
        print_row ("STT", "Ho va Ten", "Tuoi", "Diem");
        print_row();
        cout << endl;
        int count = 1;
        for (Student* p = student_head; p != NULL; p = p->next ) {
            print_row(count, p->name, p->age, p->point);
            count++;
        }
        print_row();
    }
    //4- Thêm Sinh viên
    void add_student_to_list () {
    string fullname; int add_age; int add_score;
    cin.ignore();
    cout << "(2)- Them sinh vien: " << "\n\t\t (?) - Nhap ten: "; getline(cin,fullname);
    cout << "\t\t (?)- Nhap tuoi: "; cin >> add_age;
    cout << "\t\t (?)- Nhap diem: "; cin >> add_score;
    cout << "Da them thanh cong sinh vien co ten la: " << fullname << ", tuoi: " << add_age << ", diem: " << add_score;
    Student* new_student = new Student;
    new_student->name = fullname;
    new_student->age = add_age;
    new_student->point = add_score;
    append(new_student);
}
    //5- Sửa
    void fix_student_in_list (int fix_index, Student* student_head) {
    int choose;
    int count = 1;
    string fix_name;
    int fix_age;
    float  fix_score;
    Student* p = student_head;
    for (; p != NULL; p = p-> next){
        if ( count == fix_index) {
            break;
        }
        count++;
    }
    cout << "\t\t (!)Ban muon sua gi: " << endl << "\t\t 1- Ten: " << endl << "\t\t 2- Tuoi: " << endl << "\t\t 3- Diem: " << "\t (?) Chon: "; cin >> choose;
    cin.ignore();
    if (choose == 1) {
        cout << "\t\t Nhap ten: "; getline (cin, fix_name);
        p->name = fix_name;
        
    }
    else if (choose == 2 ) {
        cout << "\t\t Nhap tuoi: "; cin >> fix_age;
        p->age = fix_age;
    }
    else if (choose == 3) {
        cout << "\t\t Nhap diem: "; cin >> fix_score;
        p->point = fix_score;
    }
    }
    //6- Xóa
    void remove_student_in_list (int remove_index, Student** remove_head) {
        int count = 1;
        if (remove_index == 0) {
            *remove_head = head->next;
            head = *remove_head;
            return;
        }
        Student* p2_back = head;
        Student* p2 = head->next;
        while (p2 != NULL ) {
            if (count == remove_index) {
                p2_back->next = p2->next;
                delete(p2);
            }
            count++;
            p2_back = p2;
            p2 = p2->next;
        }
        
    }
    //7- Tìm kiếm
    void find_student_in_list () {
        string add_char;
        Student string[100];
        int count_find = 0;

        cout << "[5] Tim kiem " << endl;
        cout << "\t\t (?) Nhap ki tu: "; cin >> add_char;

        for (Student* p = head; p != NULL; p = p->next) {
            if ((p->name).find(add_char) != string:: npos) {
                string[count_find].name = p->name;
                string[count_find].age = p->age;
                string[count_find].point = p->point;
                count_find++;
            }
        }
        print_row();
        cout << endl;
        print_row ("STT", "Ho va Ten", "Tuoi", "Diem");
        print_row();
        cout << endl;
        int count = 1;
        for (int i = 0; i < count_find; i++) {
             print_row(count, string[i].name, string[i].age, string[i].point);
             count++;
        }
        print_row();
    }
    //8- Sắp xếp
    void arrange_list () {
        string choose;
        Student change_info[2];
    
    
        cout << "(6) Sap xep " << endl;
        cout << "\t\t (!) Sap xep the nao: " << endl;
        cout << "\t\t (?) 1- Sap xep theo ten ABC " << endl;
        cout << "\t\t (?) 2- Sap xep theo tuoi tang dan " << endl;
        cout << "\t\t (?) 3- Sap xep theo diem tang dan " << endl;
        cout << "\t\t (?) Chon: "; cin >> choose;
    
        if (choose == "1") {
            for (Student* p_before = head; p_before != NULL; p_before = p_before->next) {
                for (Student* p_after = p_before->next; p_after != NULL; p_after = p_after->next) {
                    if (p_before->name > p_after->name) {
                        change_info[0].name = p_before->name;
                        change_info[0].age = p_before->age;
                        change_info[0].point = p_before->point;

                        p_before->name = p_after->name;
                        p_before->age = p_after->age;
                        p_before->point = p_after->point;

                        p_after->name = change_info[0].name;
                        p_after->age = change_info[0].age;
                        p_after->point =  change_info[0].point;
                        
                    }
                }
            }
            print_row();
            cout << endl;
            print_row ("STT", "Ho va Ten", "Tuoi", "Diem");
            print_row();
            cout << endl;
            int count = 1;
            for (Student* p = head; p != NULL; p = p->next ) {
                print_row(count, p->name, p->age, p->point);
                count++;
            }
            print_row();
        }
        else if (choose == "2") {
            for (Student* p_before = head; p_before != NULL; p_before = p_before->next) {
                for (Student* p_after = p_before->next; p_after != NULL; p_after = p_after->next) {
                    if ( p_before->age > p_after->age) {
                        change_info[1].age = p_before->age;

                        p_before->age = p_after->age;
                        p_after->age = change_info[1].age;
                    }
                }
            
            
            }
        print_row();
        cout << endl;
        print_row ("STT", "Ho va Ten", "Tuoi", "Diem");
        print_row();
        cout << endl;
        int count = 1;
        for (Student* p = head; p != NULL; p = p->next ) {
            print_row(count, p->name, p->age, p->point);
            count++;
        }
        print_row();
        }
        else if (choose == "3") {
            for (Student* p_before = head; p_before != NULL; p_before = p_before->next) {
                for (Student* p_after = p_before->next; p_after != NULL; p_after = p_after->next) {
                    if ( p_before->point > p_after->point) {
                        change_info[1].point = p_before->point;

                        p_before->point = p_after->point;
                        p_after->point = change_info[1].point;
                    }
                }
            }
        print_row();
        cout << endl;
        print_row ("STT", "Ho va Ten", "Tuoi", "Diem");
        print_row();
        cout << endl;
        int count = 1;
        for (Student* p = head; p != NULL; p = p->next ) {
            print_row(count, p->name, p->age, p->point);
            count++;
        }
        print_row();
        }
    }
    // Thống kê
    void statiscal_list (int members) {
    float score_average = 0;
    int person_good = 0;
    int person_rather = 0;
    int person_least = 0;
    float hightest_score = 0;
    
    for (Student* p = head; p != NULL; p = p->next ) {
        score_average += p->point;
        if (p->point >= 8 && p->point <= 10 ) {
            person_good++;
        }
        else if ( p->point >= 5 && p->point < 8 ) {
            person_rather++;
        }
        else if ( p->point >= 0 && p->point < 5) {
            person_least++;
        } 
    }
    float ket_qua_1 = (score_average/members);
    cout << "\t\t(!) Diem trung binh cua cac Sinh vien: " << ket_qua_1 << endl;
    
    float ket_qua_2 = (float)person_good*100/members;
    cout << "\t\t(!) Ti le phan tram hoc sinh gioi: " << ket_qua_2 << setprecision(2) << " %" << endl;
    
    float ket_qua_3 = (float)person_rather*100/members;
    cout << "\t\t(!) Ti le phan tram hoc sinh kha: " << ket_qua_3  << setprecision(2) << " %"  << endl;
    
    float ket_qua_4 = (float)person_least*100/members;
    cout << "\t\t(!) Ti le phan tram hoc sinh kem: " << ket_qua_4  << setprecision(2) << " %" << endl;
    
    cout << "\t\t(!) Sinh vien co diem cao nhat: ";
    for (Student* p = head; p != NULL; p = p->next) {
        if (p->point > hightest_score) {
            hightest_score = p->point;
        }
    }
    for (Student* p = head; p != NULL; p = p->next) {
        if (p->point == hightest_score) {
            cout << p->name << endl << "\t\t\t\t\t     ";
        }
    }
    }
    // Sao lưu
    void past_list_into_file () {
        std:: ofstream Output("DSach.txt");
        for (Student* p = head; p != NULL; p = p->next) {
            Output << p->name << ";" << p->age << ";" << p->point << endl;
        }
    }
};


int main () {
    string option;
    int members = 0;
    int fix_index = 0;
    int remove_index = 0;
    system ("cls");

    StudentList list;
    Student* head;
    
    list.init(members);
    head = list.head;

    while (true) {
        cout << "Danh sach thao tac: "  << endl;
        cout << "1- In danh sach SV " << endl;
        cout << "2- Them" << endl;
        cout << "3- Sua" << endl;
        cout << "4- Xoa" << endl;
        cout << "5- Tim kiem" << endl;
        cout << "6- Sap xep" << endl;
        cout << "7- Thong ke" << endl;
        cout << "8- Sao luu" << endl;
        cout << "9- Thoat" << endl;
        cout << "Nhap lenh: "; cin >> option;
        
        if (option == "1") {
            list.print_list(head);
        }
        
        else if (option == "2") {
            list.add_student_to_list();
            members++;
        }
        
        else if (option == "3") {
            cout << "(3)- Sua thong tin sinh vien" << "\n\t\t (?)Nhap vi tri ban muon fix: "; cin >> fix_index;
            while (fix_index < 0 || fix_index > members) {
                cout << "\t\tGia tri khong dung. Xin vui long nhap lai... ";
                cout << "\n\t\t (?) Nhap lai gia tri ban muon fix: ";
                cin >> fix_index;
            }
            list.fix_student_in_list(fix_index, head);
        }
        
        else if ( option == "4") {
            cout << "(4)- Xoa thong tin sinh vien" << "\n\t\t (?)Nhap vi tri ban muon xoa: "; cin >> remove_index;
            while (remove_index < 0 || remove_index > members) {
                cout << "\t\tGia tri khong dung. Xin vui long nhap lai... ";
                cout << "\n\t\t (?) Nhap lai gia tri ban muon remove: ";
                cin >> remove_index;
            }
            list.remove_student_in_list(remove_index-1, &head);
            members--;
        }
        
        else if ( option == "5") {
            list.find_student_in_list();
        }

        else if ( option == "6") {
            list.arrange_list();
        }
        else if (option == "7")
        {
            list.statiscal_list(members);
        }
        else if (option == "8")
        {
            list.past_list_into_file();
        }
        else if ( option == "9") {
            break;
        }
        cout << "\nPress any key to the continue...";
        cin.ignore();
        //cin >> option;
        //system("cls");
    }
}