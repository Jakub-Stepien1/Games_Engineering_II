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
        InputCase t1(1, 2);
        int sum1 = 0;
        string p1 = g.traverse(t1, sum1);
        cout << "Input (a,b)=(" << t1.a << "," << t1.b << ")\n";
        cout << "Path chosen: " << p1 << "\n";
        cout << "Sum: " << sum1 << "\n";

        // Simple pass/fail using if/else (no external library):
        bool pass1 = true;
        if (p1 != "N0->N1->N3->N2") pass1 = false;
        if (sum1 != 3) pass1 = false;

        if (pass1) cout << "[PASS] Example test (a<b)\n";
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

        InputCase t2(3, 3);
        int sum2 = 0;
        string p2 = g.traverse(t2, sum2);
        cout << "Input (a,b)=(" << t2.a << "," << t2.b << ")\n";
        cout << "Path chosen: " << p2 << "\n";
        cout << "Sum: " << sum2 << "\n";

        bool pass2 = true;
        if (p2 != "N0->N3->N2") pass2 = false;
        if (sum2 != 6) pass2 = false;

        if (pass2) cout << "[PASS] Test (a==b)\n";
        else       cout << "[FAIL] Test (a==b)\n";

        InputCase t3(5, 3);
        int sum3 = 0;
        string p3 = g.traverse(t3, sum3);
        cout << "Input (a,b)=(" << t3.a << "," << t3.b << ")\n";
        cout << "Path chosen: " << p3 << "\n";
        cout << "Sum: " << sum3 << "\n";

        bool pass3 = true;
        if (p3 != "N0->N2") pass3 = false;
        if (sum3 != 8) pass3 = false;

        if (pass3) cout << "[PASS] Test (a>b)\n";
        else       cout << "[FAIL] Test (a>b)\n";

        // Boundary Tests
        InputCase bt1(9, 10);
        int bsum1 = 0;
        string bp1 = g.traverse(bt1, bsum1);
        cout << "Input (a,b)=(" << bt1.a << "," << bt1.b << ")\n";
        cout << "Path chosen: " << bp1 << "\n";
        cout << "Sum: " << bsum1 << "\n";

        bool bpass1 = true;
        if (bp1 != "N0->N1->N3->N2") bpass1 = false;
        if (bsum1 != 19) bpass1 = false;

        if (bpass1) cout << "[PASS] Boundary test (a<b)\n";
        else      cout << "[FAIL] Boundary test (a<b)\n";

        InputCase bt2(10, 10);
        int bsum2 = 0;
        string bp2 = g.traverse(bt2, bsum2);
        cout << "Input (a,b)=(" << bt2.a << "," << bt2.b << ")\n";
        cout << "Path chosen: " << bp2 << "\n";
        cout << "Sum: " << bsum2 << "\n";

        bool bpass2 = true;
        if (bp2 != "N0->N3->N2") bpass2 = false;
        if (bsum2 != 20) bpass2 = false;

        if (bpass2) cout << "[PASS] Boundary Test (a==b)\n";
        else       cout << "[FAIL] Boundary Test (a==b)\n";

        InputCase bt3(11, 10);
        int bsum3 = 0;
        string bp3 = g.traverse(bt3, bsum3);
        cout << "Input (a,b)=(" << bt3.a << "," << bt3.b << ")\n";
        cout << "Path chosen: " << bp3 << "\n";
        cout << "Sum: " << bsum3 << "\n";

        bool bpass3 = true;
        if (bp3 != "N0->N2") bpass3 = false;
        if (bsum3 != 21) bpass3 = false;

        if (bpass3) cout << "[PASS] Boundary Test (a>b)\n";
        else       cout << "[FAIL] Boundary Test (a>b)\n";
    }
};

int main() {
    Tests::runExample();
    return 0;
}