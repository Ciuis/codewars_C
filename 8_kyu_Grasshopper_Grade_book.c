/*Grade book

Complete the function so that it finds the average of the three scores passed to it and returns the letter value associated with that grade.
Numerical Score 	Letter Grade
90 <= score <= 100 	'A'
80 <= score < 90 	'B'
70 <= score < 80 	'C'
60 <= score < 70 	'D'
0 <= score < 60 	'F'

Tested values are all between 0 and 100. Theres is no need to check for negative values or values greater than 100.*/

#define 👨‍💼 ((a + b + c) / 3)
#define 👨‍💻(X) return (👨‍💼 >= 90 ? 'A' : 👨‍💼 >= 80 ? 'B' : 👨‍💼 >= 70 ? 'C' : 👨‍💼 >= 60 ? 'D' : 'F')

char get_grade(int a, int b, int c) {
    int X = 👨‍💼;
    👨‍💻(X);
}

/*
char get_grade(a, b, c)
{
    return "FFFFFFDCBAA"[(a+b+c)/30];
}*/
