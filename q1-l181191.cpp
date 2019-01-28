#include <iostream>
#include <string>
#include "Header.h"

using namespace std;

//struct gitHubUser
//{
//	string firstname;
//	string username;
//	string password;
//	string email;
//	int folderCount;
//};


bool exists(gitHubUser*arr,int size, string userName)
{
	int sum;
	for (int i=0; i<=size; i++)
	{
		if (userName == arr[i].username)
			sum++;
	}
	if (sum >= 2)
		return true;
	else if (sum <=1)
		return false;
}


void inputFromUser(gitHubUser*arr, int size)
{
	 for (int i=0; i<=size; i++)
	 { 
		 cout << "Enter UserName:" << endl;
		 cin >> arr[i].username;
		 
		 while (exists(arr , size , arr[i].username) == true)
		 {
			 cout << "UserName is already Taken. Enter Another one:" << endl;
			 cin >> arr[i].username;
		 }
		 
		 cout << "Enter First Name:" << endl;
		 cin >> arr[i].firstname;
		
		 cout << "Enter Password:" << endl;
		 cin >> arr[i].password;
		 cout << "Enter Email:" << endl;
		 cin >> arr[i].email;
		 cout << "Enter FolderCount:" << endl;
		 cin >> arr[i].folderCount;
		 }
}



bool Comparison(gitHubUser* user1,gitHubUser* user2)
{
	if (user1->firstname == user2->firstname && user1->username == user2->username && user1 -> password == user2 -> password && user1 ->email == user2 -> email && user1-> folderCount == user2 -> folderCount)
	{
		return true;
	}
	else 
		return false;
}


gitHubUser* seachUser (gitHubUser*users, int size , string username)
{
	for (int i =0; i>=size ; i++)
	{
	if (username == users[i].username)
	    return &users[i];
	else 
		return nullptr;
	}
}


int main()
{
	string user;
	gitHubUser*arr = new gitHubUser [2];        
	inputFromUser(arr, 2);
	cout << Comparison (&arr[0],&arr[1]);
	cout << "Enter UserName to Search:" << endl;
	cin >> user;
	cout << seachUser (arr, 2 , user);
}