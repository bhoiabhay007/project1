#include<iostream>
using namespace std;
class employee
{
    private:
    string Name;
    int Salary;
    
    string Designation;
    public:
    void setdata (string name, int salary, string designation)
    {
           
        Name=name;
        Salary=salary;
      Designation=designation;
    }
    void getdata (){
        cout << "Name: " << Name << " Salary: " << Salary << " Designation: " << Designation << endl;
    }
    void rdk(){
        cout<<Name <<endl<<" "<<Salary<<endl<<"  "<<Designation;
    }
};
int main()
{
    employee e1;
    e1.setdata("ABHAY", 50000, "GOOGLE" );
    e1.rdk();

    return 0;
}