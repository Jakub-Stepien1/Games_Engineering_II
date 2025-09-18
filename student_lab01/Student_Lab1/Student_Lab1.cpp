// Student_Lab1.cpp
/*
Module: COMP H4204 - Games Engineering II
Lab 1: Basic errors debugging and testing
By: Dr. Omer Ali
Date: 01 SEP 2025

Objectives:
- Implement simple arithmetic functions in C++ using two classes.
- Practice identifying faults (defects) and fixing them systematically.
- Document bug fixes clearly with <BUG_x> numbers in comments.
- Use Git to track fixes: commit after fixing each bug with a message explaining the fix.

Expected learning outcomes:
- Understand how simple arithmetic functions can contain subtle faults.
- Gain experience in systematic debugging and documenting fixes.
- Use test cases to confirm correctness and prevent regressions.

Execution:
1) Compile: g++ -std=c++17 -Wall -Wextra Student_Lab1.cpp -o student_lab1
2) Run:     ./student_lab1

--- Identify and Fix Instructions ---
1) Each bug in this code is marked with a placeholder comment like //<BUG_1>.
2) When you fix a bug, leave the <BUG_1> tag and add a short explanation comment.
   Example: //<BUG_1 fixed: changed int to double to avoid integer division>
3) After each fix, commit to Git with a message like:
   git add Student_Lab1.cpp
   git commit -m "Fixed BUG_1: changed int to double to avoid truncation"
4) Repeat for all bugs until program runs correctly.
*/

#include <iostream>
using namespace std;

class Arithmetic1 {
    public:
        // Addition
        int add(int a, int b) {
            return a + b; // <BUG_1: Changed the "-" to a "+"> 
        }

        // Subtraction
        int subtract(int a, int b) {
            return a - b; // <BUG_2: Changed the "+" to a "-" and a missing "}">
        }
};

class Arithmetic2 {
    public:
        // Multiplication
        int multiply(int a, int b) {
            return a * b; // <BUG_3: Changed the "/" to a "*">
        }

        // Division
        double divide(int a, int b) {
            if (b > 0)
            {
                return a / b; // <BUG_4: Added a check to see if the divider is a 0 or negative number>
            }
            else
            {
                return 0;
            }
        }
};

    int main() {
        Arithmetic1 ar1;
        Arithmetic2 ar2;

        int x = 10, y = 5;
        cout << "Addition (10+5): " << ar1.add(x, y) << endl;
        cout << "Subtraction (10-5): " << ar1.subtract(x, y) << endl;
        cout << "Multiplication (10*5): " << ar2.multiply(x, y) << endl;
        cout << "Division (10/5): " << ar2.divide(x, y) << endl;

        return 0;
    }