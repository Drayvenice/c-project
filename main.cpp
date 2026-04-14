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
    printBanner();

    // TODO: classifier selection menu
    // TODO: run selected classifier
    return 0;
}

void printBanner() {
    std::cout << "============================================\n";
    std::cout << "   Phone Orientation Classifier\n";
    std::cout << "   PROG71020 - OOP Winter 2026\n";
    std::cout << "============================================\n";
    std::cout << "\nLabel  Orientation\n";
    std::cout << "-----  --------------------\n";
    std::cout << "  1    Face up\n";
    std::cout << "  2    Face down\n";
    std::cout << "  3    Portrait\n";
    std::cout << "  4    Portrait upside down\n";
    std::cout << "  5    Landscape left\n";
    std::cout << "  6    Landscape right\n";
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
