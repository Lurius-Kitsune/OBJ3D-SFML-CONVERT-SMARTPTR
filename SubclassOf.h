#pragma once
#include "Macro.h"

template <typename Type>
class SubclassOf
{
	Shared<Type> objectRef;

public:
	FORCEINLINE bool IsValid() const
	{
		return objectRef != nullptr;
	}
	FORCEINLINE Type& GetObject() const
	{
		return *objectRef;
	}

public:
	// Constructeur par défaut
	SubclassOf() = default;
	// Constructeur qui prend une référence
	explicit SubclassOf(const Type& _objectRef)
	{
		objectRef = MakeShared<Type>(_objectRef);
	}
	// Constructeur qui prend un pointeur
	explicit SubclassOf(const Type* _objectRef)
	{
		objectRef = MakeShared<Type>(*_objectRef);
	}
	// Constructeur par copie
	SubclassOf(const SubclassOf<Type>& _other)
	{
		objectRef = _other.objectRef;
	}
	// Constructeur par déplacement
	SubclassOf(SubclassOf<Type>&& _other) noexcept
	{
		objectRef = move(_other.objectRef);
	}

	// Opérateur d'affectation par copie
	SubclassOf<Type>& operator=(const SubclassOf<Type>& _other) 
	{
		if (this != &_other) 
		{
			objectRef = _other.objectRef;
		}

		return *this;
	}
	// Opérateur d'affectation par déplacement
	SubclassOf<Type>& operator=(SubclassOf<Type>&& _other) noexcept 
	{
		if (this != &_other) 
		{
			objectRef = move(_other.objectRef);
		}

		return *this;
	}
};