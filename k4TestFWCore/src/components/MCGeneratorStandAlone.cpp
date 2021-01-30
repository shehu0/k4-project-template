#include "MCGeneratorStandAlone.h"
#include "GaudiKernel/MsgStream.h"

DECLARE_COMPONENT(MCGeneratorStandAlone)

MCGeneratorStandAlone::MCGeneratorStandAlone(const std::string& aName, ISvcLocator* aSvcLoc) : GaudiAlgorithm(aName, aSvcLoc) {
  declareProperty("PerEventPrintMessage", theMessage, "The message to printed for each Event");
}

MCGeneratorStandAlone::~MCGeneratorStandAlone() {}

StatusCode MCGeneratorStandAlone::initialize() {
  if (GaudiAlgorithm::initialize().isFailure()) {
    return StatusCode::FAILURE;
  }
  return StatusCode::SUCCESS;
}

StatusCode MCGeneratorStandAlone::execute() {

  info() << "Able to system call? ..." << endmsg;

  if(system(NULL)) info() << "Ok." << endmsg;
  else{ 
    info() << "Failure." << endmsg;
    return StatusCode::FAILURE;
  }

  info() << "\t" + theMCgenerator + ": ..." << endmsg;
  int er = system("source /cvmfs/fcc.cern.ch/sw/views/releases/fccsw/0.15/LCG_97a_FCC_4/x86_64-centos7-gcc8-opt/setup.sh; Herwig --help"); 
  if(er) info() << "Failure." << endmsg;

  return StatusCode::SUCCESS;
}

StatusCode MCGeneratorStandAlone::finalize() {
  return GaudiAlgorithm::finalize(); 
}
