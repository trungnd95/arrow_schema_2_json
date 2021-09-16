#include "SchemaJsonConv.h"

namespace service
{
    std::shared_ptr<arrow::Schema> SchemaJsonConv::ms_lastSchemaCache = nullptr;
    std::string SchemaJsonConv::ms_lastJsonCache = "";

    // SchemaJsonConv
    SchemaJsonConv::SchemaJsonConv() {}

    // ~SchemaJsonConv
    SchemaJsonConv::~SchemaJsonConv() {}

    // schema2JsonStr
    std::string SchemaJsonConv::schema2JsonStr(const std::shared_ptr<arrow::Schema>& t_arrSchema)
    {
        // Check if this function is call again with the same input param. Return the result immidiately.
        if (ms_lastSchemaCache == t_arrSchema && t_arrSchema != nullptr)
            return ms_lastJsonCache;

        // Convert arrow schema to json string
        std::ostringstream ssJson;
        ssJson << "{";
        for (int i = 0; i < t_arrSchema->num_fields(); ++i)
        {
            std::shared_ptr<arrow::Field> field = t_arrSchema->field(i);
            t_arrSchema->fields();
            ssJson << "\"" << field->name() << "\":[],";
        }
        ssJson.seekp(-1, std::ios_base::end);
        ssJson << "}";

        // Save cache
        ms_lastJsonCache = ssJson.str();
        ms_lastSchemaCache = t_arrSchema;
        return ms_lastJsonCache;
    }

    // jsonStr2Schema
    std::shared_ptr<arrow::Schema> SchemaJsonConv::jsonStr2Schema(const std::string& t_jsonStr)
    {
        // Check if this funciton is call again with the same input param.
        if (t_jsonStr == ms_lastJsonCache)
            return ms_lastSchemaCache;

        // Convert json to schema
        nlohmann::json oJson = nlohmann::json::parse(t_jsonStr);
        std::vector<std::string> fields;
        for (auto &it : oJson.items())
        {
            fields.push_back(it.key());
        }

        std::vector<std::shared_ptr<arrow::Field>> arrowFields;
        for (auto &it : fields)
        {
            std::shared_ptr<arrow::Field> arrowField = arrow::field(it, arrow::int64());
            arrowFields.push_back(arrowField);
        }

        // Save cache
        ms_lastSchemaCache = arrow::schema(arrowFields);
        ms_lastJsonCache = t_jsonStr;
        return ms_lastSchemaCache;
    }
}
