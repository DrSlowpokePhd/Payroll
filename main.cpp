#include <iostream>
#include <iomanip>

using namespace std;

float GrossPay(float hours, float rate);
float FedTaxOwed(float gross_pay, float fed_tax_rate);
float StateTaxOwed(float gross_pay, float state_tax_rate);
float NetPay(float gross_pay, float fed_tax_total, float state_tax_total);
float CalcOvertimePay(float hours, float rate);
float CalcOvertimeForce(float hours);

int main() {

    struct Worker {
        string name;
        float hours, rate, fed_tax, state_tax, gross_pay, fed_tax_owed, state_tax_owed, net_pay;
    };
    struct Total {
        float gross_pay, fed_tax_owed, state_tax_owed, net_pay, overtime_pay, overtime_force;
    };

    Worker worker;
    Total totals;
    int workforce;

    cout<< "Enter the number of employees: ";
    cin>> workforce;

    for (int i = 0; i<workforce; i++) {
        cin.ignore();
        cout<< "Enter Name: ";
        getline(cin, worker.name);
        cout<< "Enter hours worked: ";
        cin>> worker.hours;
        cout<< "Enter Hourly Rate: ";
        cin>> worker.rate;
        cout<< "Enter federal tax rate: ";
        cin>> worker.fed_tax;
        cout<< "Enter state tax rate: ";
        cin>> worker.state_tax;
        worker.gross_pay = GrossPay(worker.hours, worker.rate);
        worker.fed_tax_owed = FedTaxOwed(worker.gross_pay, worker.fed_tax);
        worker.state_tax_owed = StateTaxOwed(worker.gross_pay, worker.state_tax);
        worker.net_pay = NetPay(worker.gross_pay, worker.fed_tax_owed, worker.state_tax_owed);
        cout<<fixed;
        cout<< "Worker: "<< worker.name <<endl;
        cout<< setprecision(2)<< "Gross Pay: $"<< worker.gross_pay <<endl;
        cout<< setprecision(2)<< "Federal Tax Owed: $"<< worker.fed_tax_owed <<endl;
        cout<< setprecision(2)<< "State Tax Owed: $"<< worker.state_tax_owed <<endl;
        cout<< setprecision(2)<< "Net Pay: $"<< worker.net_pay <<endl;
        totals.gross_pay += worker.gross_pay;
        totals.fed_tax_owed += worker.fed_tax_owed;
        totals.state_tax_owed = totals.state_tax_owed + worker.state_tax_owed;
        totals.net_pay += worker.net_pay;
        totals.overtime_force += CalcOvertimeForce(worker.hours);
        totals.overtime_pay += CalcOvertimePay(worker.hours, worker.rate);
        cout<<endl;
    }
    cout<<fixed;
    cout<< setprecision(2) << "Total Gross Pay: $"<< totals.gross_pay <<endl;
    cout<< setprecision(2) << "Total Federal Tax Owed: $"<< totals.fed_tax_owed <<endl;
    cout<< setprecision(2) << "Total State Tax Owed: $"<< totals.state_tax_owed <<endl;
    cout<< setprecision(2) << "Total Net Pay: $"<< totals.net_pay <<endl;
    cout<< "Total overtime workers: "<< totals.overtime_force <<endl;
    cout<< "Total overtime pay: "<< totals.overtime_pay <<endl;
    cout<<endl;
    cout<<"Pizza Man said fuck work"<<endl; //pizza man said fuck work
    return 0;
}



float GrossPay(float hours, float rate){
    float gross_pay;
    if (hours > 40) {
        gross_pay = (40 * rate) + ((hours-40) * (rate * 1.5));
    } else {
        gross_pay = hours * rate;
    }
    return gross_pay;
}

float FedTaxOwed(float gross_pay, float fed_tax_rate){
    float fed_tax_owed = gross_pay * fed_tax_rate / 100;
    return fed_tax_owed;
}

float StateTaxOwed(float gross_pay, float state_tax_rate){
    float state_tax_owed = gross_pay * state_tax_rate / 100;
    return state_tax_owed;
}

float NetPay(float gross_pay, float fed_tax_owed, float state_tax_owed){
    float net_pay = gross_pay - fed_tax_owed - state_tax_owed;
    return net_pay;
}

float CalcOvertimePay(float hours, float rate){
    float overtime_pay;
    float overtime_rate = rate*1.5;
    float overtime_hours = hours-40;
    if (hours > 40)
        overtime_pay = overtime_hours*overtime_rate;
    return overtime_pay;
}

float CalcOvertimeForce(float hours){
    float ot_force = 0;
    if (hours > 40)
        ot_force = 1;
    return ot_force;
}