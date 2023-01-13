#ifndef STUDENT_H
#define STUDENT_H

//****************************************************************************************************

#include <iostream>

//****************************************************************************************************

using namespace std;

//****************************************************************************************************

struct Student 
{
	int id;
	char name[50];
	float gpa;
	char major[6];
	
	bool operator== (const Student& students) const;
	bool operator!= (const Student& students) const;
	bool operator< (const Student& students) const;
	bool operator<= (const Student& students) const;
	bool operator> (const Student& students) const;
	bool operator>= (const Student& students) const;
	void operator= (Student& students);

	friend ostream &operator << (ostream& ostr, const Student& students);
	friend istream &operator >> (istream& istr, Student& students);

};

//****************************************************************************************************

bool Student::operator==(const Student& right) const 
{
	bool status;

	if (this->id == right.id) 
	{
		status = true;
	}
	else 
	{
		status = false;
	}

	return status;
}

//****************************************************************************************************

bool Student::operator!=(const Student& right) const 
{
	bool status;

	if (this->id != right.id) 
	{
		status = true;
	}
	else 
	{
		status = false;
	}

	return status;
}

//****************************************************************************************************

bool Student::operator<(const Student& right) const
{
	bool status;

	if (this->id < right.id)
	{
		status = true;
	}
	else
	{
		status = false;
	}

	return status;
}

//****************************************************************************************************

bool Student::operator<=(const Student& right) const 
{
	bool status;

	if (this->id <= right.id) 
	{
		status = true;
	}
	else 
	{
		status = false;
	}

	return status;
}

//****************************************************************************************************

bool Student::operator>(const Student& right) const
{
	bool status;

	if (this->id > right.id)
	{
		status = true;
	}
	else
	{
		status = false;
	}

	return status;
}

//****************************************************************************************************

bool Student::operator>=(const Student& right) const
{
	bool status;

	if (this->id >= right.id)
	{
		status = true;
	}
	else
	{
		status = false;
	}

	return status;
}

//****************************************************************************************************

ostream &operator<<(ostream &ostr, const Student &obj) 
{
	ostr << endl << obj.id << ": " << obj.name << " " << endl 
		<< obj.major << " " << obj.gpa << endl;

	return ostr;
}

//****************************************************************************************************

istream &operator>>(istream &istr, Student &stu) 
{
	istr >> stu.id;
	istr.ignore();
	istr.getline(stu.name, 50, '\n');
	istr >> stu.gpa;
	istr >> stu.major;

	return istr;
}

//****************************************************************************************************

void Student::operator=(Student& right)
{
	this->id = right.id;
	this->gpa = right.gpa;

	strcpy_s(this->major, right.major);
	strcpy_s(this->name, right.name);
}

//****************************************************************************************************

#endif