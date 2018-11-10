#include<iostream>
using namespace std;
int main()
{   
 int data[10],recdata[10],c1,c2,c3,c=0;
	cout<<"Enter the data word"<<endl;
	cin>>data[0];
	cin>>data[1];
	cin>>data[2];
	cin>>data[4];
	data[6]=data[0]^data[2]^data[4];
	data[5]=data[0]^data[1]^data[4];
	data[3]=data[0]^data[1]^data[2];
	
	for(int i=0; i<7; i++)
	cout<<data[i]<<" ";
	cout<<endl;
	
	cout<<"enter the received data"<<endl;
	for(int j=0; j<7; j++)
	cin>>recdata[j];
	c1=recdata[6]^recdata[0]^recdata[2]^recdata[4];
	c2=recdata[5]^recdata[0]^recdata[1]^recdata[4];
	c3=recdata[3]^recdata[0]^recdata[1]^recdata[2];
	c=c3*4+c2*2+c1;
	if(c==0)
	cout<<"no error";
	else
	{
		if(recdata[7-c]==0)
		recdata[7-c]=1;
		else
		recdata[7-c]=0;
	
		cout<<"corect data"<<endl;
	for(int j=0; j<7; j++)
	cout<<recdata[j];
}
	return 0;
	
}
