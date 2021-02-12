
#include "LaplaceYoungSource.h"

registerMooseObject("test_projectApp", LaplaceYoungSource);

InputParameters
LaplaceYoungSource::validParams()
{
  auto params = ADKernelValue::validParams();
  params.addClassDescription("Source term for Laplace Young equation.");
  params.addParam<Real>("kappa", 1, "Coefficient to the Laplace Young source term.");
  return params;
}

LaplaceYoungSource::LaplaceYoungSource(const InputParameters & parameters) 
: ADKernelValue(parameters),
  _kappa(getParam<Real>("kappa"))
 {}

ADReal
LaplaceYoungSource::precomputeQpResidual()
{
  return _kappa * _u[_qp];
}
