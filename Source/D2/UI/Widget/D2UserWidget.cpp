


#include "UI/Widget/D2UserWidget.h"

void UD2UserWidget::SetWidgetController(UObject* InWidgetController)
{
	WidgetController = InWidgetController;
	WidgetControllerSet();
}
