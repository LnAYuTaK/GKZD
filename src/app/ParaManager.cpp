#include "ParaManager.h"

const static std::string netConfigFileStr{"netConfig.json"};
const static std::string sysConfigFileStr{"sysConfFact.json"};
const static std::string gasThresholdFileStr{"gasThreshold.json"};
const static std::string fanPumpStatusFileStr{"fanPumpStatus.json"};
const static std::string fanTimingFileStr{"fantiming.json"};

ParaManager::ParaManager(/* args */)
    : netConfFact(netConfigFileStr),
      sysConfFact(sysConfigFileStr),
      thresoldConfsFact(gasThresholdFileStr),
      fanpumpstatusConfFact(fanPumpStatusFileStr),
      fantimingConfFact(fanTimingFileStr) {}
/***********************************************************************************************/
ParaManager::~ParaManager() {}
/***********************************************************************************************/