import os
from random import shuffle
import numpy as np


class FileManager():
    def __init__(self):
        pass

    def get_file(self, filename):
        if filename == '':
            filename = "iris.data.txt"
        self.exist = os.path.isfile(filename)
        if self.exist:
            self.filename = filename
            self.file = open(self.filename, 'r').read()
            self.setosa = []
            self.versicolor = []
            self.virginica = []
            self.train = []
            self.test = []
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
        self.devide_train_test()

    def devide_train_test(self):
        for i in range(len(self.setosa)):
            if i <= (len(self.setosa)/2):
                self.train.append(self.setosa[i])
            else:
                self.test.append(self.setosa[i])
        for i in range(len(self.versicolor)):
            if i <= (len(self.versicolor)/2):
                self.train.append(self.versicolor[i])
            else:
                self.test.append(self.versicolor[i])
        for i in range(len(self.virginica)):
            if i <= (len(self.virginica)/2):
                self.train.append(self.virginica[i])
            else:
                self.test.append(self.virginica[i])


class KNNCalculator():
    def __init__(self):
        pass

    def initialize(self, train, test):
        self.correct = 0
        self.wrong = 0
        self.train = train
        self.test = test
        self.k = int(input("Please the k value in KNN : "))
        self.knn_calculate()

    def knn_calculate(self):
        for i in range(len(self.test)):
            k_point = []
            for n in range(self.k):
                k_point.append([999999.999999, "None"])
            flower = [[0, "Iris-setosa"],
                      [0, "Iris-versicolor"], [0, "Iris-virginica"]]
            for j in range(len(self.train)):
                p1 = self.train[j][0:4]
                p2 = self.test[i][0:4]
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
            origin_result = self.test[i][4]
            if knn_result == origin_result:
                print("test point_" + str(i+1) + "'s KNN result is " +
                      knn_result + ". (Exactly is " + origin_result + ".)")
                self.correct += 1
            else:
                print("\033[1;31;40mtest point_" + str(i+1) + "'s KNN result is " +
                      knn_result + ". (Exactly is " + origin_result + ".)\033[0m")
                self.wrong += 1
            sum = self.correct + self.wrong
            self.correct = round((self.correct * 100) / sum, 5)
            self.wrong = round((self.wrong * 100) / sum, 5)

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
            knn_calculator.initialize(fileManager.train, fileManager.test)
            print(
                "---------------------------KNN result---------------------------")
            print("\t\tcorrect(%)\twrong(%)")
            print("test data\t" + str(knn_calculator.correct) +
                  "\t\t" + str(knn_calculator.wrong))
            print(
                "----------------------------------------------------------------")
