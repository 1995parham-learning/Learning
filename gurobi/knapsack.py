from gurobipy import Model, GRB

m = Model("knapsack")

b1 = m.addVar(vtype=GRB.BINARY)
b2 = m.addVar(vtype=GRB.BINARY)
b3 = m.addVar(vtype=GRB.BINARY)
b4 = m.addVar(vtype=GRB.BINARY)

m.addConstr(10 * b1 + 5 * b2 + 10 * b3 + 11 * b4 <= 23)
m.setObjective(b1 + b2 + b3 + b4, GRB.MAXIMIZE)
m.update()

print(m)
print(m.presolve())

m.optimize()
