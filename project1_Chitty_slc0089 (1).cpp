// Sam Chitty
// slc0089
// project1_Chitty_slc0089.cpp
// Compile with g++ and then use ./a.out
#include <iostream>
using namespace std; 
int main(){
double loan;
double interestRate;
double monthlyPaid;
double interestRateC;
double interestTotal;
int currentMonth = 0;
double principal;

cout.setf(ios::fixed); 
cout.setf(ios::showpoint); 
cout.precision(2);


cout << "\nLoan Amount: "; 
cin >> loan;


while(!cin || loan <=0 ) {
    cout << "\nInvalid Loan: " << endl;
    cin.clear();
    cin.ignore(100,'\n');
    cin >> loan;

}








cout << "Interest Rate (% per year): "; 
cin >> interestRate;
while(!cin || interestRate <0 ) {
    cout << "\nInvalid interest rate: " << endl;
    cin.clear();
    cin.ignore(100,'\n');
    cin >> interestRate;

}
double copyInterest = interestRate/12;
interestRate /= 12; 

interestRateC = interestRate / 100; 

cout << "Monthly Payments: "; 
cin >> monthlyPaid;


while(!cin || monthlyPaid < 0 ) {
    cout << "\nInvalid Payment: " << endl;
    cin.clear();
    cin.ignore(100,'\n');
    cin >> monthlyPaid;
}
while((loan*interestRateC) >= monthlyPaid){
  cout << "\nInsufficient Payment: " << endl;
  cin >> monthlyPaid;
}


double mInterest = 0.0;


   


cout << "*****************************************************************\n"
<< "\tAmortization Table\n"
<< "*****************************************************************\n"
<< "Month\tBalance\t\tPayment\tRate\tInterest\tPrincipal\n";
//cout << currentMonth++ << "\t$"<< loan << " \t" << "N/A\tN/A\tN/A\t\tN/A" << endl;
if (currentMonth == 0) { 
  cout << currentMonth++ << "\t$" << loan; 
if (loan < 1000) cout << "\t"; // Formatting MAGIC 
  cout << "\t" << "N/A\tN/A\tN/A\t\tN/A\n"; 
} 
interestRate = ((interestRateC /100)*loan);
while (loan > 0)
{

if(loan < monthlyPaid)
{
mInterest = loan * interestRateC;
principal = loan;
monthlyPaid = loan + mInterest;
loan = 0;
interestTotal += mInterest;
cout << currentMonth++ << "\t$"<< loan << " \t\t$" << monthlyPaid << "\t";
cout << copyInterest << "\t$" << mInterest << "\t\t$" << principal << endl;
break;
  
}

mInterest = loan * interestRateC;
principal = monthlyPaid - mInterest;
loan -= principal;
if(loan<100){
  cout << currentMonth++ << "\t$"<< loan << " \t\t$" << monthlyPaid << "\t";
  cout << copyInterest << "\t$" << mInterest << "\t\t$" << principal << endl;
}else{
cout << currentMonth++ << "\t$"<< loan << " \t$" << monthlyPaid << "\t";
cout << copyInterest << "\t$" << mInterest << "\t\t$" << principal << endl;
}
interestTotal += mInterest;
  
}
 cout << "****************************************************************\n"; 
 cout << "\nIt takes " << --currentMonth << " months to pay off " 
      << "the loan.\n" 
      << "Total interest paid is: $" << interestTotal; 
 cout << endl << endl; 



return 0;
}
