# In The Name of God
# =======================================
# [] File Name : benders.py
#
# [] Creation Date : 01-07-2020
#
# [] Created By : Parham Alvani <parham.alvani@gmail.com>
# =======================================

from gurobipy import GRB, Model
import math

BIG_M = 100 * 100 * 100


class MainProblem:
    def __init__(self):
        self.model = Model("main_problem")

        self.x_1 = self.model.addVar(lb=0, name="x_1", vtype=GRB.BINARY)
        self.x_2 = self.model.addVar(lb=0, name="x_2", vtype=GRB.BINARY)
        self.y_1 = self.model.addVar(lb=0, name="y_1")
        self.y_2 = self.model.addVar(lb=0, name="y_2")

        self.model.addConstr(self.x_1 + self.x_2 <= 1)
        self.model.addConstr(
            self.y_1 + 2 * self.y_2 - self.x_1 - 2 * self.x_2 <= 0
        )
        self.model.addConstr(
            2 * self.y_1 + 3 * self.y_2 - 3 * self.x_1 - 2 * self.x_2 <= 0
        )

        self.model.setObjective(
            3 * self.x_1 + 5 * self.x_2 - 10 * self.y_1 - 18 * self.y_2,
            GRB.MINIMIZE,
        )

    def solve(self):
        self.model.optimize()

        return self.model.objVal


class SubProblem:
    def __init__(self):
        self.model = Model("benders_sub_problem")

        self.x_1 = self.model.addVar(lb=0, name="x_1")
        self.x_2 = self.model.addVar(lb=0, name="x_2")
        self.y_1 = self.model.addVar(lb=0, name="y_1")
        self.y_2 = self.model.addVar(lb=0, name="y_2")

        self.model.addConstr(
            self.y_1 + 2 * self.y_2 - self.x_1 - 2 * self.x_2 <= 0
        )

        self.model.addConstr(
            2 * self.y_1 + 3 * self.y_2 - 3 * self.x_1 - 2 * self.x_2 <= 0
        )

        self.x_hat_1 = None
        self.x_hat_2 = None

        self.model.setObjective(
            -10 * self.y_1 - 18 * self.y_2, GRB.MINIMIZE,
        )

    def solve(self, x_1, x_2):
        if self.x_hat_1 is not None:
            self.model.remove(self.x_hat_1)

        if self.x_hat_2 is not None:
            self.model.remove(self.x_hat_2)

        self.x_hat_1 = self.model.addConstr(self.x_1 == x_1)
        self.x_hat_2 = self.model.addConstr(self.x_2 == x_2)

        self.model.optimize()

        print(f"Y_1: {self.y_1.x}")
        print(f"Y_2: {self.y_2.x}")

        return self.model.objVal


class MasterProblem:
    def __init__(self):
        self.model = Model("benders_master_problem")

        self.x_1 = self.model.addVar(lb=0, name="x_1", vtype=GRB.BINARY)
        self.x_2 = self.model.addVar(lb=0, name="x_2", vtype=GRB.BINARY)

        self.phi = self.model.addVar(lb=-100, name="phi")

        self.model.addConstr(self.x_1 + self.x_2 <= 1)

        self.model.setObjective(
            3 * self.x_1 + 5 * self.x_2 + self.phi, GRB.MINIMIZE,
        )

    def add_cut(self, lhs, x_hat_1, x_hat_2):
        if x_hat_1 == 1 and x_hat_2 == 0:
            self.model.addConstr(
                lhs + BIG_M * (self.x_1 - 1) - BIG_M * (self.x_2) <= self.phi,
                name="cut",
            )
        if x_hat_1 == 0 and x_hat_2 == 1:
            self.model.addConstr(
                lhs - BIG_M * (self.x_1) + BIG_M * (self.x_2 - 1) <= self.phi,
                name="cut",
            )
        if x_hat_1 == 0 and x_hat_2 == 0:
            self.model.addConstr(
                lhs - BIG_M * (self.x_1) - BIG_M * (self.x_2) <= self.phi,
                name="cut",
            )
        if x_hat_1 == 1 and x_hat_2 == 1:
            self.model.addConstr(
                lhs + BIG_M * (self.x_1 - 1) + BIG_M * (self.x_2 - 1)
                <= self.phi,
                name="cut",
            )

    def solve(self):
        self.model.optimize()
        print()
        print(f"PHI: {self.phi.x}")
        print(f"X_1: {self.x_1.x}")
        print(f"X_2: {self.x_2.x}")
        print()

        return (
            self.model.objVal,
            self.x_1.x,
            self.x_2.x,
        )


if __name__ == "__main__":
    main_problem = MainProblem()
    print(main_problem.solve())
    input()

    master_problem = MasterProblem()
    sub_problem = SubProblem()

    EPSILON = 0.001
    k = 0

    while True:
        k += 1

        z_lb, x_1, x_2 = master_problem.solve()

        z_star = sub_problem.solve(x_1, x_2)
        z_ub = z_star + 3 * x_1 + 5 * x_2

        print(z_lb, z_ub)
        if math.isclose(z_lb, z_ub, abs_tol=EPSILON):
            break

        master_problem.add_cut(z_star, x_1, x_2)
