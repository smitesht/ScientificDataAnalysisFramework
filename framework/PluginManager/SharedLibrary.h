#pragma once
#include <iostream>
#include <string>
#include <memory>
#include <dlfcn.h>

namespace SciFlow::Plugins
{
    class SharedLibrary
    {
        public:
            explicit SharedLibrary(const std::string& path);
            
            ~SharedLibrary();

            SharedLibrary(const SharedLibrary&) = delete;
            SharedLibrary& operator=(const SharedLibrary&) = delete;
            SharedLibrary& operator=(SharedLibrary&&) = delete;

            SharedLibrary(SharedLibrary&& other) noexcept
                :m_handle(other.m_handle)
            {
                other.m_handle = nullptr;
            }

            template <typename Function>
            Function getSymbol(const std::string& symbolName){
                
                dlerror();

                void* symbol = dlsym(m_handle, symbolName.c_str());

                const char* error = dlerror();
                if(error != nullptr){
                    throw std::runtime_error(
                        "dlsym failed for - " + symbolName + " : " + std::string(error));
                }

                return reinterpret_cast<Function>(symbol);
            }
        
            private:
                void* m_handle;
    };
}