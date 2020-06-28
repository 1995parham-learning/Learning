"""
If we create more than 100 unit of an specific product then market will
raise its price and people will buy it at a higher price.
Write a maximization problem if we can only make 1000 units.
"""

# pylint: disable=import-error,no-name-in-module
from gurobipy import Model, GRB

U = 1000

m = Model("sell-in-market")

x_1 = m.addVar(vtype=GRB.INTEGER, name="sell_with_base_price")
x_2 = m.addVar(vtype=GRB.INTEGER, name="sell_with_high_price")
phi = m.addVar(vtype=GRB.BINARY, name="phi")

m.addConstr(x_1 >= 100 * phi)
m.addConstr(x_2 <= U * phi)
m.addConstr(x_2 + x_1 <= U)

m.setObjective(10 * x_1 + 100 * x_2, GRB.MAXIMIZE)

m.optimize()

for v in m.getVars():
    print(v.varName, v.x)
print(m.objVal)
