#include<iostream>
using namespace std;
int main()
{
	string  msg ,crc , encode="";
	cout<<"enter the message"<<endl;
	getline(cin,msg);
	cout<<"enter crc generator"<<endl;
	getline(cin,crc);
	int m=msg.length(), n=crc.length();
	encode+=msg;
	
	for(int i=1; i<n; i++)
	encode+='0';
	cout<<encode<<endl;
	for(int i=0; i<=encode.length()-n;)
	{
		for(int j=0;j<n;j++)
		encode[i+j]= encode[i+j]==crc[j]?'0':'1';
		for(;i<encode.length()&& encode[i]!='1';i++);
	}
	    cout<<encode.substr(encode.length()-n+1);
	return 0;
}
