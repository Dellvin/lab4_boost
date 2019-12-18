// Copyright 2018 Your Name <your_email>

#include <gtest/gtest.h>
#include <header.hpp>

TEST(Example, EmptyTest) {
    parseFinantial boostTest;
    boostTest.getFiles("./../misc/ftp", "", 1);
    EXPECT_EQ((std::string) boostTest.DATA_BASE["00123458"].broker, "bcs");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


