#include <bits/stdc++.h>
using namespace std;
#define minTarget 5
class ManagingDirector{
	public:
		virtual void printMD()=0;
};


class CEO: public ManagingDirector{
    public:
	    void printMD(){
	    	cout<<"MD of the company is Rohit Mehra"<<endl;
	    }
};

class Employee{ //Class Function
	private:
		int attendance;
	public:
		string name;
		string department;
		string ID;
		int noOfProjects;
		int leave;
		string company;
		int experience;
		int salary;
		int monTarget;
		
		friend class HR;   //Friend Function
};

void printAllEmployees(vector<string> &names){
            if (names.empty()){
    	         cout<<"No Employee Data found"<<endl;
		        }
		    for (auto idx=names.begin(); idx != names.end();idx++)
		         cout<<*idx<<endl;
}
	

	istream&operator>>(istream &input,Employee &E){ //istream
		cout<<"Enter the name of the Employee"<<endl;
		input>>E.name;
		cout<<"Enter the salary of the Employee"<<endl;
		input>>E.salary;
		cout<<"Enter the experience of the Employee"<<endl;
		input>>E.experience;
		return input;
	}
	
	class Manager:public Employee{
		public:
		double budget;
		double deduction;
		Manager(){ //Constructor
			cout<<"Enter employee name"<<endl;
			cin>>name;
			this->name=name;
			cout<<"Enter Employee Salary"<<endl;
			cin>>salary;
			this->salary=salary;
			cout<<"Enter Employee Experience"<<endl;
			cin>>experience;
			this->experience=experience;
			cout<<"Enter Budget"<<endl;
			cin>>budget;
			this->budget=budget;
			cout<<"Enter the deduction"<<endl;
			cin>>deduction;
			this->deduction=deduction;
		}
		~Manager(){} //Destructor
		virtual int appraisalScore(int experience,int attendance,int noOfProjects){   // Virtual Function
			int score;
			score=experience+attendance+noOfProjects*2;
			return score;
		}
        void maintainBudget(){
        	map<string, double>Budget;
        	double x=0.30*budget;
        	double y=0.25*budget;
        	double z=0.35*budget;
        	double k=0.23*budget;
        	Budget.insert(pair<string,double>("Managing Department",x));
        	Budget.insert(pair<string,double>("International Department",y));
        	Budget.insert(pair<string,double>("Local Department",z));
        	Budget.insert(pair<string,double>("HR Department",k));
        	map<string,double>::iterator itr;
        	
        	for(itr=Budget.begin();itr!=Budget.end();itr++)
        	{   cout<<(*itr).first<<" "<<(*itr).second<<endl;
			}
			
			
		}
	void monitorEmployee(Employee &e){
		cout<<"Enter the Number of leave taken by an employee"<<endl;
		cin>>e.leave;
		if(e.noOfProjects<5){
			cout<<"Give warning to the employee"<<endl;
		}
		try{  //Exception Handling
			if(e.leave==1){
				throw deduction;
			}
			else{
				double deduction = e.leave*(salary/30);
				cout<<"Deduction is "<<deduction<<endl;
			}
		}
		    catch(...){
		    	cout<<"No deduction in salary"<<endl;
			}
	}
	
	};
	
	
	class HR:public Employee{
		public:
			string department="HR DEPARTMENT";
			HR(){
				cout<<"Enter the name of employee "<<endl;
				cin>>name;
				this->name=name;
        cout<<"Enter Employee's Experience "<<endl;
				cin>>experience;
				this->experience=experience;
				cout<<"Enter employee's salary "<<endl;
				cin>>salary;
				this->salary=salary;
				
			}
			string hrID="101";
            ~HR(){}
            void showEmployeeData(){
                hrID=" 101 - "+this->name;
                cout<<"Employee's name is "<<this->name<<endl;
                cout<<"Employee experience is"<<this->experience<<endl;
                cout<<"Employee salary is "<<this->salary<<endl;
                cout<<"Employee id is"<<hrID<<endl;
            }
            void updateEmployeeID(vector<string> &ids,string prevID,string newID){  //Vector Function
                bool check=true;
                auto idx = find(ids.begin(),ids.end(), prevID);
                int indexOfEmployee;
                if (idx != ids.end())
                {
                    indexOfEmployee = idx - ids.begin();
                }
                else {
                    cout<<"Employee ID doesn't exist"<<endl;
                    check=false;
                }
                if(check){
                    cout<<"Employee ID updated succesfully"<<endl;
                }
                ids[indexOfEmployee]=newID;
            }
            void employeeAppraisal(int experience,int attendance,int noOfProjects){
                Manager *m1;
                int score=m1->appraisalScore(experience,attendance,noOfProjects);
                if(score<50){
                    cout<<"employee is eligible for 2.5% increment"<<endl;
                }
                else{
                    cout<<"Employee is eligible for 5% increment"<<endl;
                }
            }
            void deleteEmployee(vector<string> &names,vector<string> &ids,string name,string ID){
                auto idxN = find(names.begin(),names.end(), name);
                names.erase(idxN);
                auto idxI = find(ids.begin(),ids.end(), ID);
                ids.erase(idxI);
                if(idxN==names.end()){
                    cout<<"employee deleted succesfully"<<endl;
                }
                else{
                    cout<<"Employee not found"<<endl;
                }
            }
            void newEmployee(vector<string> &names,vector<string> &ids,string name, string ID){
                names.push_back(name);
                ids.push_back(ID);
            }
            
            
    };
    
    class GM: public Manager{
        public:
           int monTarget;
           void target(Employee &e){
              if (e.monTarget>minTarget){
                  cout<<"Target Completed"<<endl;
                }
                else{
                    cout<<"Target not completed"<<endl;
                }
            }
            inline void monitorEmployee(int leave){  //inline function
                if (leave>10)
                {
                    cout<<"Employee is suspended"<<endl;
                }
            }
    };
    

    
   
   
int main(){
vector<string>names;
vector<string>ids;
queue<string>problem;
names.push_back("Rikin");
ids.push_back("HR");
names.push_back("Shubham");
ids.push_back("GM");
names.push_back("Jhankar");
ids.push_back("GR");

int option;
char ch;
do{
        cout<<"--------------------MENU---------------------"<<endl;
        cout<<"1.Enter employee data"<<endl;
        cout<<"2.Show all employee"<<endl;
        cout<<"3.Update employee's ID:"<<endl;
        cout<<"4.Delete Employee from the database"<<endl;
        cout<<"5.Show allocated budget to different departments"<<endl;
        cout<<"6.Show appraisal of an employee fom the database"<<endl;
        cout<<"7.Show leave and projects status of employee"<<endl;

        
		cin>>option;
        switch(option)
        {
            case 1:
            {
			       HR h=HR();
             h.showEmployeeData();
             break;
            }
            case 2:{
               printAllEmployees(names);
               break;
            }
            case 3:
            {
			      HR h1=HR();
            string newID;
            cout<<"Enter the newID of the Employee"<<endl;
            cin>>newID;
            string oldID;
            cout<<"Enter the old ID of the Employee"<<endl;
            cin>>oldID;
            h1.updateEmployeeID(ids,oldID,newID);
            break;
            }
            case 4:
            {
             HR h3=HR();
             string name;
             cout<<"enter the name of  Employee to be deleted"<<endl;
             cin>>name;
             string ID;
             cout<<"enter the ID of the Employee to be deleted"<<endl;
             cin>>ID;
             h3.deleteEmployee(names,ids,name,ID);
             break;
            }
            case 5:
            {
			      Manager m=Manager();
            m.maintainBudget();
            break;
            }
            case 6:
            {
			      HR h2=HR();
            int experience;
            cout<<"EnterEmployees's Experience"<<endl;
            cin>>experience;
            int attendance;
            cout<<"Enter Employee's attendance"<<endl;
            cin>>attendance;
            int numrOfProjects;
            cout<<"Enter  number of projects"<<endl;
            cin>>numrOfProjects;
            h2.employeeAppraisal(experience,attendance,numrOfProjects);
            break;
            }
            
            case 7:
            {
		      	Manager m=Manager();
            Employee e;
            m.monitorEmployee(e);
            break;
            }
            default:
            {
              cout<<"invalid option"<<endl;
              break;
            }
	    }
	    cout<<"If you want to continue press'y' else press 'n' "<<endl;
	    cin>>ch;
    }while(ch=='y');
     
    return 0;
}
	