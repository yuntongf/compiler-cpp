#include"code.cpp"
#include"object.cpp"
#include"ast.h"

struct ByteCode {
    Instructions instructions;
    vector<Object> constants;
};

class Compiler {
    private:
    Instructions instructions;
    vector<Object> constants;

    public:
    Compiler() = default;

    int compile(Node& node) {
        return 1;
    }

    ByteCode getByteCode() {
        return ByteCode{
            instructions, constants
        };
    }
};