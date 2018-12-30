#include "Student.h"

#include <iostream>

using namespace std;

//Print the data of a student & end the line
void printStudentData(Student s)
{
	cout << s.FN << " " << s.first_name << " " << s.last_name << endl;
}
