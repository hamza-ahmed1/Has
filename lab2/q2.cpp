#include<iostream>
#include<string>
using namespace std;
bool isPalindrome(string str)
{
int low=0;
int high=str.size()-1;
while(low<high)
{
if(str[low]!=str[high])
{
return false;
}
low++;
high--;
}

return true;
}
int main(int argc,char* argv[])
{
		bool is_palindrome=isPalindrome(argv[1]);
		if(is_palindrome)
		{
			cout<<"string is Palidrome"<<endl;
		}
		else{
		cout<<"String  is not Palindrome"<<endl;
}

}
