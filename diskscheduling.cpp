#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <math.h>

using namespace std;

int compare (const void * a, const void * b)
{
  if ( *(int*)a <  *(int*)b ) return -1;
  if ( *(int*)a == *(int*)b ) return 0;
  if ( *(int*)a >  *(int*)b ) return 1;
}
void shift(int a[],const int size)
{
    for(int i=1;i<=size;i++)
        a[i-1]=a[i];
}
class disk
{
private :
    int request[101];
int sorted_request[101];
int number_of_request;
int max;
int direction;
public :
disk()
{
    cout<<"\nEnter maximum disk limit : ";
    cin>>max;
}

void receive_request()
{
    enter_request_number:
    cout<<"\nEnter number of requests (max. 100): ";
    cin>>number_of_request;
    if(number_of_request>100)
        goto enter_request_number;

    current_location:
    cout<<"\nEnter current location : ";
    cin>>request[0];
    sorted_request[0]=request[0];
    if(request[0]>max||request[0]<0)
        goto current_location;

    current_direction:
    cout<<"\nEnter current direction(0:left / 1:right) : ";
    cin>>direction;
    if(direction!=0&&direction!=1)
        goto current_direction;


    for(int i=1;i<=number_of_request;i++)
    {
        cout<<"\nEnter request number "<<i<<" : ";
        cin>>request[i];
        sorted_request[i]=request[i];
        if(request[i]>max||request[i]<0)
        {
            cout<<"\nInvalid request !! Enter again!!";
            i--;
        }
    }
    qsort(sorted_request+1,number_of_request,sizeof(int),compare);

}

int fcfs()
{
    int head_movement=0;
    for(int i=1;i<=number_of_request;i++)
        head_movement+=abs(request[i]-request[i-1]);
    return head_movement;
}
int sstf()
{
    int head_movement=0,flag=0,nor=number_of_request;
    int request[101];
    request[0]=sorted_request[0];
    for(int i=1;i<=number_of_request;i++)
    {
        if(sorted_request[i]>sorted_request[0]&&flag==0)
            flag=i;
        request[i]=sorted_request[i];
    }
    while(nor)
    {
        if(flag==0)
        {
            head_movement+=request[0]-request[nor];
            request[0]=request[nor];
        }
        else if(flag==1)
        {
            head_movement+=abs(request[nor]-request[0]);
            break;
        }
        else if((request[flag]-request[0])>(request[0]-request[flag-1]))
        {
            head_movement+=request[0]-request[flag-1];
            request[0]=request[flag-1];
            flag--;
            shift(request+flag,nor-flag);
        }
        else 
        {
            head_movement+=request[flag]-request[0];
            request[0]=request[flag];
            shift(request+flag,nor-flag);
        }
        nor--;
    }
    return head_movement;
}
int SCAN()
{
    int head_movement=0,flag=0;

    for(int i=1;i<=number_of_request;i++)
        if(sorted_request[i]>sorted_request[0]&&flag==0)
            flag=i;

    if(direction==1)
    {
        if(flag==1)
            head_movement+=sorted_request[number_of_request]-sorted_request[0];

        else 
        {
            head_movement+=max-sorted_request[0];
            head_movement+=max-sorted_request[1];
        }   
    }
    else
    {
        if(flag==0)
            head_movement+=abs(sorted_request[number_of_request]-sorted_request[0]);

        else 
        {
            head_movement+=sorted_request[0];
            head_movement+=sorted_request[number_of_request];
        }
    }
    return head_movement;
}
int CSCAN()
{
    int head_movement=0,flag=0;

    for(int i=1;i<=number_of_request;i++)
        if(sorted_request[i]>sorted_request[0]&&flag==0)
            flag=i;

    if(flag==1)
        head_movement+=sorted_request[number_of_request]-sorted_request[0];
    else 
    {
        head_movement+=max-sorted_request[0];
        head_movement+=max;
        head_movement+=sorted_request[flag-1];
    }   

    return head_movement;
}


int LOOK()
{
    int head_movement=0,flag=0;

    for(int i=1;i<=number_of_request;i++)
        if(sorted_request[i]>sorted_request[0]&&flag==0)
            flag=i;

    if(direction==1)
    {
        if(flag==1)
            head_movement+=sorted_request[number_of_request]-sorted_request[0];

        else 
        {
            head_movement+=sorted_request[number_of_request]-sorted_request[0];
            head_movement+=sorted_request[number_of_request]-sorted_request[1];
        }   
    }
    else
    {
        if(flag==0)
            head_movement+=abs(sorted_request[number_of_request]-sorted_request[0]);

        else 
        {
            head_movement+=sorted_request[1];
            head_movement+=sorted_request[number_of_request]-sorted_request[1];
        }
    }
    return head_movement;
}
int CLOOK()
{
    int head_movement=0,flag=0;

    for(int i=1;i<=number_of_request;i++)
        if(sorted_request[i]>sorted_request[0]&&flag==0)
            flag=i;

    if(flag==1)
        head_movement+=sorted_request[number_of_request]-sorted_request[0];
    else 
    {
        head_movement+=sorted_request[number_of_request]-sorted_request[0];
        head_movement+=sorted_request[number_of_request]-sorted_request[1];
        head_movement+=sorted_request[flag-1]-sorted_request[1];
    }   

    return head_movement;
}
~disk(){}
};

int main()
{
    disk hdd;
    hdd.receive_request();
    cout<<"Total head movement in ";
    cout<<"FCFS is "<<hdd.fcfs()<<endl;
    cout<<"Total head movement in ";
    cout<<"SSTF is "<<hdd.sstf()<<endl;
    cout<<"Total head movement in ";
    cout<<"SCAN is "<<hdd.SCAN()<<endl;
    cout<<"Total head movement in ";
    cout<<"CSCAN is "<<hdd.CSCAN()<<endl;
    cout<<"Total head movement in ";
    cout<<"LOOK is "<<hdd.LOOK()<<endl;
    cout<<"Total head movement in ";
    cout<<"CLOOK is "<<hdd.CLOOK()<<endl;
    _getche();
}  


