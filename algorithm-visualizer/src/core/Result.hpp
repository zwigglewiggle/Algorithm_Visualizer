#pragma once
#include "core/Types.hpp"
#include <string>

namespace av{
    struct Result{
        StatusCode code;
        std::string message;
        bool isOk() const{
            return code == StatusCode::Ok;
        }
        bool isError() const{
            return code != StatusCode::Ok;
        
        }
        static Result success(){
            Result res = Result();
            res.code = StatusCode::Ok;
            res.message = "";
            return res;
         
        }
        static Result success(const std::string& message){
            Result res = Result();
            res.code = StatusCode::Ok;
            res.message = message;
            return res;
        }
        static Result failure(StatusCode code, const std::string& message){
            Result res = Result();
            res.code = code;
            res.message = message;
            return res;
        
        }
        
    

    };
}