#include <iostream>
#include <string>
#include <limits>
#include "DataPoint.h"
#include "DataLoader.h"
#include "Classifier.h"
#include "NNClassifier.h"
#include "StubClassifiers.h"

/**
 * @file main.cpp
 * @brief Entry point - handles user interaction and classifier selection.
 * @author Kristen & Drayven
 * @course PROG71020 - OOP Winter 2026
 */

 // ─── Constants ───────────────────────────────────────────────────────────────
const std::string TRAINING_FILE = "trainingData.txt";
const std::string TESTING_FILE = "testingData.txt";

// ─── Forward declarations ─────────────────────────────────────────────────────
void printBanner();
void runNNMode(Classifier* clf);
void runManualInput(Classifier* clf);
void runFileMode(Classifier* clf);
void runTestAccuracy(Classifier* clf);
void clearInput();

// ─────────────────────────────────────────────────────────────────────────────

/**
 * @brief Application entry point.
 */
int main() {
    // TODO: print banner
    // TODO: load training data
    // TODO: classifier selection menu
    // TODO: run selected classifier
    return 0;
}

void printBanner() {
    // TODO: implement
}

void runNNMode(Classifier* clf) {
    // TODO: implement
}

void runManualInput(Classifier* clf) {
    // TODO: implement
}

void runFileMode(Classifier* clf) {
    // TODO: implement
}

void runTestAccuracy(Classifier* clf) {
    // TODO: implement
}

void clearInput() {
    // TODO: implement
}
