#pragma once

template <typename T>
class ObjectPtr
{
protected:
	T* pointer;

public:
	FORCEINLINE bool IsValid() const
	{
		return pointer;
	}
	FORCEINLINE T* Get() const
	{
		return pointer;
	}

public:
	ObjectPtr(T* _pointer)
	{
		pointer = _pointer;
	}
	virtual ~ObjectPtr() 
	{
		delete pointer;
	};

public:
	void operator()(nullptr_t)
	{
		pointer = nullptr;
	}
	bool operator!() const
	{
		return pointer == nullptr;
	}
	T& operator*() const
	{
		return *pointer;
	}
	T* operator->() const
	{
		return pointer;
	}
};