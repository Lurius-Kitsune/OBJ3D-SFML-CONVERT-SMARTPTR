#pragma once
#include "ObjectPtr"

template <typename T>
class TSharedPtr : public ObjectPtr<T>
{
	int* count;

public:
	inline int Count() const
	{
		return *count;
	}

public:
	SharedPtr() : ObjectPtr<T>(nullptr)
	{
		count = nullptr;
	}
	SharedPtr(T* _pointer) : ObjectPtr<T>(_pointer)
	{
		count = new int(1);
	}
	SharedPtr(const TSharedPtr& _other) : ObjectPtr<T>(_other.pointer)
	{
		count = _other.count;
		(*count)++;
	}
	~SharedPtr()
	{
		Unregister();
	}

public:
	void Unregister()
	{
		if (!count) return;

		(*count)--;
		if ((*count) == 0)
		{
			GarbageCollector::GetInstance().AddToCleanup<T>(TSharedPtr<T>::pointer);
			delete count;
		}
	}

public:
	TSharedPtr<T>& operator=(const TSharedPtr<T>& _other)
	{
		// Si _other n'est pas la même instance que this
		if (this && this != &_other)
		{
			Unregister();
			ObjectPtr<T>::pointer = _other.pointer;
			count = _other.count;
			(*count)++;
		}

		return *this;
	}

	template <typename T>
	friend class WeakPtr;
};