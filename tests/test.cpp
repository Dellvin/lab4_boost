// Copyright 2018 Your Name <your_email>

#include <gtest/gtest.h>
#include <header.hpp>

TEST(Example, EmptyTest) {
    parseFinantial boostTest;
    boostTest.getFiles("./../misc/ftp", "", 1);
    EXPECT_EQ((std::string) boostTest.DATA_BASE["00123458"].broker, "bcs");
    EXPECT_EQ(boostTest.DATA_BASE["00123458"].billsCount, 48);
    EXPECT_EQ(boostTest.DATA_BASE["00123458"].billLastDate, 20181018);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


