#include <cstring>
#ifndef system_h
#define system_h

int const SIZE = 100;
int numberOfItems=-1;


struct Teacher
{
	string Tname;
	string ID;
	string phone;
};
Teacher teacher[5];//Global array of struct


struct info // add and update student
{
	char name[50];
	int ID;
	double physics,chemistry, mathematics, english;
};info students[SIZE];


void addStudent(info students[],int &numberOfItems); //Add student
void update(info students[], int numberOfItems); //Update student
void Print(info students[],int numberOfItems); //Print students names and marks
void deleteStudent(info students[],int &numberOfItems);
void teacerDetails(Teacher teacher[]);
void sortScore(info students[]);
int AdminPass ( string Pass); //ChecK Pass
string calculateGrade(double chemistry, double english, double mathematics,double physics); // calculate the grade
#endif
