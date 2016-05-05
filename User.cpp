#include "User.h"

User::User(const string& name)
{
	SetUsername(name);
}

void User::SetUsername(const string& name)
{
	m_username = name;
}

string User::GetUsername()
{
	return m_username;
}