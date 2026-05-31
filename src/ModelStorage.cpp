#include "ModelStorage.h"
#include "DataHandler.h"

void ModelStorage::saveLayer(const std::string& prefix, const DenseLayer& layer) {
    DataHandler::saveCSV(prefix + "_w.csv", layer.getWeights());
    DataHandler::saveCSV(prefix + "_b.csv", layer.getBias());
}

void ModelStorage::loadLayer(const std::string& prefix, DenseLayer& layer) {
    Matrix w = DataHandler::loadCSV(prefix + "_w.csv");
    Matrix b = DataHandler::loadCSV(prefix + "_b.csv");
    layer.setWeights(w);
    layer.setBias(b);
}
