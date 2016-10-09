#include "ActionChooserFactory.h"
#include "IAActionChooser.h"
#include "InputActionChooser.h"

std::unique_ptr<NextActionChooser> InputActionFactory::createAction(Comportement & c)
{
	return std::make_unique<InputActionChooser>(c);
}

std::unique_ptr<NextActionChooser> IAActionFactory::createAction(Comportement & c)
{
	return std::make_unique<IAActionChooser>(c);
}