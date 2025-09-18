// File: week2lab1.cpp
#include <iostream>
#include <string>
using namespace std;

// --------- Class 1: input holder ---------
class InputCase {
public:
    int a;
    int b;
    InputCase(int a_, int b_) : a(a_), b(b_) {}
};

// --------- Class 2: the "graph" logic ---------
// Traverses the CFG and returns a path string like "N0->N1->N3->N2".
// Also returns the computed sum via outSum.
class Graph {
public:
    string traverse(const InputCase& in, int& outSum) const {
        string path = "N0";                      // start node
        if (in.a < in.b) {                       // branch 1: a<b
            path += "->N1->N3->N2";
        }
        else if (in.a == in.b) {               // branch 2: a==b
            path += "->N3->N2";
        }
        else {                                 // branch 3: a>b
            path += "->N2";
        }
        outSum = in.a + in.b;                    // final node computes a+b
        return path;
    }
};

// --------- Minimal test harness (no framework) ---------
// One worked example (students add more tests).
class Tests {
public:
    static void runExample() {
        Graph g;

        // Example: force branch a<b
        InputCase t1(1, 1);
        int sum1 = 0;
        string p1 = g.traverse(t1, sum1);
        cout << "Input (a,b)=(" << t1.a << "," << t1.b << ")\n";
        cout << "Path chosen: " << p1 << "\n";
        cout << "Sum: " << sum1 << "\n";

        // Simple pass/fail using if/else (no external library):
        bool pass = true;
        if (p1 != "N0->N1->N3->N2") pass = false;
        if (sum1 != 1) pass = false;

        if (pass) cout << "[PASS] Example test (a<b)\n";
        else      cout << "[FAIL] Example test (a<b)\n";

        // -------------------------------
        // TODO (Student): Add the remaining tests here.
        // 1) a==b  -> expect path "N0->N3->N2" and sum a+b
        // 2) a>b   -> expect path "N0->N2" and sum a+b
        // 3) Boundary ideas (see Section 10): near a==b, e.g., (9,10), (10,10), (11,10)
        // For each test:
        //   - construct InputCase
        //   - call g.traverse()
        //   - print "Path chosen: ..."
        //   - use if/else to check expected path & sum; print [PASS]/[FAIL]
        // -------------------------------
    }
};

int main() {
    Tests::runExample();
    return 0;
}