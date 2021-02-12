
#include "DarcyPressure.h"

registerMooseObject("test_projectApp", DarcyPressure);

InputParameters
DarcyPressure::validParams()
{
  InputParameters params = ADKernelGrad::validParams();
  params.addClassDescription("Compute the diffusion term for Darcy pressure ($p$) equation: "
                             "$-\\nabla \\cdot \\frac{\\mathbf{K}}{\\mu} \\nabla p = 0$");
  // Required parameter. MOOSE will error if not provided in input file
  params.addRequiredParam<Real>("permeability", "The isotropic permeability ($K$) of the medium.");
  // Optional parameter w/ default value
  params.addParam<Real>(
    "viscosity",
    7.98e-04,
    "The dynamic viscosity ($\\mu$) of the fluid, the default value is that of water at 30 "
    "degrees Celcius (7.98e-04 Pa-s).");

  return params;
}

DarcyPressure::DarcyPressure(const InputParameters & parameters)
  : ADKernelGrad(parameters),

    // Set the coefficients for the pressure kernel
    _permeability(getParam<Real>("permeability")),
    _viscosity(getParam<Real>("viscosity"))
{
}

ADRealVectorValue
DarcyPressure::precomputeQpResidual()
{
  return (_permeability / _viscosity) * _grad_u[_qp];
}
