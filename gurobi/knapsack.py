from gurobipy import Model, GRB, quicksum

import typing
import dataclasses


@dataclasses.dataclass
class Item:
    weight: int
    profit: int


items: typing.List[Item] = [Item(1, 10), Item(1, 1)]

capacity = 10


m = Model("knapsack")

b = m.addVars(len(items), name="item", vtype=GRB.BINARY)
m.update()


m.addConstr(
    quicksum(item.weight * b[i] for (i, item) in enumerate(items)) <= capacity,
    name="capacity",
)
m.setObjective(
    quicksum(b[i] * item.profit for (i, item) in enumerate(items)),
    GRB.MAXIMIZE,
)
m.update()

print(m)
print(m.presolve())

m.optimize()
