#include"vm.cpp"
#include<iostream>
#include<gtest/gtest.h>

using namespace std;

void parse(string input, Program* program) {
    Lexer l = Lexer(input);
    Parser p = Parser(l);
    int error = p.parseProgram(program);
    if (error) FAIL() << "test failed due to error in parser..." << endl;
}

template <typename T>
struct VMTest {
    const string input;
    T expected;
};

TEST(VMTest, RunVMTest) {
    vector<VMTest<int>> tests = {
        {"1", 1},
        {"2", 2},
        {"1 + 2", 3},
        {"2 - 3", -1},
        {"4 * 3", 12},
        {"4 / 2", 2}
    };
    for (auto test : tests) {
        auto program = Program();
        parse(test.input, &program);
        auto compiler = Compiler();
        int err = compiler.compileProgram(&program);
        if (err) FAIL() << "test failed due to error in compiler..." << endl;

        auto vm = VM(compiler.getByteCode());
        if (vm.run()) FAIL() << "test failed due to error in vm..." << endl;

        Integer* integer = dynamic_cast<Integer*>(vm.getLastPopped().get());
        ASSERT_EQ(integer->value, test.expected);
        // ASSERT_EQ(vm.sp, 0);
    }
}