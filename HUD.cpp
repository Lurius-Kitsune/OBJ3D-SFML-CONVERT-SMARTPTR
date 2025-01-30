#include "HUD.h"
#include "CameraManager.h"

using namespace Camera;

UI::HUD::HUD()
{
	allWidgets = set<Shared<Widget>>();
	currentWidget = nullptr;
}

void UI::HUD::AddToViewport(Widget* _widget)
{
	_widget->Construct();
}

void UI::HUD::RemoveFromViewport(Widget* _widget)
{
	_widget->Deconstruct();
}