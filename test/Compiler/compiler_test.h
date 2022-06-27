#include "Compiler/Compiler.h"

#include <gtest/gtest.h> // NOLINT

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#define CONSTRUCT_FILE(str)      \
    std::ofstream ofile("file"); \
    ofile << (str);              \
    ofile.close(); //

TEST(CompilerTest, DefaultConstructor) // NOLINT
{
    Compiler comp;
}

TEST(CompilerTest, LoadWrongFileName) // NOLINT
{
    Compiler comp;
    comp.load("!");
    EXPECT_TRUE(comp.getError().type == CompilationError::Type::FILE_NOT_FOUND);
}

TEST(CompilerTest, LoadNormFile) // NOLINT
{
    CONSTRUCT_FILE(
        "class Main;"
    )
    Compiler comp;
    comp.load("file");
    comp.compile(".txt");
    EXPECT_TRUE(comp.getError().type == CompilationError::Type::OK);
}

#undef CONSTRUCT_FILE