#pragma once
template<class T>
class Singleton
{
private:
	static T* instance;

public:

	Singleton()
	{
	}

	virtual ~Singleton()
	{
		if (instance)
		{
			//delete instance;
			instance = nullptr;
		}

		else if (instance == nullptr)
		{
			printf("Singleton instance null\n");
		}
	}

	static T* GetInstance()
	{
		if (instance == nullptr)
		{
			instance = new T();
			//atexit(Destroy);
		}
		return instance;
	}

};

template<class T>
T* Singleton<T>::instance = nullptr;
