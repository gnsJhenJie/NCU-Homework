from code import MainProgram
import matplotlib.pyplot as plt
import numpy as np

k_value = []
train_error = []
test_error = []

main = MainProgram()
for i in range(20):
    main.one_run('', i+1)
    k_value.append(i+1)
    train_error.append(main.knn_calculator.train_wrong)
    test_error.append(main.knn_calculator.test_wrong)


plt.xlabel("k value")
plt.ylabel("error(%)")
plt.plot(k_value, train_error, label="train error")
plt.plot(k_value, test_error, label="test error")
plt.xticks(np.linspace(1, 20, 20))
plt.legend()
plt.show()
