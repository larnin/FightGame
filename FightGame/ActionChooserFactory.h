#pragma once

#include "NextActionChooser.h"
#include <memory>

class Comportement;

class ActionChooserFactory
{
public:
	ActionChooserFactory() = default;
	virtual ~ActionChooserFactory() = default;

	virtual std::unique_ptr<NextActionChooser> createAction(Comportement & c) = 0;
};

class InputActionFactory : public ActionChooserFactory
{
public:
	InputActionFactory() = default;
	virtual ~InputActionFactory() = default;

	virtual std::unique_ptr<NextActionChooser> createAction(Comportement & c) override;
};


class IAActionFactory : public ActionChooserFactory
{
public:
	IAActionFactory() = default;
	virtual ~IAActionFactory() = default;

	virtual std::unique_ptr<NextActionChooser> createAction(Comportement & c) override;
};
