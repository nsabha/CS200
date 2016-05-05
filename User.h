#ifndef _Users
#define _Users

#include <string>
using namespace std;

class User
{
public:
	User(const string& name);
	void SetUsername(const string& name);
	string GetUsername();

private:
	string m_username;
};

#endif