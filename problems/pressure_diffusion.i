
[Mesh]
    type = GeneratedMesh
    dim = 2
    nx = 100 # number of elements in x direction
    ny = 10 # number of elements in y direction
    xmax = 0.304 # Length of test chamber
    ymax = 0.0257 # Test chamber radius
[]

[Problem]
    type = FEProblem # "Normal" type of Finite Element Problem in MOOSE
    coord_type = RZ # Axisymmetric RZ
    rz_coord_axis = X # Which axis the symmetry is around
[]

[Variables]
    [pressure]
        # Adds a linear Lagrange variable by default
    []
[]

[Kernels]
    [diffusion]
        type = DarcyPressure # Zero-gravity, divergence-free form of Darcy's law
        variable = pressure # Operate on the "pressure" variable from above
        permeability = 0.8451e-09 # (m^2) assumed permeability of the porous medium
    []
[]

[BCs]
    [inlet]
        type = ADDirichletBC # Simple u=value BC
        variable = pressure # Variable to be set
        boundary = left # Name of a sideset in the mesh
        value = 4000 # (Pa)
    []
    [outlet]
        type = ADDirichletBC
        variable = pressure
        boundary = right
        value = 0 # (Pa) 
    []
[]

[Executioner]
    type = Steady # Steady-state problem
    solve_type = NEWTON # Performs a Newton solve

    # Set PETSc parameters to optimize solver efficiency
    petsc_options_iname = '-pc_type -pc_hypre_type' # PETSc option pairs with values below
    petsc_options_value = ' hypre    boomerange'
[]

[Outputs]
    exodus = true # Output Exodus format
[]

