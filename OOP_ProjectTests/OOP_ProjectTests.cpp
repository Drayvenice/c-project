#include "pch.h"
#include "CppUnitTest.h"
#include "../OOP_Project/DataPoint.h"
#include "../OOP_Project/DataLoader.h"
#include "../OOP_Project/NNClassifier.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace OOP_ProjectTests {

    // =========================================================
    // DataPoint Tests (6 tests)
    // =========================================================
    TEST_CLASS(DataPointTests) {
public:

    TEST_METHOD(ValidPoint_ReturnsTrue) {
        DataPoint p(-0.17738, -0.04536, -0.9831, 1);
        Assert::IsTrue(p.isValid());
    }

    TEST_METHOD(InvalidPoint_ZOutOfRange_ReturnsFalse) {
        DataPoint p(0.0, 0.0, -7.96, 1);
        Assert::IsFalse(p.isValid());
    }

    TEST_METHOD(InvalidPoint_XOutOfRange_ReturnsFalse) {
        DataPoint p(1.5, 0.0, 0.0, 1);
        Assert::IsFalse(p.isValid());
    }

    TEST_METHOD(GetOrientationName_Label1_ReturnsFaceUp) {
        DataPoint p(0, 0, -1, 1);
        Assert::AreEqual(std::string("Face up"), p.getOrientationName());
    }

    TEST_METHOD(GetOrientationName_Label2_ReturnsFaceDown) {
        DataPoint p(0, 0, 1, 2);
        Assert::AreEqual(std::string("Face down"), p.getOrientationName());
    }

    TEST_METHOD(GetOrientationName_UnknownLabel_ReturnsUnknown) {
        DataPoint p(0, 0, 0, 99);
        Assert::AreEqual(std::string("Unknown"), p.getOrientationName());
    }
    };

    // =========================================================
    // DataLoader Tests (4 tests)
    // =========================================================
    TEST_CLASS(DataLoaderTests) {
public:

    TEST_METHOD(LoadLabeledData_ReturnsNonEmptyVector) {
        auto data = DataLoader::loadLabeledData("trainingData.txt");
        Assert::IsTrue(data.size() > 0);
    }

    TEST_METHOD(LoadLabeledData_SkipsInvalidRows) {
        auto data = DataLoader::loadLabeledData("trainingData.txt");
        Assert::AreEqual((size_t)170, data.size());
    }

    TEST_METHOD(LoadUnknownData_ReturnsLabel0) {
        auto data = DataLoader::loadUnknownData("unknownData.txt");
        for (const auto& p : data) {
            Assert::AreEqual(0, p.label);
        }
    }

    TEST_METHOD(LoadUnknownData_ReturnsCorrectCount) {
        auto data = DataLoader::loadUnknownData("unknownData.txt");
        Assert::AreEqual((size_t)23, data.size());
    }
    };

    // =========================================================
    // NNClassifier Tests - all 29 rows of testingData.txt
    // =========================================================
    TEST_CLASS(NNClassifierTests) {
public:

    NNClassifier getTrainedClassifier() {
        NNClassifier clf;
        std::vector<DataPoint> trainingData =
            DataLoader::loadLabeledData("trainingData.txt");
        clf.train(trainingData);
        return clf;
    }

    // --- Label 1: Face up (rows 1-5) ---

    TEST_METHOD(Predict_FaceUp_Row1) {
        NNClassifier clf = getTrainedClassifier();
        DataPoint test(-0.17778, -0.04568, -0.98301, 0);
        Assert::AreEqual(1, clf.predict(test));
    }

    TEST_METHOD(Predict_FaceUp_Row2) {
        NNClassifier clf = getTrainedClassifier();
        DataPoint test(-0.17765, -0.04547, -0.98304, 0);
        Assert::AreEqual(1, clf.predict(test));
    }

    TEST_METHOD(Predict_FaceUp_Row3) {
        NNClassifier clf = getTrainedClassifier();
        DataPoint test(-0.03205, -0.23794, -0.97075, 0);
        Assert::AreEqual(1, clf.predict(test));
    }

    TEST_METHOD(Predict_FaceUp_Row4) {
        NNClassifier clf = getTrainedClassifier();
        DataPoint test(-0.27182, -0.16692, -0.94772, 0);
        Assert::AreEqual(1, clf.predict(test));
    }

    TEST_METHOD(Predict_FaceUp_Row5) {
        NNClassifier clf = getTrainedClassifier();
        DataPoint test(-0.08683, -0.34201, -0.93568, 0);
        Assert::AreEqual(1, clf.predict(test));
    }

    // --- Label 2: Face down (rows 6-10) ---

    TEST_METHOD(Predict_FaceDown_Row6) {
        NNClassifier clf = getTrainedClassifier();
        DataPoint test(0.05951, -0.16744, 0.98408, 0);
        Assert::AreEqual(2, clf.predict(test));
    }

    TEST_METHOD(Predict_FaceDown_Row7) {
        NNClassifier clf = getTrainedClassifier();
        DataPoint test(0.42008, -0.05597, 0.90576, 0);
        Assert::AreEqual(2, clf.predict(test));
    }

    TEST_METHOD(Predict_FaceDown_Row8) {
        NNClassifier clf = getTrainedClassifier();
        DataPoint test(0.3811, -0.03899, 0.92371, 0);
        Assert::AreEqual(2, clf.predict(test));
    }

    TEST_METHOD(Predict_FaceDown_Row9) {
        NNClassifier clf = getTrainedClassifier();
        DataPoint test(-0.15083, -0.33631, 0.92959, 0);
        Assert::AreEqual(2, clf.predict(test));
    }

    TEST_METHOD(Predict_FaceDown_Row10) {
        NNClassifier clf = getTrainedClassifier();
        DataPoint test(0.44038, 0.01346, 0.89771, 0);
        Assert::AreEqual(2, clf.predict(test));
    }

    // --- Label 3: Portrait (rows 11-15) ---

    TEST_METHOD(Predict_Portrait_Row11) {
        NNClassifier clf = getTrainedClassifier();
        DataPoint test(-0.01429, -0.99807, -0.06051, 0);
        Assert::AreEqual(3, clf.predict(test));
    }

    TEST_METHOD(Predict_Portrait_Row12) {
        NNClassifier clf = getTrainedClassifier();
        DataPoint test(0.0048, -0.96534, -0.26095, 0);
        Assert::AreEqual(3, clf.predict(test));
    }

    TEST_METHOD(Predict_Portrait_Row13) {
        NNClassifier clf = getTrainedClassifier();
        DataPoint test(-0.12484, -0.98771, 0.09409, 0);
        Assert::AreEqual(3, clf.predict(test));
    }

    TEST_METHOD(Predict_Portrait_Row14) {
        NNClassifier clf = getTrainedClassifier();
        DataPoint test(0.01774, -0.99978, -0.01092, 0);
        Assert::AreEqual(3, clf.predict(test));
    }

    TEST_METHOD(Predict_Portrait_Row15) {
        NNClassifier clf = getTrainedClassifier();
        DataPoint test(-0.26325, -0.933, -0.24538, 0);
        Assert::AreEqual(3, clf.predict(test));
    }

    // --- Label 4: Portrait upside down (rows 16-19) ---

    TEST_METHOD(Predict_PortraitUpsideDown_Row16) {
        NNClassifier clf = getTrainedClassifier();
        DataPoint test(0.00982, 0.99868, -0.05038, 0);
        Assert::AreEqual(4, clf.predict(test));
    }

    TEST_METHOD(Predict_PortraitUpsideDown_Row17) {
        NNClassifier clf = getTrainedClassifier();
        DataPoint test(-0.07058, 0.99706, -0.02986, 0);
        Assert::AreEqual(4, clf.predict(test));
    }

    TEST_METHOD(Predict_PortraitUpsideDown_Row18) {
        NNClassifier clf = getTrainedClassifier();
        DataPoint test(-0.18741, 0.97813, -0.09022, 0);
        Assert::AreEqual(4, clf.predict(test));
    }

    TEST_METHOD(Predict_PortraitUpsideDown_Row19) {
        NNClassifier clf = getTrainedClassifier();
        DataPoint test(0.04945, 0.96554, -0.25553, 0);
        Assert::AreEqual(4, clf.predict(test));
    }

    // --- Label 6: Landscape right (rows 20-24) ---

    TEST_METHOD(Predict_LandscapeRight_Row20) {
        NNClassifier clf = getTrainedClassifier();
        DataPoint test(0.9978, -0.05244, -0.04047, 0);
        Assert::AreEqual(6, clf.predict(test));
    }

    TEST_METHOD(Predict_LandscapeRight_Row21) {
        NNClassifier clf = getTrainedClassifier();
        DataPoint test(0.99827, -0.04471, -0.03825, 0);
        Assert::AreEqual(6, clf.predict(test));
    }

    TEST_METHOD(Predict_LandscapeRight_Row22) {
        NNClassifier clf = getTrainedClassifier();
        DataPoint test(0.93264, -0.03448, -0.35916, 0);
        Assert::AreEqual(6, clf.predict(test));
    }

    TEST_METHOD(Predict_LandscapeRight_Row23) {
        NNClassifier clf = getTrainedClassifier();
        DataPoint test(0.88866, -0.01717, 0.45824, 0);
        Assert::AreEqual(6, clf.predict(test));
    }

    TEST_METHOD(Predict_LandscapeRight_Row24) {
        NNClassifier clf = getTrainedClassifier();
        DataPoint test(0.88988, -0.45391, 0.04563, 0);
        Assert::AreEqual(6, clf.predict(test));
    }

    // --- Label 5: Landscape left (rows 25-29) ---

    TEST_METHOD(Predict_LandscapeLeft_Row25) {
        NNClassifier clf = getTrainedClassifier();
        DataPoint test(-0.89759, 0.01899, -0.44043, 0);
        Assert::AreEqual(5, clf.predict(test));
    }

    TEST_METHOD(Predict_LandscapeLeft_Row26) {
        NNClassifier clf = getTrainedClassifier();
        DataPoint test(-0.67688, 0.02461, -0.73569, 0);
        Assert::AreEqual(5, clf.predict(test));
    }

    TEST_METHOD(Predict_LandscapeLeft_Row27) {
        NNClassifier clf = getTrainedClassifier();
        DataPoint test(-0.99965, -0.02026, -0.00571, 0);
        Assert::AreEqual(5, clf.predict(test));
    }

    TEST_METHOD(Predict_LandscapeLeft_Row28) {
        NNClassifier clf = getTrainedClassifier();
        DataPoint test(-0.9762, 0.13291, -0.1714, 0);
        Assert::AreEqual(5, clf.predict(test));
    }

    TEST_METHOD(Predict_LandscapeLeft_Row29) {
        NNClassifier clf = getTrainedClassifier();
        DataPoint test(-0.96562, -0.19291, -0.17428, 0);
        Assert::AreEqual(5, clf.predict(test));
    }

    // --- Overall accuracy ---

    TEST_METHOD(Evaluate_AllTestingData_Returns100Percent) {
        NNClassifier clf = getTrainedClassifier();
        std::vector<DataPoint> testData =
            DataLoader::loadLabeledData("testingData.txt");
        double accuracy = clf.evaluate(testData);
        Assert::AreEqual(100.0, accuracy, 0.01);
    }
    };
}
