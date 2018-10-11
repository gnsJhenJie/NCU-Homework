import os
from random import shuffle
import numpy as np


class FileManager():
    def __init__(self):
        pass

    def initialize(self):
        # initialize variable
        self.setosa = []
        self.versicolor = []
        self.virginica = []
        self.train = []
        self.test = []

    def get_file(self, filename):
        # read file and arrange data
        if filename == '':
            filename = "iris.data.txt"
        self.exist = os.path.isfile(filename)
        if self.exist:
            self.filename = filename
            self.file = open(self.filename, 'r').read()
            self.initialize()
            self.classfy_file()
        else:
            print("the file '" + filename + "' doesn't exist.")

    def classfy_file(self):
        # devide to three part of flower
        lines = self.file.split('\n')
        shuffle(lines)
        for line in lines:
            if len(line) > 1:
                w, x, y, z, result = line.split(',')
                if result == "Iris-setosa":
                    self.setosa.append(
                        [float(w), float(x), float(y), float(z), result])
                elif result == "Iris-versicolor":
                    self.versicolor.append(
                        [float(w), float(x), float(y), float(z), result])
                elif result == "Iris-virginica":
                    self.virginica.append(
                        [float(w), float(x), float(y), float(z), result])
        self.flower_devide()

    def flower_devide(self):
        # devide data to train ande test
        self.devide_train_test(self.setosa)
        self.devide_train_test(self.versicolor)
        self.devide_train_test(self.virginica)

    def devide_train_test(self, kind):
        # 50% train & 50% test
        for i in range(len(kind)):
            if i < (len(kind)/2):
                self.train.append(kind[i])
            else:
                self.test.append(kind[i])


class KNNCalculator():
    def __init__(self):
        pass

    def work(self, train, test):
        # initialize variable
        self.test_correct = 0
        self.test_wrong = 0
        self.train_correct = 0
        self.train_wrong = 0
        self.train = train
        self.test = test
        # user input k value of KNN
        self.k = int(input("Please the k value in KNN : "))
        self.calculate()

    def calculate(self):
        # calculate test error rate
        self.knn_calculate(self.test, "test")

        # calculate train error rate
        self.knn_calculate(self.train, "train")

    def knn_calculate(self, data, kind):
        correct, wrong = 0, 0

        # each test data point will be calculate with all train data to find k closed train point
        for i in range(len(data)):
            k_point = []
            for n in range(self.k):
                k_point.append([999999.999999, "None"])
            flower = [[0, "Iris-setosa"],
                      [0, "Iris-versicolor"], [0, "Iris-virginica"]]
            for j in range(len(self.train)):
                p1 = self.train[j][0:4]
                p2 = data[i][0:4]
                distance = self.distance_calculate(p1, p2)
                if distance < k_point[0][0]:
                    k_point[0] = [distance, self.train[j][4]]
                    k_point.sort(reverse=True)

            # count flower kind number
            for n in range(self.k):
                if k_point[n][1] == "Iris-setosa":
                    flower[0][0] += 1
                if k_point[n][1] == "Iris-versicolor":
                    flower[1][0] += 1
                if k_point[n][1] == "Iris-virginica":
                    flower[2][0] += 1

            # sort to get the biggest number of flower kind in [0]
            flower.sort(reverse=True)
            knn_result = flower[0][1]
            origin_result = data[i][4]

            #correct or wrong
            if knn_result == origin_result:
                print("test point_" + str(i+1) + "'s KNN result is " +
                      knn_result + ". (Exactly is " + origin_result + ".)")
                correct += 1
            else:
                print("\033[1;31;40mtest point_" + str(i+1) + "'s KNN result is " +
                      knn_result + ". (Exactly is " + origin_result + ".)\033[0m")
                wrong += 1
        sum = correct + wrong

        # calculate error rate
        if kind == "test":
            self.test_correct = round((correct * 100) / sum, 4)
            self.test_wrong = round((wrong * 100) / sum, 4)
        else:
            self.train_correct = round((correct * 100) / sum, 4)
            self.train_wrong = round((wrong * 100) / sum, 4)

    def distance_calculate(self, p1, p2):
        # calculate the distance between two vectors
        vector1 = np.array(p1)
        vector2 = np.array(p2)
        return np.linalg.norm(vector1-vector2)


# initialize essential object
fileManager = FileManager()
knn_calculator = KNNCalculator()

while True:
    # user input data file for KNN
    filename = input(
        "Please input the file name to start KNN. Or input 'end' to close. (Default is iris.data.txt)\n : ")
    if filename == "end":
        break
    else:
        fileManager.get_file(filename)
        if fileManager.exist:
            knn_calculator.work(fileManager.train, fileManager.test)

            # show the knn result
            print(
                "---------------------------KNN result---------------------------")
            print(
                "\t\ttrain_correct(%)\ttrain_wrong(%)\t\ttest_correct(%)\t\ttest_wrong(%)")
            print("test data\t" + str(knn_calculator.train_correct) + "\t\t\t" + str(knn_calculator.train_wrong) +
                  "\t\t\t" + str(knn_calculator.test_correct) + "\t\t\t" + str(knn_calculator.test_wrong))
            print(
                "----------------------------------------------------------------")
