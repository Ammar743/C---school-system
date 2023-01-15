#include "system.h"

void printMenu()
{
	cout<<"****************************************"<<endl;
    cout<<"Please choose from the following list :"<<endl;
    cout<<"\t1-Add student\'s"<<endl;
    cout<<"\t2-Update student\'s score"<<endl;
    cout<<"\t3-Print students scores"<<endl;
    cout<<"\t4-Delete student"<<endl;
    cout<<"\t5-search for teacher's details"<<endl;
    cout<<"\t6-Sort student marks"<<endl;
    cout<<"\t7-End"<<endl;
    cout<<"****************************************"<<endl;

}

void teacerDetails(Teacher teacher[])
{
	string name;
	cout<<"Enter teacher name to see the details ";
	cin>>name;
	for(int i = 0; i < 4; i++)
	{
		if(teacher[i].Tname == name)
		{
			cout<<"Theacher name :" << teacher[i].Tname<<" | ID : "<<teacher[i].ID <<" | Phone number : "<<teacher[i].phone<<"\n";
		}
	}
}

int AdminPass(string Pass)
{
    if (Pass == "2020")
    {
        return 1;
    }
    else
    {
        cout<<"\n Password is wrong!! \n <<You Login temp is denied>>";
        return 0;
    }
}

string calculateGrade(double chemistry, double english, double mathematics,double physics) // calculate the grade
{
	double per;
	string grade;
	per = (chemistry + english + mathematics + physics)/4;
	
	if(per>=90)
		grade="A";
	else if(per>=80)
		grade="B";
	else if(per>=70)
		grade="C";
	else if(per>=60)
		grade="D";
	else
		grade='F';

	return grade;
}

void addStudent(info students[],int &numberOfItems)// add student
{
	numberOfItems++;
	if(numberOfItems < SIZE-1)
	{
		cout<<"Enter your Full Name : ";
		cin.ignore();
        cin.getline(students[numberOfItems].name,50);
        
        cout<<"Enter your ID: ";
        cin>>students[numberOfItems].ID;
        
        cout<<"Enter your marks in physics :";
        cin>>students[numberOfItems].physics;
        
        cout<<"Enter your marks in chemistry :";
		cin>>students[numberOfItems].chemistry;
		
		cout<<"Enter your marks in mathematics :";
		cin>>students[numberOfItems].mathematics;
		
		cout<<"Enter your marks in english :";
		cin>>students[numberOfItems].english;
		cout<<endl;
	}
	else
		cout<<"\nThe array is full.You need to delete items to add";
}
void update(info students[],int numberOfItems)
{
	int chooseSubject,ID,newScore;
	cout<<"Choose the subject that you want to update :"<<endl;
	cout<<"1-physics"<<endl;
	cout<<"2-chemistry"<<endl;
	cout<<"3-mathematics"<<endl;
	cout<<"4-english"<<endl;
	cin>>chooseSubject;
	
	switch(chooseSubject)
	{
		case 1:
			cout<<"\n Enter student ID to update :";
			cin>>ID;
			for(int i = 0; i <= numberOfItems;i++)
				if(students[i].ID == ID)
				{
					cout<<"Enter new mark :";
					cin>>newScore;
					students[i].physics = newScore;
					cout<<"\nStudent Updated"<<endl;
					break;
				}
			break;
		case 2:
			cout<<"\n Enter student ID to update :";
			cin>>ID;
			for(int i = 0; i <= numberOfItems;i++)
				if(students[i].ID == ID)
				{
					cout<<"Enter new mark ";
					cin>>newScore;
					students[i].chemistry = newScore;
					cout<<"\nStudent Updated"<<endl;
					break;
				}
			break;
		case 3:
			cout<<"\n Enter student ID to update :";
			cin>>ID;
			for(int i = 0; i <= numberOfItems;i++)
				if(students[i].ID == ID)
				{
					cout<<"Enter new mark ";
					cin>>newScore;
					students[i].mathematics = newScore;
					cout<<"\nStudent Updated"<<endl;
					break;
				}
			break;
		case 4:
			cout<<"\n Enter student ID to update :";
			cin>>ID;
			for(int i = 0; i <= numberOfItems;i++)
				if(students[i].ID == ID)
				{
					cout<<"Enter new mark ";
					cin>>newScore;
					students[i].english = newScore;
					cout<<"\nStudent Updated"<<endl;
					break;
				}
			break;	
	}
	
}

void Print(info students[],int numberOfItems)// print
{
	for(int i = 0; i <= numberOfItems; i++)
	{
		cout<<"Name :"<<students[i].name<<"\tID : "<<students[i].ID<<endl;
		cout<<"\t | \t physics mark : "<<students[i].physics;
		cout<<"\t | \t chemistry mark : "<<students[i].chemistry;
		cout<<"\t | \t mathematics mark : "<<students[i].mathematics;
		cout<<"\t | \t english mark : "<<students[i].english;
		cout<<"\t | \t your grade is : "<<calculateGrade(students[i].chemistry, students[i].english, students[i].mathematics, students[i].physics);
		cout<<endl;
	}
	cout<<endl;
}
void deleteStudent(info students[],int &numberOfItems)//delete student
{
    int ID;
    if (numberOfItems >= 0)
    {
        cout << "enter student ID to delete:";
        cin >> ID;
        for (int i = 0; i < numberOfItems; i++)
        {
        	if (students[i].ID == ID)
            {
            	for(int j = i; j < numberOfItems ; j++)
            	{
            		students[j] = students[j + 1];
				}
				numberOfItems--;
				cout << "\n student deleted  ";
                cout<<endl;
				break;
            }
		}        
    }
}
void sortScore(info students[])
{
	info temp;
	for(int i = 0; i < SIZE -1; ++i) 
	{
		for(int j = 0; j < SIZE;++j)
		{
			if(calculateGrade(students[j].chemistry, students[j].english, students[j].mathematics, students[j].physics) > calculateGrade(students[j+1].chemistry, students[j+1].english, students[j+1].mathematics, students[j+1].physics))
			{
				temp = students[j];
                students[j] = students[j+1];
                students[j+1] = temp;
			}
		}
	}
}
