#ifndef STUDENT_H
#define STUDENT_H

#include<iostream>

//Student struct
struct Student 
{
	unsigned long long FN = ULLONG_MAX;
	char first_name[257] = { '\0' };
	char last_name[257] = { '\0' };
};

//Function for print the data in a student struct
void printStudentData(Student s);

#endif
