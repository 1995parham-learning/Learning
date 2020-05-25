from gurobipy import Model, GRB

m = Model("brewery")

A = m.addVar(vtype=GRB.INTEGER, name="Ale")
B = m.addVar(vtype=GRB.INTEGER, name="Beer")
m.update()

c1 = m.addConstr(4 * A + 4 * B <= 160)
c2 = m.addConstr(35 * A + 20 * B <= 1190)
c3 = m.addConstr(5 * A + 15 * B <= 480)

m.setObjective(13 * A + 23 * B, GRB.MAXIMIZE)

m.optimize()

for v in m.getVars():
    print(v.varName, v.x)
print(m.objVal)
