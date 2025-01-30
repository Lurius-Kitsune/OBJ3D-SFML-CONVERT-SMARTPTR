#pragma once
#include "ObjectPtr"

template <typename T>
class TWeakPtr : public TSmartPtr<T>
{
	int* count;

public:
	bool HasExpired() const
	{
		return *count <= 1;
	}
	int Count() const
	{
		return *count;
	}

public:
	TWeakPtr() : TSmartPtr<T>(nullptr)
	{
		count = nullptr;
	}
	TWeakPtr(T* _pointer) : TSmartPtr<T>(_pointer)
	{
		count = new int(1);
	}
	TWeakPtr(const TWeakPtr<T>& _other) : TSmartPtr<T>(_other.pointer)
	{
		count = _other.count;
		(*count)++;
	}
	TWeakPtr(const TSharedPtr<T>& _shared) : TSmartPtr<T>(_shared.pointer)
	{
		count = _shared.count;
		(*count)++;
	}
	~TWeakPtr()
	{
		(*count)--;
		if (*count == 0)
		{
			delete count;
		}
	}

public:
	TSharedPtr<T> Lock() const
	{
		if (HasExpired()) return nullptr;
		return TSharedPtr<T>(TSmartPtr<T>::pointer);
	}
};