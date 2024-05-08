#include<iostream>
using namespace std;
#include<string>

int main(int argc,char* argv[])
{
	int a=atoi(argv[1]);
	int b=atoi(argv[2]);
	char op=argv[3][0];


	switch(op){
		case '+':
		cout<<a<<" + "<<b<<" = "<<a+b<<endl;
		break;
		
		case '-':
		cout<<a<<" - "<<b<<" = "<<a-b<<endl;
		break;
		case '/':
		cout<<a<<" / "<<b<<" = "<<a/b<<endl;
		break;
		case 'M':
		cout<<a<<" * "<<b<<" = "<<a*b<<endl;
		break;
		default:
		cout<<"Invalid input"<<endl;
			}
}
