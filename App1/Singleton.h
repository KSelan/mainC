#pragma once
#include <sstream>


/*
class Singleton
{
private:
	static Singleton * instance;
	Singleton() {} //constructeur privé!!
	~Singleton() {}

public:
	static Singleton * getSingleton() //getter statique
	{
		if (instance == NULL)
		{
			instance = new Singleton();
		}
		return instance;
	}

	static void resetSingleton()
	{
		delete instance;
		instance = NULL;
	}

};

Singleton * Singleton::instance = 0;
//Singleton * Singleton::instance = 0;
*/

class Singleton
{
private:
	static Singleton* m_pInstance;
	Singleton() {};

public:

	static Singleton* GetInstance()
	{
		if (m_pInstance == NULL)
		{
			m_pInstance = new Singleton();
		}
		return m_pInstance;
	}
	static void resetSingleton()
	{
		delete m_pInstance;
		m_pInstance = NULL;
	}

	~Singleton()
	{
		//delete m_pInstance; // The system goes in infinate loop here if i uncomment this  
		m_pInstance = NULL;
	}
};

//Singleton*  Singleton::m_pInstance = NULL;
	

