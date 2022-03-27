#include<string>
#include<iostream>
using namespace std;
class Employee {
	int employee_id;
	string employe_name;
	double salary;
	string designation;
	int grade;
	public:
	void setEmployeId(int id){
		employee_id = id;
	}
	int getEmployeId(){
		return employee_id;
	}
	void setEmployeName(string name){
		employe_name = name;
	}
	string getEmployeName(){
		return employe_name;
	}
	void setEmployeSalary(double salary){
		this->salary = salary;
	}
	double getEmployeSalary() {
		return salary;
	}
	void setEmployeDesignation(string designation) {
		this->designation = designation;
	}
	string getEmployeDesignation() {
		return designation;
	}
	void setEmployeGrade(int grade){
		this->grade = grade;
	}
	int getEmployeGrade(){
		return grade;
	}
};

class Developer : public Employee {
	int manager_id;
	public:
	Developer(){
	}
	Developer(int id,string name,double salary,string designation,int grade) {
		setEmployeId(id);
		setEmployeName(name);
		setEmployeSalary(salary);
		setEmployeDesignation(designation);
		setEmployeGrade(grade);
	}
	void setManager(int id){
		manager_id = id;
	}
};

class Manager : public Employee {
	Developer team[5];
	public:
	Manager(){
	}
	Manager(int id,string name,double salary,string designation,int grade) {
		setEmployeId(id);
		setEmployeName(name);
		setEmployeSalary(salary);
		setEmployeDesignation(designation);
		setEmployeGrade(grade);
	}
	void asignTeam(Developer *d){
		for (int i=0;i<5;i++) {
			d[i].setManager(getEmployeId());
			team[i] = d[i];
		}
	}
	void DisplayData(){
		cout<<"id of manager is "<<getEmployeId()<<endl;
		cout<<"name of manager is "<<getEmployeName()<<endl;
		cout<<"salary of manager is "<<getEmployeSalary()<<endl;
		cout<<"designation of manager is "<<getEmployeDesignation()<<endl;
		cout<<"grade of manager is "<<getEmployeGrade()<<endl;
	}
};

class Date {
	int day;
	int month;
	int year;
	public:
	Date(){
	}
	Date(int d,int m, int y) {
		day = d;
		month = m;
		year = y;
	}
	int  getDay(){
		return day;
	}
	int getMonth(){
		return month;
	}
	int getYear(){
		return year;
	}
	int totalDays(){
		return(year*365*month*30)+day;
	}
	int getNumberOfDays(Date d1){
		int days =totalDays()-d1.totalDays();
		return days;
	}
};

class Project {
	int project_id;
	string project_title;
	string client_name;
	Date start_date;
	Date end_date;
	Manager manager;
	Developer developers[5];
	public:
	Project(){
	}
	Project(int id,string title,string name,Date sdate,Date edate){
		project_id = id;
		project_title=title;
		client_name=name;
		start_date=sdate;
		end_date=edate;
	}
	Project(const Project &project){
		project_id = project.project_id;
		project_title=project.project_title;
		client_name=project.client_name;
		start_date=project.start_date;
		end_date=project.end_date;
	}
	int getprojectId() {
		return project_id;
	}
	string getTitle() {
		return project_title;
	}
	string getClientName() {
		return client_name;
	}
	Date getStartDate() {
		return start_date;
	}
	Date getEndDate() {
		return end_date;
	}
	void asignManager(Manager manager){
		this->manager = manager;
	}
	void asignTeam(Developer *d){
		for (int i=0;i<5;i++) {
			developers [i] = d[i];
		}
	}
	void DisplayProjectTeam(){
		cout<<"information of team members for project "<<project_id<<endl<<endl;
		for(int i=0;i<5;i++)
		{
			cout<<"id of team member is "<<developers[i].getEmployeId()<<endl;
		cout<<"name of team member is "<<developers[i].getEmployeName()<<endl;
		cout<<"salary of team member is "<<developers[i].getEmployeSalary()<<endl;
		cout<<"designation of team member is "<<developers[i].getEmployeDesignation()<<endl;
		cout<<"grade of tean member is "<<developers[i].getEmployeGrade()<<endl<<endl;
		}
	}
	int calculateDuration(){
		return start_date.getNumberOfDays(end_date);
	}
};
class Firm {
	Manager *managers;
	int number_of_managers = 0;
	public:
	Firm(){
		managers = new Manager[100];
	}
	void addManager(Manager manager) {
		managers[number_of_managers++] = manager;
	}
};
Date getDate(string msg) {
	int d,m,y;
	cout<<"input day number of "<<msg<<" :";
	cin>>d;
	cout<<"input month number of "<<msg<<" :";
	cin>>m;
	cout<<"input year of "<<msg<<" :";
	cin>>y;
	Date date(d,m,y);
	return date;
}
Project getProject(int id) {
	string title,name;
	cout<<"input project title: ";
	cin>>title;
	cout<<"input client name: ";
	cin>>name;
	Date sdate = getDate("start Date");
	Date edate =getDate("end Date");
	Project project(id,title,name,sdate,edate);
	return project;
}
int main()
{
	Firm firm;
	Manager manager1(1,"ali",100000,"senior manager",5);
	Developer d11(11,"ali",100000,"seniordev",5);
	Developer d12(12,"ali",100000,"seniordev",4);
	Developer d13(13,"ali",100000,"seniordev",5);
	Developer d14(14,"ali",100000,"juniordev",2);
	Developer d15(15,"ali",100000,"juniordev",1);
	Developer developers1[5] ={ d11,d12,d13,d14,d15};
	manager1.asignTeam(developers1);
	firm.addManager(manager1);

	Manager manager2(2,"ali",100000,"senior manager",5);
	Developer d21(21,"ali",100000,"seniordev",5);
	Developer d22(22,"ali",100000,"seniordev",4);
	Developer d23(23,"ali",100000,"seniordev",5);
	Developer d24(24,"ali",100000,"juniordev",2);
	Developer d25(25,"ali",100000,"juniordev",1);
	Developer developers2[5] ={ d21,d22,d23,d24,d25};
	manager2.asignTeam(developers2);
	firm.addManager(manager2);

	Manager manager3(3,"ali",100000,"senior manager",5);
	Developer d31(31,"ali",100000,"seniordev",5);
	Developer d32(32,"ali",100000,"seniordev",4);
	Developer d33(33,"ali",100000,"seniordev",5);
	Developer d34(34,"ali",100000,"juniordev",2);
	Developer d35(35,"ali",100000,"juniordev",1);
	Developer developers3[5] ={ d31,d32,d33,d34,d35};
	manager3.asignTeam(developers3);
	firm.addManager(manager3);

	Manager manager4(4,"ali",100000,"senior manager",5);
	Developer d41(41,"ali",100000,"seniordev",5);
	Developer d42(42,"ali",100000,"seniordev",4);
	Developer d43(43,"ali",100000,"seniordev",5);
	Developer d44(44,"ali",100000,"juniordev",2);
	Developer d45(45,"ali",100000,"juniordev",1);
	Developer developers4[5] ={ d41,d42,d43,d44,d45};
	manager4.asignTeam(developers4);
	firm.addManager(manager4);

	Manager manager5(5,"ali",100000,"senior manager",5);
	Developer d51(51,"ali",100000,"seniordev",5);
	Developer d52(52,"ali",100000,"seniordev",4);
	Developer d53(53,"ali",100000,"seniordev",5);
	Developer d54(54,"ali",100000,"juniordev",2);
	Developer d55(55,"ali",100000,"juniordev",1);
	Developer developers5[5] ={ d51,d52,d53,d54,d55};
	manager5.asignTeam(developers5);
	firm.addManager(manager5);

	Project project = getProject(1);
	project.asignManager(manager2);
	project.asignTeam(developers2);

	Project project2 = getProject(2);
	project2.asignManager(manager4);
	project2.asignTeam(developers4);

	project.DisplayProjectTeam();
	cout<<"======================"<<endl<<endl;
	project2.DisplayProjectTeam();
}
