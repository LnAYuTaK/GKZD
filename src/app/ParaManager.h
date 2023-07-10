#pragma once 

#include <iostream>
#include <string>
#include <fstream>
#include <ostream>
#include <functional>
#include <mutex>

#include "sysconfig.pb.h"
#include "netconfig.pb.h"
#include "thresoldconfig.pb.h"
#include "fanpumpstatusconfig.pb.h"
#include "fantimingconfig.pb.h"
#include "SimpleSigleton.h"
#include "FileHelper.h"
#include "CLOG.h"

template <typename T>
class ProtoFact 
{
public:
    ProtoFact(std::string fileName)
             :_fileName(fileName)
    {
        if(FileHelper::isFileExists(_fileName))
        {
            loadConf();
        }
        else
        {
            saveConf();
        }
    }

    T & obj() 
    {
        return _obj;
    }

    bool saveConf()
    {
        std::mutex mutex;
        std::lock_guard<std::mutex> lock(mutex);
        std::string jsonConf;
        if(Utils::protoToJson(_obj,jsonConf))
        {
            ofstream outfile(_fileName, ios::binary | ios::trunc);
            outfile << jsonConf;
            outfile.close();
            return true;
        }
        else
        {
            return false;
        }
    }
private:
    bool loadConf()
    {
        std::string readjson;
        if(FileHelper::getContent(_fileName,&readjson))
        {
            T readconf; 
            if(Utils::jsonToProto(readjson,readconf))
            {
                _obj = readconf;
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
        return saveConf();
    }
    T             _obj;
    std::mutex    _mut;
    std::string   _fileName; 
};

class ParaManager
{

    DISALLOW_COPY_AND_ASSIGN(ParaManager)
public:

    ParaManager();
    ~ParaManager();
    
    ProtoFact<NetConfig>           &  netConf(){return this->netConfFact;}
    ProtoFact<SysConfig>           &  sysConf(){return this->sysConfFact;}
    ProtoFact<GasThresholdList>    &  gasConfsFact(){return this->thresoldConfsFact;}
    ProtoFact<FanPumpStatusConfig> &  fanpumpstatusConf(){return this->fanpumpstatusConfFact;}
    ProtoFact<FanTimingConfig>     &  fantimingConf(){return this->fantimingConfFact;}
private:
    ProtoFact<NetConfig>           netConfFact;
    ProtoFact<SysConfig>           sysConfFact;
    ProtoFact<GasThresholdList>    thresoldConfsFact;
    ProtoFact<FanPumpStatusConfig> fanpumpstatusConfFact;
    ProtoFact<FanTimingConfig>     fantimingConfFact;
    //NetConfig conf;
};

