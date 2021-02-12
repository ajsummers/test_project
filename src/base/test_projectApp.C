#include "test_projectApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
test_projectApp::validParams()
{
  InputParameters params = MooseApp::validParams();

  // Do not use legacy DirichletBC, that is, set DirichletBC default for preset = true
  params.set<bool>("use_legacy_dirichlet_bc") = false;

  return params;
}

test_projectApp::test_projectApp(InputParameters parameters) : MooseApp(parameters)
{
  test_projectApp::registerAll(_factory, _action_factory, _syntax);
}

test_projectApp::~test_projectApp() {}

void
test_projectApp::registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  ModulesApp::registerAll(f, af, s);
  Registry::registerObjectsTo(f, {"test_projectApp"});
  Registry::registerActionsTo(af, {"test_projectApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
test_projectApp::registerApps()
{
  registerApp(test_projectApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
test_projectApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  test_projectApp::registerAll(f, af, s);
}
extern "C" void
test_projectApp__registerApps()
{
  test_projectApp::registerApps();
}
