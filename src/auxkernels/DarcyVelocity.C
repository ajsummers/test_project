
#include "DarcyVelocity.h"

#include "metaphysicl/raw_type.h"

registerMooseObject("test_projectApp", DarcyVelocity);

InputParameters
DarcyVelocity::validParams()
{
  InputParameters params = VectorAuxKernel::validParams();

  // Add a "coupling parameter" to get a variable from the input file
  params.addRequiredCoupledVar("pressure", "The pressure field.");

  return params;
}

DarcyVelocity::DarcyVelocity(const InputParameters & parameters)
  : VectorAuxKernel(parameters),
    // Get the gradient of the variable
    _pressure_gradient(coupledGradient("pressure")),

    // Set reference to the permeability MaterialProperty.
    // Only AuxKernels operating on Elemental Auxiliary Variables can do this
    _permeability(getADMaterialProperty<Real>("permeability")),

    // Set reference to the viscosity MaterialProperty.
    _viscosity(getADMaterialProperty<Real>("viscosity"))
{
}

RealVectorValue
DarcyVelocity::computeValue()
{
  return -MetaPhysicL::raw_value(_permeability[_qp] / _viscosity[_qp]) * _pressure_gradient[_qp];
}
