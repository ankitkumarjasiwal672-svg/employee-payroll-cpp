# employee payroll system — c++

made by ankit kumar  
language: c++  
type: portfolio project

---

## about

i made this project to practice c++ — specifically classes, file handling, and vectors. the logic is based on real payroll stuff i deal with at work so it felt more useful to build this than a random textbook example.

it runs in the terminal and lets you manage employees, view payslips, process payroll and save records to a file.

---

## what it does

- view all employees in a table
- search by id and view payslip
- add a new employee
- update salary
- run monthly payroll for everyone (saves to txt file)
- department wise payout breakdown
- auto tax calculation — 10% if basic salary is above 40,000

---

## c++ concepts used

- classes and objects
- constructors
- vectors
- file handling (ofstream)
- loops — for, do-while
- switch case
- iomanip for table formatting
- string, fixed, setprecision

---

## how to run

make sure you have g++ installed

```bash
g++ payroll.cpp -o payroll
./payroll
```

on windows:
```bash
g++ payroll.cpp -o payroll.exe
payroll.exe
```

payroll records get saved to `payroll_output.txt` in the same folder

---

## sample output

```
==============================
   EMPLOYEE PAYROLL SYSTEM
   by ankit kumar
==============================

5 employees loaded.

-- menu --
1. view all employees
2. view payslip
3. add employee
4. update salary
5. run monthly payroll
6. department breakdown
0. exit

ID    Name                Department            Basic       Take Home
----------------------------------------------------------------------
1     Ankit Kumar         Customer Support      55000       52500
2     Sneha Gupta         Quality Assurance     48000       43700
3     Rahul Singh         Customer Support      38000       36800
4     Mohit Yadav         MIS & Reporting       60000       57800
5     Nisha Patel         Customer Support      58000       54200
```

---

## other projects

- [hr employee database](https://github.com/ankitkumarjasiwal672-svg/Hr-system-sql) — mysql / sql
- [budget tracker](https://ankitkumarjasiwal672-svg.github.io/budget-tracker) — html css js

---

open to data analyst / mis analyst roles in delhi ncr  
ankit.kumarjasiwal672@gmail.com
