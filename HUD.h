#pragma once
#include "Singleton.h"
#include "Widget.h"

namespace UI
{
	class HUD : public Singleton<HUD>
	{
		set<Shared<Widget>> allWidgets;
		Shared<Widget> currentWidget;

		FORCEINLINE void RegisterWidget(Widget* _widget)
		{
			const Shared<Widget>& _widgetPtr = Shared<Widget>(_widget);
			if (allWidgets.contains(_widgetPtr)) return;
			allWidgets.insert(_widgetPtr);
		}
	public:
		template <typename Type, typename ...Args, IS_BASE_OF(Widget, Type)>
		FORCEINLINE Shared<Type> CreateWidget(Args&&... _args)
		{
			Shared<Type> _widget = MakeShared<Type>(forward<Args>(_args)...);
			RegisterWidget(_widget.get);
			return _widget;
		}
		FORCEINLINE void UnregisterWidget(Widget* _widget)
		{
			const Shared<Widget>& _widgetPtr = Shared<Widget>(_widget);
			if (!allWidgets.contains(_widgetPtr)) return;
			allWidgets.erase(_widgetPtr);
		}

	public:
		HUD();

	public:
		void AddToViewport(Widget* _widget);
		void RemoveFromViewport(Widget* _widget);
	};
}