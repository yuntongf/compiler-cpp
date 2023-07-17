#include<iostream>

using namespace std;

struct ObjTypes {
    string INTEGER_OBJ = "INTEGER";
} objs;

class Object {
    public:
    string type;
    virtual ~Object() = default;
    virtual string serialize() const = 0;
    virtual string getType() const = 0;
};

class Integer: public Object {
    public:
    int value;
    string type = objs.INTEGER_OBJ;

    Integer(int val) : value(val) {};

    string serialize() const override {
        return to_string(value);
    }

    string getType() const override {
        return type;
    }
};