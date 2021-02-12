#pragma once

// Including the "ADKernel" base class here so we can extend it
#include "ADKernel.h"

/**
 * Computes the residual contribution: K / mu * grad_test * grad_u.
 */
class DarcyPressure : public ADKernel
{
public:
  static InputParameters validParams();

  DarcyPressure(const InputParameters & parameters);

protected:
  /// ADKernel objects must override precomputeQpResidual
  virtual ADReal computeQpResidual() override;

  /// The variables which hold the value for K and mu
  /// Updated to take in material properties
  const ADMaterialProperty<Real> & _permeability;
  const ADMaterialProperty<Real> & _viscosity;
};
