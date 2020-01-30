/*********************************************************************************************************************************************
 * Create three classes Person, Professor and Student. The class Person should have data members name and age. 
 * The classes Professor and Student should inherit from the class Person. 
 * The class Professor should have two integer members: publications and cur_id. There will be two member functions: getdata and putdata. 
 * The function getdata should get the input from the user: the name, age and publications of the professor. 
 * The function putdata should print the name, age, publications and the cur_id of the professor.
 * The class Student should have two data members: marks, which is an array of size 6 and cur_id. It has two member functions:
 * getdata and putdata. The function getdata should get the input from the user: the name, age, and the marks of the student in 6 subjects. 
 * The function putdata should print the name, age, sum of the marks and the cur_id of the student.
 * For each object being created of the Professor or the Student class, sequential id's should be assigned to them starting from 1.
 *  Solve this problem using virtual functions, constructors and static variables. 
 * 
 * Input format:
 * The first line of input contains the number of objects that are being created. If the first line of input for each object is 1, 
 * it means that the object being created is of the Professor class, you will have to input the name, age and publications of the professor.
 * If the first line of input for each object is 2, it means that the object is of the Student class, you will have to input the name, 
 * age and the marks of the student in 6 subjects.
 * 
 * Output format:
 * There are two types of output depending on the object.
 * If the object is of type Professor, print the space separated name, age, publications and id on a new line.
 * If the object is of the Student class, print the space separated name, age, the sum of the marks in  subjects and id on a new line.
 * 
 * Constraints:
 * 1 <= len(name) <= 100, where len(name) is the length of the name
 * 1 <= age <= 80
 * 1 <= publications <= 1000
 * 0 <= marks <= 100, where marks is the marks of the student in each subject
 * 
 * Example input:
 * 4
 * 1
 * Walter 56 99
 * 2
 * Jesse 18 50 48 97 76 34 98
 * 2
 * Pinkman 22 10 12 0 8 45 50
 * 1
 * White 58 87
 * 
 * Example Output:
 * Walter 56 99 1
 * Jesse 18 403 1
 * Pinkman 22 135 2
 * White 58 87 2
 ********************************************************************************************************************************************/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Person 
{
protected:
    string name;
    int age;
    int cur_id;
public:
    Person() : name(), age(0), cur_id(0){}

    virtual void getdata() 
    {
        cin >> name >> age;
    }

    virtual void putdata() 
    {
        cout << name << age << "\n";
    }
};

class Professor : public Person 
{
    int publications;
    static int id;
public:
    Professor() : publications(0) 
    {
        cur_id = ++id;
    }
    void getdata() 
    {
        cin >> name >> age >> publications;
    }
    void putdata() 
    {
        cout << name << " " << age << " " << publications << " " << cur_id << endl;
    }
};
// must initialize static varible like this
int Professor::id = 0;

class Student : public Person 
{
    #define TOTAL_MARKS 6
    int marks[TOTAL_MARKS];
    int cur_id;
    static int id;
public:
    Student(): cur_id(0) 
    {
        for (int i = 0; i < TOTAL_MARKS; i++)
        {
            marks[i] = 0;
        }
        cur_id = ++id;
    }
    void getdata() 
    {
        cin >> name >> age;
        for (int i = 0; i < TOTAL_MARKS; i++)
        {
            cin >> marks[i];
        }
    }
    void putdata()
    {
        int sum = 0;
        for (int i = 0; i < TOTAL_MARKS; i++)
        {
            sum += marks[i];
        }
        cout << name << " " << age << " " << sum << " " << cur_id << endl;
    }
};
int Student::id = 0;

int main()
{

    int n, val;
    cin>>n; //The number of objects that is going to be created.
    Person *per[n];

    for(int i = 0;i < n;i++)
    {

        cin>>val;
        if(val == 1)
        {
            // If val is 1 current object is of type Professor
            per[i] = new Professor;

        }
        else per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.

    }

    for(int i=0;i<n;i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;

}
