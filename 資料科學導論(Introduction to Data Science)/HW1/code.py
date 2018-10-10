import os
from random import shuffle
import numpy as np


class FileManager():
    def __init__(self):
        pass

    def initialize(self):
        self.setosa = []
        self.versicolor = []
        self.virginica = []
        self.train = []
        self.test = []

    def get_file(self, filename):
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
        self.devide_train_test(self.setosa)
        self.devide_train_test(self.versicolor)
        self.devide_train_test(self.virginica)

    def devide_train_test(self, kind):
        for i in range(len(kind)):
            if i < (len(kind)/2):
                self.train.append(kind[i])
            else:
                self.test.append(kind[i])


class KNNCalculator():
    def __init__(self):
        pass

    def work(self, train, test):
        self.test_correct = 0
        self.test_wrong = 0
        self.train_correct = 0
        self.train_wrong = 0
        self.train = train
        self.test = test
        self.k = int(input("Please the k value in KNN : "))
        self.calculate()

    def calculate(self):
        self.knn_calculate(self.test, "test")
        self.knn_calculate(self.train, "train")

    def knn_calculate(self, data, kind):
        correct, wrong = 0, 0
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
            for n in range(self.k):
                if k_point[n][1] == "Iris-setosa":
                    flower[0][0] += 1
                if k_point[n][1] == "Iris-versicolor":
                    flower[1][0] += 1
                if k_point[n][1] == "Iris-virginica":
                    flower[2][0] += 1
            flower.sort(reverse=True)
            knn_result = flower[0][1]
            origin_result = data[i][4]
            if knn_result == origin_result:
                print("test point_" + str(i+1) + "'s KNN result is " +
                      knn_result + ". (Exactly is " + origin_result + ".)")
                correct += 1
            else:
                print("\033[1;31;40mtest point_" + str(i+1) + "'s KNN result is " +
                      knn_result + ". (Exactly is " + origin_result + ".)\033[0m")
                wrong += 1
        sum = correct + wrong
        if kind == "test":
            self.test_correct = round((correct * 100) / sum, 4)
            self.test_wrong = round((wrong * 100) / sum, 4)
        else:
            self.train_correct = round((correct * 100) / sum, 4)
            self.train_wrong = round((wrong * 100) / sum, 4)

    def distance_calculate(self, p1, p2):
        vector1 = np.array(p1)
        vector2 = np.array(p2)
        return np.linalg.norm(vector1-vector2)


fileManager = FileManager()
knn_calculator = KNNCalculator()

while True:
    filename = input(
        "Please input the file name to start KNN. Or input 'end' to close. (Default is iris.data.txt)\n : ")
    if filename == "end":
        break
    else:
        fileManager.get_file(filename)
        if fileManager.exist:
            knn_calculator.work(fileManager.train, fileManager.test)
            print(
                "---------------------------KNN result---------------------------")
            print(
                "\t\ttrain_correct(%)\ttrain_wrong(%)\t\ttest_correct(%)\t\ttest_wrong(%)")
            print("test data\t" + str(knn_calculator.train_correct) + "\t\t\t" + str(knn_calculator.train_wrong) +
                  "\t\t\t" + str(knn_calculator.test_correct) + "\t\t\t" + str(knn_calculator.test_wrong))
            print(
                "----------------------------------------------------------------")
