#include <iostream>
//SIMPLE CALCULATOR

using namespace std;

int main()
{
    cout<<"*************************************************************"<<endl;
    cout<<"                     'CALCULATOR'"<<endl;
    cout<<"*************************************************************"<<endl;
    int ops;//variable to take the value of the type of operation
    float num1,num2,res;//variables to take operands
    char ch;
    do
    {
    cout<<"*************************************************************"<<endl;
    cout<<"1. ADDITION"<<endl;
    cout<<"2. SUBTRACTION"<<endl;
    cout<<"3. MULTIPLICATION"<<endl;
    cout<<"4. DIVISION"<<endl;
    cout<<"*************************************************************"<<endl;
    cout<<"\nChoose the operation to be performed from the above menu:";
    cin>>ops;
    cout<<"\nEnter two operands:";
    cin>>num1>>num2;
    switch(ops)
    {
    case 1:
        res = num1 + num2;
        cout<<"\nYour result is:"<<res<<endl;
        break;
    case 2:
        if(num1>num2)
            res = num1-num2;
        else
            res = num2-num1;
        cout<<"\nYour result is:"<<res<<endl;
        break;
    case 3:
        res = num1*num2;
        cout<<"\nYour result is:"<<res<<endl;
        break;
    case 4:
        if(num1>num2)
            res = num1/num2;
        else
            res = num2/num1;
        cout<<"\nYour result is:"<<res<<endl;
        break;
    default:
        cout<<"You did not choose a valid operation"<<endl;
        break;
    }
    cout<<"\nDo you want to perform more operation?y/n ";
    cin>>ch;
    }while(ch=='y');


    cout<<"************************************************************"<<endl;
    return 0;
}
