/*
 *  Yarp Modules Manager
 *  Copyright: (C) 2011 Robotics, Brain and Cognitive Sciences - Italian Institute of Technology (IIT)
 *  Authors: Ali Paikan <ali.paikan@iit.it>
 *
 *  Copy Policy: Released under the terms of the LGPLv2.1 or later, see LGPL.TXT
 */


#ifndef YARP_MANAGER_XMLAPPLOADER
#define YARP_MANAGER_XMLAPPLOADER

#include <yarp/manager/ymm-types.h>
#include <yarp/manager/manifestloader.h>


namespace yarp {
namespace manager {


/**
 * Class XmlAppLoader
 */
class XmlAppLoader : public AppLoader {

    typedef map<string, string> VarMap;
public:
    XmlAppLoader(const char* szFileName);
    XmlAppLoader(const char* szPath, const char* szAppName);
    virtual ~XmlAppLoader();

    bool         init(void);
    void         fini(void);
    void         reset(void);
    Application* getNextApplication(void);

protected:

private:
    string         strAppName;
    string         strPath;
    string         strFileName;
    vector<string> fileNames;
    VarMap         variables;
    Application    app;
    Application*   parsXml(const char* szFile);
    std::string    parseText(const char *element);
};

} // namespace yarp
} // namespace manager


#endif // __YARP_MANAGER_XMLAPPLOADER__
