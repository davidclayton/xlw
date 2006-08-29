/*
 Copyright (C) 2006 Mark Joshi
 
 This file is part of XLW, a free-software/open-source C++ wrapper of the
 Excel C API - http://xlw.sourceforge.net/
 
 XLW is free software: you can redistribute it and/or modify it under the
 terms of the XLW license.  You should have received a copy of the
 license along with this program; if not, please email xlw-users@lists.sf.net
 
 This program is distributed in the hope that it will be useful, but WITHOUT
 ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 FOR A PARTICULAR PURPOSE.  See the license for more details.
*/

#ifndef PARSER_DATA_H
#define PARSER_DATA_H
#include <string>
#include <vector>

class  FunctionArgumentType
{
public:       
     FunctionArgumentType(std::string NameIdentifier,
                          std::string ConversionToMethod,
                          char EXCELKey);
     
     const std::string& GetNameIdentifier() const;
     const std::string& GetConversionToMethod() const;
     char GetEXCELKey() const;
     
private:
     std::string NameIdentifier;
     std::string ConversionToMethod;            
     char EXCELKey; 
            
};

class FunctionArgument
{
public: 
     FunctionArgument(const FunctionArgumentType& TheType_,
                        std::string ArgumentName_,
                        std::string ArgumentDescription_);
        
     FunctionArgumentType GetTheType() const;
     std::string GetArgumentName() const;
     std::string GetArgumentDescription() const; 
             
private:
     FunctionArgumentType TheType;
     std::string ArgumentName;
     std::string ArgumentDescription;   
};

class FunctionDescription
{
public:
     FunctionDescription(std::string FunctionName_,
                         std::string FunctionHelpDescription_,
						 std::string ReturnType,
						 char ExcelKey,
                         const std::vector<FunctionArgument>& Arguments_);
     
     std::string GetFunctionName() const;
     std::string GetFunctionDescription() const;
	 char GetExcelKey() const;
	 std::string GetReturnType() const;
     const FunctionArgument& GetArgument(unsigned long ArgumentNumber) const;
     unsigned long NumberOfArguments() const;
            
private:
     std::string FunctionName;
     std::string FunctionHelpDescription;
	 std::string ReturnType;
	 char ExcelKey;
     std::vector<FunctionArgument> Arguments;
     
      
};

#endif