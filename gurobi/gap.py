from gurobipy import Model, GRB, quicksum

import dataclasses
import typing
import math
import pprint


@dataclasses.dataclass(eq=True, frozen=True, repr=True)
class Machine:
    name: str
    capacity: int


@dataclasses.dataclass(eq=True, frozen=True, repr=True)
class Task:
    name: str
    size: int


machines: typing.List[Machine] = [Machine("m1", 10), Machine("m2", 20)]
tasks: typing.List[Task] = [Task("t1", 1), Task("t2", 2), Task("t3", 15)]


costs: typing.Dict[typing.Tuple[Machine, Task], int] = {
    (machine, task): math.ceil(task.size / machine.capacity * 100)
    for machine in machines
    for task in tasks
}

pprint.pprint(costs)

m = Model("Generalized Assignment Problem")


_lambda = m.addVars(machines, tasks, name="lambda", vtype=GRB.BINARY)

m.addConstrs(
    (_lambda.sum("*", task) == 1 for task in tasks), name="task execution"
)

m.addConstrs(
    (
        quicksum(_lambda[machine, task] * task.size for task in tasks)
        <= machine.capacity
        for machine in machines
    )
)

m.setObjective(
    quicksum(
        _lambda[machine, task] * costs[machine, task]
        for task in tasks
        for machine in machines
    ),
    GRB.MINIMIZE,
)

m.optimize()

for machine in machines:
    for task in tasks:
        print(f"{task} @ {machine}: {_lambda[machine, task].x}")
