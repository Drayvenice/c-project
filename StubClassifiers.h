#pragma once
#include "Classifier.h"
#include <iostream>

/**
 * @file StubClassifiers.h
 * @brief KNNClassifier and AnotherClassifier stubs (not implemented).
 * @author Kristen & Drayven
 */

 /**
  * @class KNNClassifier
  * @brief Placeholder — all methods just print their function name.
  */
class KNNClassifier : public Classifier {
public:
    void train(const std::vector<DataPoint>& trainingData) override {
        std::cout << "KNNClassifier::train() - Not implemented yet." << std::endl;
    }

    int predict(const DataPoint& point) override {
        std::cout << "KNNClassifier::predict() - Not implemented yet." << std::endl;
        return -1;
    }

    double evaluate(const std::vector<DataPoint>& testData) override {
        std::cout << "KNNClassifier::evaluate() - Not implemented yet." << std::endl;
        return 0.0;
    }

    std::string getName() const override { return "KNNClassifier"; }
};

/**
 * @class AnotherClassifier
 * @brief Placeholder — all methods just print their function name.
 */
class AnotherClassifier : public Classifier {
public:
    void train(const std::vector<DataPoint>& trainingData) override {
        std::cout << "AnotherClassifier::train() - Not implemented yet." << std::endl;
    }

    int predict(const DataPoint& point) override {
        std::cout << "AnotherClassifier::predict() - Not implemented yet." << std::endl;
        return -1;
    }

    double evaluate(const std::vector<DataPoint>& testData) override {
        std::cout << "AnotherClassifier::evaluate() - Not implemented yet." << std::endl;
        return 0.0;
    }

    std::string getName() const override { return "AnotherClassifier"; }
};
