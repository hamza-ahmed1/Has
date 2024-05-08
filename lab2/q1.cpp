#include <algorithm> 
#include<iostream>
#include<string>
using namespace std; 
int main(int argc, char *argv[]) 
{ 
	int i=1;
	int sum=0;
	while(1)
{
	if(argv[i])
	{
		cout<<argv[i]<<"   ";
		sum+=atoi(argv[i]);
		i++;
	}	
	else{
	int j=i-1;

	cout<<"\nSum is :"<<sum<<endl;
	cout<<"Avarage is :"<<(sum/j)<<endl;
	break;
		}	
}
 
    return 0;
}
