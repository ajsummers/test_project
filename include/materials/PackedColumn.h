
#pragma once

#include "Material.h"

// A helper class from MOOSE that linear interpolates x,y data
#include "LinearInterpolation.h"

/**
 * Material objects inherit from Material and override computeQpProperties.
 * 
 * Their job is to declare properties for use by other objects in the
 * calculation such as Kernels and BoundaryConditions
 */
class PackedColumn : public Material
{
public:
    static InputParameters validParams();

    PackedColumn(const InputParameters & parameters);

protected:
    /// Necessary override. This is where the values of the properties are computed.
    virtual void computeQpProperties() override;

    /// The radius of the spheres in the column
    const Function & _radius;

    /// Value of viscosity from the input file
    const Real & _input_viscosity;

    /// Compute permeability based on the radius (mm)
    LinearInterpolation _permeability_interpolation;

    /// The permeability (K)
    ADMaterialProperty<Real> & _permeability;

    /// The viscosity of the fluid (mu)
    ADMaterialProperty<Real> & _viscosity;
};
