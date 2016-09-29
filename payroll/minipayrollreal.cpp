#include <iostream>
#include <iomanip>
#include <stdlib.h>

using namespace std;

class  Employee{
	public:
		string name, position;
		float dailyRate, tax, sss, pagIbig, daysAbsent;
        float solveSalary, netPay, totalDeduction, lateDeduction, absentDeduction, hourlyRate, minutesRate;
        int numberDaysWork, lateInMinutes;
        
        /*calculate gross pay*/
        
        float calculateGrossPay(float dailyRate, int numberDaysWork){
        	return (dailyRate * numberDaysWork);
		}
		
		/* Calculate net pay*/
        float calculateNetPay(float solveSalary, float totalDeduction){
        	return (solveSalary - totalDeduction);
		}
        
        /* Calculate total deduction*/
        float calculateTotalDeduction(float tax, float sss, float pagIbig, float late, float absent){
        	 return (tax + sss + pagIbig + late + absent);
		}
		
		/*calculate late*/
		float getHourlyRate(float dailyRate){
			return (dailyRate /8 );
		}
		
		
		
		float getMinutesRate(float hourlyRate){
			return (hourlyRate/ 60);
		}
	   
	   	float calculateLateDeduction(float minutesRate, int totalMinutesLate){
	   		return (minutesRate * totalMinutesLate);
		}
		
		float calculateAbsentDeduction(float daysAbsent, float dailyRate){
			return(daysAbsent * dailyRate);
		}
		
};

class SystemPrints{
	
	public:
		
		void headerText(){
			cout << "\t ===== EMPLOYEE'S PAYROLL SYSTEM =====";
			cout << "\n\n";
		
		}
		
		void enterEmployee(){
			cout << "Enter Employees Name        :=>   ";
		}
		
		void enterPosition(){
			cout << "Enter Employees Position    :=>   ";
		}
		
		void enterSalaryRate(){
			cout << "Enter Daily Salary Rate     :=> $ ";
		}
		
		void enterNumberOfDaysWorked(){
			 cout << "Enter Number of Day's Worked :=>   ";
		}
		
		void enterTax(){
			cout << "Enter Employee's Tax                    :=> $ ";
		}
		
		void enterSss(){
			cout << "Enter Employee's SSS Contribution       :=> $ ";
		}
		
		void enterPagIbig(){
			 cout << "Enter Employee's PAG-IBIG Contribution  :=> $ ";
		}
		void enterLateInMinutes(){
			 cout << "Enter Late in Minutes:=>  ";
		}
		
		void enterdaysOfAbsent(){
			 cout << "Enter Days of Absent:=>  ";
		}
		
		void displayGrossPay(float salary){
			cout << "\n\n";
			cout << "Your Gross Pay is $ " << fixed
			      << setprecision(2) <<salary << ".";
			cout << "\n\n";
		}
		
		void displayTotalDeduction(float total_deductions){
			cout << "\n\n";
			cout << "Total Deductions  $ " << fixed
			     << setprecision(2) <<total_deductions << ".";
			cout << "\n\n";
		}
		
		void payrolReport(string employee_name, string position, float net_pay ){
			cout << "\n\n";
			cout << " ====== PAYROLL REPORT ======";
			cout << "\n\n";	
			cout << " NAME : " << setw(5)<<     employee_name
			     <<setw(8) << "\n POSITION : " << setw(5)<<  position
			     << setw(8) << "\n NET PAY : $ " << setw(5)<< net_pay;
			
			cout << "\n\n";
		}
};

main(){

	Employee employee;
	SystemPrints sysPrint;
	
	system("COLOR 69");
	
 	sysPrint.headerText();
 	
	sysPrint.enterEmployee();
	cin >>employee.name;
	
	sysPrint.enterPosition();
	cin >> employee.position;
 	
 	sysPrint.enterSalaryRate();
 	cin >> employee.dailyRate;
 	
 	sysPrint.enterNumberOfDaysWorked();
 	cin >> employee.numberDaysWork;

  	employee.solveSalary = employee.calculateGrossPay(employee.dailyRate, employee.numberDaysWork);
	sysPrint.displayGrossPay(employee.solveSalary);
	
	sysPrint.enterTax();
 	cin >> employee.tax;
 	
 	sysPrint.enterSss();
 	cin >> employee.sss;
 	
 	sysPrint.enterPagIbig();
 	cin >> employee.pagIbig;
 	 
 	sysPrint.enterLateInMinutes();
 	cin >> employee.lateInMinutes;
 	
 	sysPrint.enterdaysOfAbsent();
 	cin >> employee.daysAbsent;
 	
 	employee.hourlyRate = employee.getHourlyRate(employee.dailyRate);
 	employee.minutesRate = employee.getMinutesRate(employee.hourlyRate);
 	
 	employee.absentDeduction = employee.calculateAbsentDeduction(employee.daysAbsent, employee.dailyRate);
 	employee.lateDeduction = employee.calculateLateDeduction(employee.minutesRate, employee.lateInMinutes);
 	employee.totalDeduction = employee.calculateTotalDeduction(employee.tax, employee.sss, employee.pagIbig, employee.lateDeduction, employee.absentDeduction);
 	employee.netPay = employee.calculateNetPay(employee.solveSalary, employee.totalDeduction);
 	
	sysPrint.displayTotalDeduction(employee.totalDeduction);
	
 	system("COLOR A9");
 	
 	sysPrint.payrolReport(employee.name, employee.position, employee.netPay);
	system("pause");

}

