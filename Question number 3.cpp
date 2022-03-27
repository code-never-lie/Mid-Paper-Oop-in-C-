#include<string>
#include<iostream>
using namespace std;
class Employee
{
    int employee_id;
    string employe_name;
    double salary;
    string designation;
    char grade;
public:
    void setEmployeId(int id)
    {
        employee_id = id;
    }
    int getEmployeId()
    {
        return employee_id;
    }
    void setEmployeName(string name)
    {
        employe_name = name;
    }
    string getEmployeName()
    {
        return employe_name;
    }
    void setEmployeSalary(double salary)
    {
        this->salary = salary;
    }
    double getEmployeSalary()
    {
        return salary;
    }
    void setEmployeDesignation(string designation)
    {
        this->designation = designation;
    }
    string getEmployeDesignation()
    {
        return designation;
    }
    void setEmployeGrade(char grade)
    {
        this->grade = grade;
    }
    char getEmployeGrade()
    {
        return grade;
    }
};

class Developer : Employee
{
    int manager_id;
public:
    Developer()
    {
        manager_id=0;
    }
    Developer(int id,string name,double salary,string designation,char grade)
    {
        setEmployeId(id);
        setEmployeName(name);
        setEmployeSalary(salary);
        setEmployeDesignation(designation);
        setEmployeGrade(grade);
    }
    void setManager(int id)
    {
        manager_id = id;
    }
};

class Manager : Employee
{
    Developer team[5];
public:
    Manager()
    {
    }
    Manager(int id,string name,double salary,string designation,char grade)
    {
        setEmployeId(id);
        setEmployeName(name);
        setEmployeSalary(salary);
        setEmployeDesignation(designation);
        setEmployeGrade(grade);
    }
    void DisplayData()
    {
        cout<<"id of manager is "<<getEmployeId()<<endl;
        cout<<"name of manager is "<<getEmployeName()<<endl;
        cout<<"salary of manager is "<<getEmployeSalary()<<endl;
        cout<<"designation of manager is "<<getEmployeDesignation()<<endl;
        cout<<"grade of manager is "<<getEmployeGrade()<<endl;
    }
};

class Date
{
    int day;
    int month;
    int year;
public:
    Date()
    {
    }
    Date(int d,int m, int y)
    {
        day = d;
        month = m;
        year = y;
    }
    int  getDay()
    {
        return day;
    }
    int getMonth()
    {
        return month;
    }
    int getYear()
    {
        return year;
    }
    int totalDays()
    {
        return(year*365*month*30)+day;
    }
    int getNumberOfDays(Date d1)
    {
        int days =totalDays()-d1.totalDays();
        return days;
    }
};

class Project
{
    int project_id;
    string project_title;
    string client_name;
    Date start_date;
    Date end_date;
    Manager manager;
    Developer developers[5];
public:
    Project()
    {
    }
    Project(int id,string title,string name,Date sdate,Date edate)
    {
        project_id = id;
        project_title=title;
        client_name=name;
        start_date=sdate;
        end_date=edate;
    }
    Project(Project &project)
    {
        project_id = project.getprojectId();
        project_title=project.getTitle();
        client_name=project.getClientName();
        start_date=project.getStartDate();
        end_date=project.getEndDate();
    }
    int getprojectId()
    {
        return project_id;
    }
    string getTitle()
    {
        return project_title;
    }
    string getClientName()
    {
        return client_name;
    }
    Date getStartDate()
    {
        return start_date;
    }
    Date getEndDate()
    {
        return end_date;
    }
    void asignManager(Manager manager)
    {
        this->manager = manager;
    }
    void asignTeam(Developer *d)
    {
        for (int i=0; i<5; i++)
        {
            developers [i] = d[i];
        }
    }
    int calculateDuration()
    {
        return start_date.getNumberOfDays(end_date);
    }
};
int main()
{
    cout<<"Now Assign a Project to technical manger"<<endl;
    int manger_id;
    string Name;
    string Designation;
    float Salary;
    char Grade;
    cout<<"Enter manger_id of Project"<<endl;
    cin>>manger_id;
    cout<<"Enter Name of Project"<<endl;
    cin>>Name;
    cout<<"Enter Designation of Project"<<endl;
    cin>>Designation;
    cout<<"Enter Salary of Project"<<endl;
    cin>>Salary;
    cout<<"Enter Grade of Project "<<endl;
    cin>>Grade;
    Manager manager(manger_id,Name,Salary,Designation,Grade);
    int dep_id_d;
    string Name_d;
    string Designation_d;
    float Salary_d;
    char Grade_d;
    cout<<"Now Assign 1 Project to Developer Member"<<endl;
    cout<<"Enter manger_id of Developer Member"<<endl;
    cin>>dep_id_d;
    cout<<"Enter Name of Developer Member"<<endl;
    cin>>Name_d;
    cout<<"Enter Designation of Developer Member"<<endl;
    cin>>Designation_d;
    cout<<"Enter Salary of Developer Member"<<endl;
    cin>>Salary_d;
    cout<<"Enter Grade of Project "<<endl;
    cin>>Grade_d;
    Developer d1(dep_id_d,Name_d,Salary_d,Designation_d,Grade_d);

    cout<<"Now Assign 2 Project to Developer Member"<<endl;
    cout<<"Enter manger_id of Developer Member"<<endl;
    cin>>dep_id_d;
    cout<<"Enter Name of Developer Member"<<endl;
    cin>>Name_d;
    cout<<"Enter Designation of Developer Member"<<endl;
    cin>>Designation_d;
    cout<<"Enter Salary of Developer Member"<<endl;
    cin>>Salary_d;
    cout<<"Enter Grade of Project "<<endl;
    cin>>Grade_d;
    Developer d2(dep_id_d,Name_d,Salary_d,Designation_d,Grade_d);

    cout<<"Now Assign 2 Project to Developer Member"<<endl;
    cout<<"Enter manger_id of Developer Member"<<endl;
    cin>>dep_id_d;
    cout<<"Enter Name of Developer Member"<<endl;
    cin>>Name_d;
    cout<<"Enter Designation of Developer Member"<<endl;
    cin>>Designation_d;
    cout<<"Enter Salary of Developer Member"<<endl;
    cin>>Salary_d;
    cout<<"Enter Grade of Project "<<endl;
    cin>>Grade_d;
    Developer d3(dep_id_d,Name_d,Salary_d,Designation_d,Grade_d);

    cout<<"Now Assign 2 Project to Developer Member"<<endl;
    cout<<"Enter manger_id of Developer Member"<<endl;
    cin>>dep_id_d;
    cout<<"Enter Name of Developer Member"<<endl;
    cin>>Name_d;
    cout<<"Enter Designation of Developer Member"<<endl;
    cin>>Designation_d;
    cout<<"Enter Salary of Developer Member"<<endl;
    cin>>Salary_d;
    cout<<"Enter Grade of Project "<<endl;
    cin>>Grade_d;
    Developer d4(dep_id_d,Name_d,Salary_d,Designation_d,Grade_d);

    cout<<"Now Assign 2 Project to Developer Member"<<endl;
    cout<<"Enter manger_id of Developer Member"<<endl;
    cin>>dep_id_d;
    cout<<"Enter Name of Developer Member"<<endl;
    cin>>Name_d;
    cout<<"Enter Designation of Developer Member"<<endl;
    cin>>Designation_d;
    cout<<"Enter Salary of Developer Member"<<endl;
    cin>>Salary_d;
    cout<<"Enter Grade of Project "<<endl;
    cin>>Grade_d;
    Developer d5(dep_id_d,Name_d,Salary_d,Designation_d,Grade_d);

    Developer developers[5] = { d1,d2,d3,d4,d5};
    int a,b,c,d,e,f;
    cout<<"Enter start date Year,Months,days of project"<<endl;
    cin>>a>>b>>c;
    cout<<"Enter start date Year,Months,days of project"<<endl;
    cin>>d>>e>>f;
    Date sdate(a,b,c);
    Date edate(d,e,f);
    int ab;
    string bc,ca;
    cout<<"Enter project id"<<endl;
    cin>>ab;
    cout<<"Enter Project_Title"<<endl;
    cin>>bc;
    cout<<"Enter Client_Name"<<endl;
    cin>>ca;
    Project project(ab,bc,ca,sdate,edate);
    project.asignManager(manager);
    project.asignTeam(developers);
    int duration = project.calculateDuration();
    cout<<"Your Project duration"<<duration<<endl;
    return 0;
}
