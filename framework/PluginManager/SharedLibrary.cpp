#include "SharedLibrary.h"

namespace SciFlow::Plugins
{
    SharedLibrary::SharedLibrary(const std::string& path)
    {
        m_handle = dlopen(path.c_str(),RTLD_LAZY);       
        
        if(m_handle == nullptr)
        {
            const char* error = dlerror();
            throw std::runtime_error(
                "dlopen failed: " + 
                    std::string(error ? error : "unknown error"));            
        }               
    }

    SharedLibrary::~SharedLibrary()
    {
        if(m_handle != nullptr)
        {
            const char* error = dlerror();
            std::cerr << "dlclose failed: "
                << (error ? error : "unknown error") 
                << '\n';
        }
    }

    /*template<typename Function>
    Function SharedLibrary::getSymbol(const std::string& symbolName)
    {
        dlerror();

        void* symbol = dlsym(m_handle, symbolName.c_str());

        const char* error = dlerror();
        if(error != nullptr){
            throw std::runtime_error(
                "dlsym failed for - " + symbolName + " : " + std::string(error));
        }

        return reinterpret_cast<Function>(symbol);
    }*/
}