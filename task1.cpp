#include<iostream>
using namespace std;
class rectangle
{
    private:
    float length;
    float breadth;
    
    public:
    
    void setdata (float l, float b)
    {
           
        length=l;
        breadth=b;
    }
    void getdata (){
        cout << "Length: " << length << ", Breadth: " << breadth << endl;
    }
    float area(){
        return length * breadth;
    }

};
int main()
{
    rectangle r1;
    r1.setdata(5.25, 10.20);
    cout << "Area of rectangle: " << r1.area() << endl;
    return 0;
}