// employee payroll system
// made by ankit kumar
// this is a simple console based payroll program i made to practice c++
// covers classes, file handling, vectors, loops, switch case

#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<iomanip>
using namespace std;


// employee class
// stores all the details and has functions to calculate salary stuff

class Employee {

public:
    int id;
    string name;
    string dept;
    string role;
    float basic;
    float bonus;
    float deduction;

    // i used a constructor so i dont have to set values one by one
    Employee(int i, string n, string d, string r, float b, float bon, float ded) {
        id = i;
        name = n;
        dept = d;
        role = r;
        basic = b;
        bonus = bon;
        deduction = ded;
    }

    // net pay = basic + bonus - deduction
    float netPay() {
        return basic + bonus - deduction;
    }

    // simple tax logic — 10% if basic is above 40000
    float tax() {
        if(basic > 40000)
            return basic * 0.10;
        return 0;
    }

    // final take home after tax
    float takeHome() {
        return netPay() - tax();
    }

    void showPayslip() {
        cout << "\n------------------------------" << endl;
        cout << "       PAYSLIP" << endl;
        cout << "------------------------------" << endl;
        cout << "ID         : " << id << endl;
        cout << "Name       : " << name << endl;
        cout << "Dept       : " << dept << endl;
        cout << "Role       : " << role << endl;
        cout << "------------------------------" << endl;
        cout << fixed << setprecision(2);
        cout << "Basic      : Rs." << basic << endl;
        cout << "Bonus      : Rs." << bonus << endl;
        cout << "Deduction  : Rs." << deduction << endl;
        cout << "Tax (10%)  : Rs." << tax() << endl;
        cout << "------------------------------" << endl;
        cout << "Take Home  : Rs." << takeHome() << endl;
        cout << "------------------------------" << endl;
    }

    // saves the payslip to a txt file
    void savePayslip() {
        ofstream f("payroll_output.txt", ios::app);
        if(f.is_open()) {
            f << "------------------------------\n";
            f << "ID       : " << id << "\n";
            f << "Name     : " << name << "\n";
            f << "Dept     : " << dept << "\n";
            f << "Basic    : Rs." << basic << "\n";
            f << "Bonus    : Rs." << bonus << "\n";
            f << "Tax      : Rs." << tax() << "\n";
            f << "Deduction: Rs." << deduction << "\n";
            f << "Take Home: Rs." << takeHome() << "\n";
            f << "------------------------------\n\n";
            f.close();
            cout << "saved to payroll_output.txt" << endl;
        } else {
            cout << "couldnt open file" << endl;
        }
    }
};


// payroll system class
// manages the employee list and handles all the menu operations

class Payroll {

private:
    vector<Employee> empList;

public:

    // added some default data so it works right away when you run it
    void loadData() {
        empList.push_back(Employee(1, "Ankit Kumar",  "Customer Support",  "Senior Team Lead",     55000, 5000, 2000));
        empList.push_back(Employee(2, "Sneha Gupta",  "Quality Assurance", "QA Analyst",           48000, 2000, 1500));
        empList.push_back(Employee(3, "Rahul Singh",  "Customer Support",  "Support Executive",    38000, 0,    1200));
        empList.push_back(Employee(4, "Mohit Yadav",  "MIS & Reporting",   "MIS Analyst",          60000, 6000, 2200));
        empList.push_back(Employee(5, "Nisha Patel",  "Customer Support",  "Team Leader",          58000, 4000, 2000));
        cout << "5 employees loaded." << endl;
    }

    void showAll() {
        if(empList.empty()) {
            cout << "no employees added yet." << endl;
            return;
        }
        cout << "\n" << left << setw(6) << "ID"
             << setw(20) << "Name"
             << setw(22) << "Department"
             << setw(12) << "Basic"
             << "Take Home" << endl;
        cout << string(70, '-') << endl;
        for(int i = 0; i < empList.size(); i++) {
            cout << fixed << setprecision(0);
            cout << left << setw(6)  << empList[i].id
                 << setw(20) << empList[i].name
                 << setw(22) << empList[i].dept
                 << setw(12) << empList[i].basic
                 << empList[i].takeHome() << endl;
        }
        cout << string(70, '-') << endl;
    }

    void addEmployee() {
        int id;
        string name, dept, role;
        float basic, bonus, ded;

        cout << "\n-- add new employee --" << endl;
        cout << "enter id     : "; cin >> id;
        cin.ignore();
        cout << "enter name   : "; getline(cin, name);
        cout << "enter dept   : "; getline(cin, dept);
        cout << "enter role   : "; getline(cin, role);
        cout << "enter basic  : "; cin >> basic;
        cout << "enter bonus  : "; cin >> bonus;
        cout << "enter deduction : "; cin >> ded;

        empList.push_back(Employee(id, name, dept, role, basic, bonus, ded));
        cout << "employee added!" << endl;
    }

    void searchEmp() {
        int id;
        cout << "\nenter employee id : "; cin >> id;
        bool found = false;

        for(int i = 0; i < empList.size(); i++) {
            if(empList[i].id == id) {
                empList[i].showPayslip();
                found = true;

                char ch;
                cout << "save to file? (y/n) : "; cin >> ch;
                if(ch == 'y' || ch == 'Y')
                    empList[i].savePayslip();
                break;
            }
        }
        if(!found)
            cout << "employee not found." << endl;
    }

    void updateSalary() {
        int id;
        cout << "\nenter employee id to update : "; cin >> id;
        bool found = false;

        for(int i = 0; i < empList.size(); i++) {
            if(empList[i].id == id) {
                cout << "current basic : Rs." << empList[i].basic << endl;
                cout << "enter new basic : "; cin >> empList[i].basic;
                cout << "salary updated!" << endl;
                found = true;
                break;
            }
        }
        if(!found)
            cout << "employee not found." << endl;
    }

    // runs payroll for everyone and saves to file
    void runPayroll() {
        if(empList.empty()) {
            cout << "no employees to process." << endl;
            return;
        }

        // clear old output file before writing fresh
        ofstream f("payroll_output.txt");
        f << "============================\n";
        f << "   MONTHLY PAYROLL REPORT\n";
        f << "============================\n\n";
        f.close();

        float total = 0;
        for(int i = 0; i < empList.size(); i++) {
            empList[i].savePayslip();
            total += empList[i].takeHome();
        }

        cout << "\n------------------------------" << endl;
        cout << "payroll done for " << empList.size() << " employees" << endl;
        cout << fixed << setprecision(2);
        cout << "total payout : Rs." << total << endl;
        cout << "check payroll_output.txt for records" << endl;
        cout << "------------------------------" << endl;
    }

    // shows total salary going out per department
    void deptBreakdown() {
        if(empList.empty()) {
            cout << "no employees found." << endl;
            return;
        }

        vector<string> depts;
        for(int i = 0; i < empList.size(); i++) {
            bool exists = false;
            for(int j = 0; j < depts.size(); j++)
                if(depts[j] == empList[i].dept) { exists = true; break; }
            if(!exists) depts.push_back(empList[i].dept);
        }

        cout << "\n-- department breakdown --" << endl;
        for(int i = 0; i < depts.size(); i++) {
            float total = 0;
            int count = 0;
            for(int j = 0; j < empList.size(); j++) {
                if(empList[j].dept == depts[i]) {
                    total += empList[j].takeHome();
                    count++;
                }
            }
            cout << fixed << setprecision(2);
            cout << left << setw(25) << depts[i]
                 << " | emp: " << count
                 << " | payout: Rs." << total << endl;
        }
    }
};


// main function — just the menu loop

int main() {

    Payroll p;
    p.loadData();

    int choice;

    cout << "\n==============================" << endl;
    cout << "   EMPLOYEE PAYROLL SYSTEM" << endl;
    cout << "   by ankit kumar" << endl;
    cout << "==============================" << endl;

    do {
        cout << "\n-- menu --" << endl;
        cout << "1. view all employees" << endl;
        cout << "2. view payslip" << endl;
        cout << "3. add employee" << endl;
        cout << "4. update salary" << endl;
        cout << "5. run monthly payroll" << endl;
        cout << "6. department breakdown" << endl;
        cout << "0. exit" << endl;
        cout << "choice : ";
        cin >> choice;

        switch(choice) {
            case 1: p.showAll();        break;
            case 2: p.searchEmp();      break;
            case 3: p.addEmployee();    break;
            case 4: p.updateSalary();   break;
            case 5: p.runPayroll();     break;
            case 6: p.deptBreakdown();  break;
            case 0: cout << "bye!" << endl; break;
            default: cout << "invalid choice" << endl;
        }

    } while(choice != 0);

    return 0;
}
