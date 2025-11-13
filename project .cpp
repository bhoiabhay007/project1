#include<iostream>
using namespace std;

class time{
        
    public:
     
    int hours;
    int min;
    int sec;

    void inputvalue(int sec){
        hours=(sec/3600);
        min=(sec%3600)/60;
        sec=sec%60;
        cout<<hours<<":"<<min<<":"<<sec<<endl;

    }

    void inputvalue2(int hours,int min,int sec){
        sec=(hours*3600)+(min*60)+(sec);
        cout<<sec;
    }

};

int main(){
    time tm;
    int no,hours,min,sec;
    cout<<"press 1 for convert a sec to hh:mm:ss"<<endl;

    cout<<"press 2 for convert a hh:mm:ss to sec"<<endl;
    cin>>no;

    if (no==1)
    {
        cout<<"enter sec"<<endl;
        cin>>sec;
        tm.inputvalue(sec);

    }

    else if (no==2)
    {
        cout<<"enter hours"<<endl;
        cin>>hours;
        cout<<"enter min"<<endl;
        cin>>min;
        cout<<"enter sec"<<endl;
        cin>>sec;

        tm.inputvalue2(hours,min,sec);
    }
    
    else
    {
        cout<<"invelide no:";


    }

    return 0;
    

}