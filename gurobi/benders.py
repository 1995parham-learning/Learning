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

        self.x_1 = self.model.addVar(lb=0, name="x_1")
        self.x_2 = self.model.addVar(lb=0, name="x_2")
        self.x_3 = self.model.addVar(lb=0, name="x_3")
        self.x_4 = self.model.addVar(lb=0, name="x_4")
        self.x_5 = self.model.addVar(lb=0, name="x_5")

        self.model.addConstr(self.x_1 + self.x_4 + self.x_5 <= 3)
        self.model.addConstr(2 * self.x_2 + 3 * self.x_4 <= 12)
        self.model.addConstr(self.x_3 - 7 * self.x_5 <= -16)
        self.model.addConstr(-self.x_4 + self.x_5 <= 2)

        self.x_hat_4 = None
        self.x_hat_5 = None

        self.model.setObjective(
            -2 * self.x_1 - self.x_2 + self.x_3 + 3 * self.x_4 - 3 * self.x_5,
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
        self.x_3 = self.model.addVar(lb=0, name="x_3")
        self.x_4 = self.model.addVar(lb=0, name="x_4")
        self.x_5 = self.model.addVar(lb=0, name="x_5")

        v_1 = self.model.addVar(lb=0, name="v_1")
        self.model.addConstr(self.x_1 + self.x_4 + self.x_5 - v_1 <= 3)

        v_2 = self.model.addVar(lb=0, name="v_2")
        self.model.addConstr(2 * self.x_2 + 3 * self.x_4 - v_2 <= 12)

        v_3 = self.model.addVar(lb=0, name="v_3")
        self.model.addConstr(self.x_3 - 7 * self.x_5 - v_3 <= -16)

        self.x_hat_4 = None
        self.x_hat_5 = None

        self.model.setObjective(
            -2 * self.x_1
            - self.x_2
            + self.x_3
            + BIG_M * v_1
            + BIG_M * v_2
            + BIG_M * v_3,
            GRB.MINIMIZE,
        )

    def solve(self, x_4, x_5):
        if self.x_hat_4 is not None:
            self.model.remove(self.x_hat_4)

        if self.x_hat_5 is not None:
            self.model.remove(self.x_hat_5)

        self.x_hat_4 = self.model.addConstr(self.x_4 == x_4)
        self.x_hat_5 = self.model.addConstr(self.x_5 == x_5)

        self.model.optimize()

        return (
            self.model.objVal,
            self.x_hat_4.pi,
            self.x_hat_5.pi,
        )


class MasterProblem:
    def __init__(self):
        self.model = Model("benders_master_problem")

        self.x_4 = self.model.addVar(lb=0, name="x_4")
        self.x_5 = self.model.addVar(lb=0, name="x_5")

        self.phi = self.model.addVar(lb=-100 * 100 * 100, name="phi")

        self.model.addConstr(-self.x_4 + self.x_5 <= 2)

        self.model.setObjective(
            3 * self.x_4 - 3 * self.x_5 + self.phi, GRB.MINIMIZE,
        )

    def add_cut(self, lhs, pi_1, pi_2):
        self.model.addConstr(
            lhs <= self.phi - self.x_4 * pi_1 - self.x_5 * pi_2, name="cut"
        )

    def solve(self):
        self.model.optimize()

        return (
            self.model.objVal,
            self.x_4.x,
            self.x_5.x,
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

        z_lb, x_4, x_5 = master_problem.solve()

        z_star, pi_1, pi_2 = sub_problem.solve(x_4, x_5)
        z_ub = z_star + 3 * x_4 - 3 * x_5

        print(z_lb, z_ub)
        if math.isclose(z_lb, z_ub, abs_tol=EPSILON):
            break

        master_problem.add_cut(z_star - pi_1 * x_4 - pi_2 * x_5, pi_1, pi_2)
