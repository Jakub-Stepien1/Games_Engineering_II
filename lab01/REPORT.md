Branch at N0	Covered by test(s)	Evidence (path)
a < b			Test=PASS			N0->N1->N3->N2
a == b 			Test=PASS			N0->N3->N2
a > b 			Test=PASS			N0->N2

Coverage = 3/3 = 100%

Question Answers
A.  Input (a,b)=(1,2)
	Path chosen: N0->N1->N3->N2
	Sum: 3
	PASS Example test (a<b)
	
B.  Input (a,b)=(1,2)
	Path chosen: N0->N1->N3->N2
	Sum: 3
	[PASS] Example test (a<b)
	Input (a,b)=(3,3)
	Path chosen: N0->N3->N2
	Sum: 6
	[PASS] Test (a==b)
	Input (a,b)=(5,3)
	Path chosen: N0->N2
	Sum: 8
	[PASS] Test (a>b)
	
C. 	Input (a,b)=(9,10)
	Path chosen: N0->N1->N3->N2
	Sum: 19
	[PASS] Boundary test (a<b)
	Input (a,b)=(10,10)
	Path chosen: N0->N3->N2
	Sum: 20
	[PASS] Boundary Test (a==b)
	Input (a,b)=(11,10)
	Path chosen: N0->N2
	Sum: 21
	[PASS] Boundary Test (a>b)
	
	It's good for testing when values are within 1 below, equal or 1 above the expected value.
	
D. 	The (a == b) test now takes a different path because it first goes into the (a<=b) which has a different expected results.
	The test outputs a fail so we can easily see there is an issue somewhere in the code.