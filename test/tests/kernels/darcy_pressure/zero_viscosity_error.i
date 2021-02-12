
[Mesh]
    type = GeneratedMesh
    dim = 1
[]

[Problem]
    solve = false
[]

[Variables]
    [u]
    []
[]

[Kernels]
    [zero_viscosity]
        type = DarcyPressure
        variable = u
        permeability = 0.8451e-09
        viscosity = 0 # The viscosity must be non-zero, so this should invoke an error
    []
[]

[Executioner]
    type = Steady
[]
