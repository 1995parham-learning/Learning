using JuMP
using GLPK
using GLPKMathProgInterface

m = Model(solver=GLPKSolverMIP())

@variable(m, x[1:2] >= 0, Int)
@constraint(m, x[1] + x[2] <= 4.5)
@constraint(m, -x[1] + x[2] >= -2.5)
@constraint(m, x[2] <= 3)
@objective(m, Max, 3x[1] + x[2])

print(m)

status = @time solve(m)

println("Objective value: ", getobjectivevalue(m))
println("x = ", getvalue(x))
