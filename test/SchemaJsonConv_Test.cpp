/**
*===================================================================================================
* Project: Arrow2Json
* Module: SchemaJsonConv_Test
* Module Short Description: Unit-test SchemaJsonConv apis
* Author: Trung Nguyen
* Date: 09/15/2021 20:42
* Organization:
* ==================================================================================================
*/

#include <iostream>
#include <gtest/gtest.h>
#include "../src/SchemaJsonConv.h"

class SchemaJsonConv_Test : public ::testing::Test
{
    public:
        /**
         * @brief SetUp: Setup test data
         * @return
         */
        virtual void SetUp() override
        {
            jsonStrTest = "{\"field_A\":[],\"field_B\":[]}";
            schemaTest = arrow::schema({ arrow::field("field_A", arrow::int64()),
                                         arrow::field("field_B", arrow::int64())});
        }

        /**
         * @brief SetUp: Release test data
         * @return
         */
        virtual void TearDown() override
        {
            jsonStrTest = "";
            schemaTest = nullptr;
        }

    protected:
        std::string jsonStrTest;
        std::shared_ptr<arrow::Schema> schemaTest;
};

TEST_F(SchemaJsonConv_Test, ConvertJsonStr2ArrowChema)
{
    std::shared_ptr<arrow::Schema> schema = service::SchemaJsonConv::jsonStr2Schema(jsonStrTest);
    EXPECT_TRUE(schema->Equals(schemaTest));
}

TEST_F(SchemaJsonConv_Test, ConvertJsonStr2ArrowChema_CallAgain)
{
    std::shared_ptr<arrow::Schema> schema = service::SchemaJsonConv::jsonStr2Schema(jsonStrTest);
    std::shared_ptr<arrow::Schema> schema2 = service::SchemaJsonConv::jsonStr2Schema(jsonStrTest);
    EXPECT_TRUE(schema->Equals(schema2));
    EXPECT_TRUE(schema->Equals(schemaTest));
    EXPECT_TRUE(schema2->Equals(schemaTest));
}

TEST_F(SchemaJsonConv_Test, ConvertArrowSchema2JsonStr)
{
    std::string jsonStr = service::SchemaJsonConv::schema2JsonStr(schemaTest);
    EXPECT_STREQ(jsonStr.c_str(), jsonStrTest.c_str());
}

TEST_F(SchemaJsonConv_Test, ConvertArrowSchema2JsonStr_CallAgain)
{
    std::string jsonStr = service::SchemaJsonConv::schema2JsonStr(schemaTest);
    std::string jsonStr2 = service::SchemaJsonConv::schema2JsonStr(schemaTest);
    EXPECT_STREQ(jsonStr.c_str(), jsonStr2.c_str());
    EXPECT_STREQ(jsonStr.c_str(), jsonStrTest.c_str());
    EXPECT_STREQ(jsonStr2.c_str(), jsonStrTest.c_str());
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
