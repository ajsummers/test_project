//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "test_projectTestApp.h"
#include "test_projectApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

InputParameters
test_projectTestApp::validParams()
{
  InputParameters params = test_projectApp::validParams();
  return params;
}

test_projectTestApp::test_projectTestApp(InputParameters parameters) : MooseApp(parameters)
{
  test_projectTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

test_projectTestApp::~test_projectTestApp() {}

void
test_projectTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  test_projectApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"test_projectTestApp"});
    Registry::registerActionsTo(af, {"test_projectTestApp"});
  }
}

void
test_projectTestApp::registerApps()
{
  registerApp(test_projectApp);
  registerApp(test_projectTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
test_projectTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  test_projectTestApp::registerAll(f, af, s);
}
extern "C" void
test_projectTestApp__registerApps()
{
  test_projectTestApp::registerApps();
}
