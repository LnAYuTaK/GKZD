#include "ParaManager.h"
#include "CLOG.h"
#include "Utils.h"
#include "FileHelper.h"
#include <mutex>

ParaManager::ParaManager(/* args */)
{

}
/***********************************************************************************************/
ParaManager::~ParaManager()
{

}
/***********************************************************************************************/
bool ParaManager::SaveSysConf(SysConfig & sysconf)
{
    std::mutex mutex;
    std::lock_guard<std::mutex> lock(mutex);
    std::string jsonConf;
    if(Utils::protoToJson(sysconf,jsonConf))
    {
        ofstream outfile("SysConfig.json", ios::binary | ios::trunc);
        outfile << jsonConf;
        outfile.close();
        std::cout << "Gas thresholds saved to JSON file: " << "SysConfig.json" << std::endl;
        return true;
    }
    else
    {
        std::cerr << "Failed to open file: " << "SysConfig.json" << std::endl;
        return false;
    }
}
/***********************************************************************************************/
bool ParaManager::loadSysConf()
{
  if((FileHelper::isFileExists("SysConfig.json")))
  {
    std::string readjson;
    SysConfig readconf;
    if(FileHelper::getContent("SysConfig.json",&readjson))
    {
        if(Utils::jsonToProto(readjson,readconf))
        {
            sysConf = readconf;
            return true;
        }
        else
        {
            return false; 
        }
    }
    else
    {
        return false;
    }
  }
  else
  {
    sysConf.set_componentid("DFEGWZDGAS0000001");
    sysConf.set_datainterval(1);
    sysConf.set_devicestatusinterval(1);
    return SaveSysConf(sysConf);
  }

}
/***********************************************************************************************/
bool ParaManager::SaveNetConf(NetConfig & netconf)
{
    std::mutex mutex;
    std::lock_guard<std::mutex> lock(mutex);
    std::string jsonConf;
    if(Utils::protoToJson(netconf,jsonConf))
    {
        ofstream outfile("NetConfig.json", ios::binary | ios::trunc);
        outfile << jsonConf;
        outfile.close();
        return true;
    }
    else
    {
        return false;
    }
}

/***********************************************************************************************/
bool ParaManager::loadNetConf()
{
  if((FileHelper::isFileExists("NetConfig.json")))
  {
    std::string readjson;
    NetConfig readconf;
    if(FileHelper::getContent("NetConfig.json",&readjson))
    {
        if(Utils::jsonToProto(readjson,readconf))
        {
            netConf = readconf;
            return true;
        }
        else
        {
            return false; 
        }
    }
    else
    {
        return false;
    }
  }
  else
  {
    std::string jsonConf;
    netConf.set_mqttserverurl("192.168.16.231:1883");
    netConf.set_mqttclientname("client");
    netConf.set_mqttname("GWZD");
    netConf.set_mqttpassword("12345");
    netConf.set_serverhost("192.168.16.232");
    netConf.set_clienthost("192.168.16.231");
    netConf.set_tcpclientport(2345);
    netConf.set_tcpserverport(2345);
    return SaveNetConf(netConf);
  }

}
/***********************************************************************************************/
bool ParaManager::SaveThresoldPara(GasThresholdList& thresoldconfs)
{
    std::mutex mutex;
    std::lock_guard<std::mutex> lock(mutex);
    std::string jsonConf;
    if(Utils::protoToJson(thresoldconfs,jsonConf))
    {
        ofstream outfile("ThresoldConfig.json", ios::binary | ios::trunc);
        outfile << jsonConf;
        outfile.close();
        return true;
    }
    else
    {
        return false;
    }  
}
/***********************************************************************************************/
bool ParaManager::loadThresoldPara()
{
  if((FileHelper::isFileExists("ThresoldConfig.json")))
  {
    std::string readjson;
    GasThresholdList readthresoldConfs;
    if(FileHelper::getContent("ThresoldConfig.json",&readjson))
    {
        if(Utils::jsonToProto(readjson,readthresoldConfs))
        {
            thresoldConfs = readthresoldConfs;
            return true;
        }
        else
        {
            return false; 
        }
    }
    else
    {
        return false;
    }
  }
  else
  { 
    for(int i = 0;i<2 ;i++)
    {
        auto gas = thresoldConfs.add_thresholds();
        switch (i)
        {
        case 0:
            gas->set_name("O2");
            break;
        case 1:
            gas->set_name("CO");
        default:
            break;
        }
        gas->set_thresholdl_max1(10);
        gas->set_thresholdl_max2(20);
        gas->set_thresholdl_max3(30);
        gas->set_thresholdl_min1(1);
        gas->set_thresholdl_min2(2);  
        gas->set_thresholdl_min3(3);
        gas->set_thresholdchange(5);

    }
    // GasThreshold * thresold1 = thresoldConfs.add_thresholds();
    // thresold1->set_name("O2");
    // thresold1->set_thresholdl_max1(10);
    // thresold1->set_thresholdl_max2(20);
    // thresold1->set_thresholdl_max3(30);
    // thresold1->set_thresholdl_min1(1);
    // thresold1->set_thresholdl_min2(2);  
    // thresold1->set_thresholdl_min3(3);
    // thresold1->set_thresholdchange(5);
    // GasThreshold * thresold2 = thresoldConfs.add_thresholds();
    // thresold2->set_name("CO");
    // thresold2->set_thresholdl_max1(10);
    // thresold2->set_thresholdl_max2(20);
    // thresold2->set_thresholdl_max3(30);
    // thresold2->set_thresholdl_min1(1);
    // thresold2->set_thresholdl_min2(2);  
    // thresold2->set_thresholdl_min3(3);
    // thresold2->set_thresholdchange(5);
    return SaveThresoldPara(thresoldConfs);
  }

}
/***********************************************************************************************/
bool ParaManager::SaveFanPumpStatusConf(FanPumpStatusConfig & fanpumpstatusconf)
{
    std::mutex mutex;
    std::lock_guard<std::mutex> lock(mutex);
    std::string jsonConf;
    if(Utils::protoToJson(fanpumpstatusconf,jsonConf))
    {
        ofstream outfile("FanPumpStatusConfig.json", ios::binary | ios::trunc);
        outfile << jsonConf;
        outfile.close();
        std::cout << "Gas thresholds saved to JSON file: " << "FanPumpStatusConfig.json" << std::endl;
        return true;
    }
    else
    {
        std::cerr << "Failed to open file: " << "FanPumpStatusConfig.json" << std::endl;
        return false;
    }
}
/***********************************************************************************************/
bool ParaManager::loadFanPumpStatusConf()
{
  if((FileHelper::isFileExists("FanPumpStatusConfig.json")))
  {
    std::string readjson{};
    FanPumpStatusConfig readconf;
    if(FileHelper::getContent("FanPumpStatusConfig.json",&readjson))
    {
        if(Utils::jsonToProto(readjson,readconf))
        {
            fanpumpstatusConf = readconf;
            return true;
        }
        else
        {
            return false; 
        }
    }
    else
    {
        return false;
    }
  }
  else
  {
    fanpumpstatusConf.set_status("Open");
    fanpumpstatusConf.set_workmode("Manual");
    return SaveFanPumpStatusConf(fanpumpstatusConf);
  }

}
/***********************************************************************************************/
bool ParaManager::SaveFanTimingConf(FanTimingConfig & fantimingconf)
{
    std::mutex mutex;
    std::lock_guard<std::mutex> lock(mutex);
    std::string jsonConf{};
    if(Utils::protoToJson(fantimingconf,jsonConf))
    {
        ofstream outfile("FanTimingConfig.json", ios::binary | ios::trunc);
        outfile << jsonConf;
        outfile.close();
        std::cout << "Gas thresholds saved to JSON file: " << "FanTimingConfig.json" << std::endl;
        return true;
    }
    else
    {
        std::cerr << "Failed to open file: " << "FanTimingConfig.json" << std::endl;
        return false;
    }
}

/***********************************************************************************************/
bool ParaManager::loadNFanTimingConf()
{
  if((FileHelper::isFileExists("FanTimingConfig.json")))
  {
    std::string readjson;
    FanTimingConfig readconf;
    if(FileHelper::getContent("FanTimingConfig.json",&readjson))
    {
        if(Utils::jsonToProto(readjson,readconf))
        {
            fantimingConf = readconf;
            return true;
        }
        else
        {
            return false; 
        }
    }
    else
    {
        return false;
    }
  }
  else
  {
    fantimingConf.set_active("True");
    fantimingConf.set_basetime("080000");
    fantimingConf.set_endtime("180000");
    fantimingConf.set_interval(60);
    fantimingConf.set_openmin(10);
    return SaveFanTimingConf(fantimingConf);
  }

}
/***********************************************************************************************/
