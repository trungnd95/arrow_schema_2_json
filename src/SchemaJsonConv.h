/**
*===================================================================================================
* Project: Arrow2Json
* Module: SchemaJsonConv
* Module Short Description: Module provide helper apis to convert apache schema arrow to json string
*                           and vice vesa.
* Author: Trung Nguyen
* Date: 09/15/2021 20:41
* Organization:
* ==================================================================================================
*/

#ifndef SCHEMAJSONCONV_H
#define SCHEMAJSONCONV_H

//----- Include libs
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <arrow/dataset/dataset.h>
#include <nlohmann/json.hpp>

namespace service
{
    class SchemaJsonConv
    {
        public:
            /**
             * @brief Api help convert apache arrow schema to Json string format.
             * @param t_arrSchema: Arrow schema to convert
             * @return json string is converted from schema
             */
            static std::string schema2JsonStr(const std::shared_ptr<arrow::Schema>& t_arrSchema);

            /**
             * @brief Api help convert from Json string to Apache arrow schema
             * @param t_jsonStr: Json string to convert
             * @return arrow::Schema is converted from json string
             */
            static std::shared_ptr<arrow::Schema> jsonStr2Schema(const std::string& t_jsonStr);

        protected:
            //---- Prevent create, copy object because of this class is truely
            //     helper one, do not need create instance that waste memory.
            SchemaJsonConv();
            ~SchemaJsonConv();
            SchemaJsonConv(const SchemaJsonConv& ) = delete;
            SchemaJsonConv& operator=(const SchemaJsonConv& ) = delete;

        private:
            static std::shared_ptr<arrow::Schema> ms_lastSchemaCache;
            static std::string ms_lastJsonCache;
    };
}
#endif // SCHEMAJSONCONV_H
