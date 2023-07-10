#pragma once 

#include <iostream>
#include <string>
#include <fstream>
#include <ostream>

#include "sysconfig.pb.h"
#include "netconfig.pb.h"
#include "thresoldconfig.pb.h"
#include "fanpumpstatusconfig.pb.h"
#include "fantimingconfig.pb.h"
#include "SimpleSigleton.h"
#include "FileHelper.h"

class ParaManager
{
    DISALLOW_COPY_AND_ASSIGN(ParaManager)
public:
    
    bool loadSysConf();
    bool SaveSysConf(SysConfig & sysconf);

    bool loadNetConf();
    bool SaveNetConf(NetConfig & netconf);

    bool loadThresoldPara();
    bool SaveThresoldPara(GasThresholdList& thresoldconfs);

    bool loadFanPumpStatusConf();
    bool SaveFanPumpStatusConf(FanPumpStatusConfig & fanpumpstatusconf);

    bool loadNFanTimingConf();
    bool SaveFanTimingConf(FanTimingConfig & fantimingconf);

    ParaManager(/* args */);
    ~ParaManager();

    SysConfig sysConf;
    NetConfig netConf;
    GasThresholdList thresoldConfs;
    FanPumpStatusConfig fanpumpstatusConf;
    FanTimingConfig   fantimingConf;
private:
};

