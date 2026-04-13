#pragma once
#include "Classifier.h"
#include <iostream>

/**
 * @file StubClassifiers.h
 * @brief KNNClassifier and AnotherClassifier stubs (not implemented).
 * @author [Your Name] & [Teammate Name]
 */

/**
 * @class KNNClassifier
 * @brief Placeholder — all methods just print their function name.
 */
class KNNClassifier : public Classifier {
public:
    void train(const std::vector<DataPoint>& trainingData) override {
        // TODO: Print function name
    }

    int predict(const DataPoint& point) override {
        // TODO: Print function name
        return -1;
    }

    double evaluate(const std::vector<DataPoint>& testData) override {
        // TODO: Print function name
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
        // TODO: Print function name
    }

    int predict(const DataPoint& point) override {
        // TODO: Print function name
        return -1;
    }

    double evaluate(const std::vector<DataPoint>& testData) override {
        // TODO: Print function name
        return 0.0;
    }

    std::string getName() const override { return "AnotherClassifier"; }
};
