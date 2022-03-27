#include <iostream>
using namespace std;

class Employe
{
protected:
    string Employe_id;
    string Name;
    string Designation;
    float Salary;
    char Grade;
public:
    Employe()//Default Constructors
    {
        Employe_id="null";
        Name="null";
        Designation="null";
        Salary=0;
        Grade='F';
    }

    Employe(string id,string n,string d,float s,char g)//parameters constructor
    {
        Employe_id=id;
        Name=n;
        Designation=d;
        Salary=s;
        Grade=g;
    }
    string   get_Employe_id()
    {
        return Employe_id;
    }
    string  get_Name()
    {
        return Name;
    }
    string  get_Designation()
    {
        return Designation;
    }
    float get_salary()
    {
        return Salary;
    }
    char  get_grade()
    {
        return Grade;

    }
    void  set_Employe_id(string x)
    {
        Employe_id=x;
    }
    void  set_Name(string y)
    {
        Name=y;
    }
    void  set_Designation(string a)
    {
        Designation=a;
    }
    void  set_salary(float s)
    {
        Salary=s;
    }
    void set_grade(char c)
    {
        Grade=c;
    }
    void display_Employe()
    {
        cout<<"your ID is :"<<get_Employe_id()<<endl;
        cout<<"your Name is ="<<get_Name()<<endl;
        cout<<"your Designation is : "<<get_Designation()<<endl;
        cout<<"your salary is :"<<get_salary()<<endl;
        cout<<"your Grade is "<<get_grade()<<endl;

    }

};
class Manager : public Employe
{
private:
    string Manager_ID;
public:

    Manager(string Manager_ID,string id,string n,string d,float s,char g):Employe(id,n,d,s,g)
    {
        setManager_ID(Manager_ID);
    }
    void setManager_ID(string Manager_ID)
    {
        this->Manager_ID = Manager_ID;
    }
    string getManager_ID()
    {
        return this->Manager_ID;
    }
    void display_Manger()
    {

        cout<<"Manger id is "<<getManager_ID()<<endl;
        display_Employe();

    }
};

class Developer : Employe
{
private:
    string Developer_ID;
public:

    Developer(string Developer_ID,string id,string n,string d,float s,char g):Employe(id,n,d,s,g)
    {
        setDeveloper_ID( Developer_ID);
    }

    void setDeveloper_ID(string Developer_ID)
    {
        this->Developer_ID = Developer_ID;
    }
    string getDeveloper_ID()
    {
        return this->Developer_ID;
    }
    void display_Developer()
    {

        cout<<"Manger id is "<<getDeveloper_ID()<<endl;
         display_Employe();

    }


};

int main()
{
    Manager obj1("123","1","Name","Technical Manger",7500.00,'A');
    obj1.display_Manger();
    return 0;
}
