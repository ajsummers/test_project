
[Mesh]
    type = GeneratedMesh
    dim = 2
    nx = 100
    ny = 10
    xmax = 0.304 # Length of test chamber
    ymax = 0.0257 # Test chamber radius
[]

[Variables]
    [temperature]
    []
[]

[Kernels]
    [heat_conduction]
        type = ADHeatConduction
        variable = temperature
    []
[]

[BCs]
    [inlet_temperature]
        type = DirichletBC
        variable = temperature
        boundary = left
        value = 350 # K
    []
    [outlet_temperature]
        type = DirichletBC
        variable = temperature
        boundary = right
        value = 300 # K
    []
[]

[Materials]
    [steel]
        type = ADGenericConstantMaterial
        prop_names = thermal_conductivity
        prop_values = 18 # (W/m*K)
    []
[]

[Problem]
    type = FEProblem
    coord_type = RZ
    rz_coord_axis = x
[]

[Executioner]
    type = Steady
    solve_type = NEWTON
    petsc_options_iname = '-pc_type -pc_hypre_type'
    petsc_options_value = 'hypre boomeramg'
[]

[Outputs]
    exodus = true
[]
