#include <gtest/gtest.h>

//--gtest_list_tests
//--gtest_filter=*

TEST (TestCaseName, test_name) {
    int a = 0;
    //EXPECT_*
    //ASSERT_* - критическая ошибка
    EXPECT_EQ(1, a + 1); //ожидаем, что получим 1
    //*_TRUE / *_FALSE
    //*_EQ / *_LT / ...
}

class FooTest : public ::testing::Test {
//функции (де)инициализации
};

int main(int argc, char const *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}