import pulp

# demoLp = pulp.LpProblem("最长观光时间", sense = pulp.LpMaximize)

# t1 = pulp.LpVariable("游客服务中心", lowBound = 10, upBound = 30, cat = "Continuous")
# t2 = pulp.LpVariable("阳光草坪", lowBound = 20, upBound = 60, cat = "Continuous")
# t3 = pulp.LpVariable("森林小剧场", lowBound = 30, upBound = 30, cat = "Continuous")
# t4 = pulp.LpVariable("儿童科普体验区", lowBound = 30, upBound = 60, cat = "Continuous")
# t5 = pulp.LpVariable("儿童戏水场", lowBound = 20, upBound = 60, cat = "Continuous")
# t6 = pulp.LpVariable("湿地博物馆", lowBound = 30, upBound = 60, cat = "Continuous")
# t7 = pulp.LpVariable("湿地商业街", lowBound = 30, cat = "Continuous")

# demoLp += (t1 + t2 + t3 + t4 + t5 + t6 + t7)

# demoLp += (t1 == 0)
# demoLp += ()

demoLP = pulp.LpProblem("Max Profit", sense = pulp.LpMaximize)

x1 = pulp.LpVariable("for A1", lowBound = 0, cat = "Continuous")
x2 = pulp.LpVariable("for A2", lowBound = 0, cat = "Continuous")

demoLP += (72 * x1 + 64 * x2)

demoLP += (x1 + x2 <= 50)
demoLP += (3 * x1 <= 100)
demoLP += (12 * x1 + 8 * x2 <= 480)

demoLP.solve()

for i in demoLP.variables():
    print(i.name, "=", i.varVaule)
print(pulp.value(demoLp.objective))