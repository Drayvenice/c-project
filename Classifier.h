#pragma once
#include <vector>
#include <string>
#include "DataPoint.h"

/**
 * @file Classifier.h
 * @brief Abstract base class for all classifiers.
 * @author Kristen & Drayven
 */

/**
 * @class Classifier
 * @brief Defines the interface all classifiers must implement.
 */
class Classifier {
public:
    virtual ~Classifier() {}

    /// @brief Train the classifier using labeled data.
    virtual void train(const std::vector<DataPoint>& trainingData) = 0;

    /// @brief Predict the label for a single point.
    virtual int predict(const DataPoint& point) = 0;

    /// @brief Evaluate accuracy on labeled test data.
    virtual double evaluate(const std::vector<DataPoint>& testData) = 0;

    /// @brief Return the name of this classifier.
    virtual std::string getName() const = 0;

    /// @brief Classify all points in a vector (uses predict internally).
    virtual void classifyAll(std::vector<DataPoint>& points) {
        for (auto& p : points) {
            p.label = predict(p);
        }
    }
};
