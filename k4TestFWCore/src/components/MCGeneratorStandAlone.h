#ifndef TESTFWCORE_MCGENERATORSTANDALONE
#define TESTFWCORE_MCGENERATORSTANDALONE

#pragma once 

// GAUDI
#include "GaudiAlg/GaudiAlgorithm.h"
#include "Gaudi/Property.h"


class MCGeneratorStandAlone : public GaudiAlgorithm {
public:
  explicit MCGeneratorStandAlone(const std::string&, ISvcLocator*);
  virtual ~MCGeneratorStandAlone();
  /**  Initialize.
   *   @return status code
   */
  virtual StatusCode initialize() final;
  /**  Execute.
   *   @return status code
   */
  virtual StatusCode execute() final;
  /**  Finalize.
   *   @return status code
   */
  virtual StatusCode finalize() final;

private:
  // member variable 
  Gaudi::Property<std::string> theMessage{this, "PerEventPrintMessage", "Hello ", "The message to printed for each Event"};
  Gaudi::Property<std::string> theMCgenerator{this, "MCGeneratorName", "Herwig", "The name of the stand-alone Monte Carlo generator"};
};

#endif /* TESTFWCORE_MCGENERATORSTANDALONE */
