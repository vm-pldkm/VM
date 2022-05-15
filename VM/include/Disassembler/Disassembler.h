#ifndef DISASSEMBLER_DISASSEMBLER_H
#define DISASSEMBLER_DISASSEMBLER_H

#include <fstream>
#include <sstream>
#include <string>

class Disassembler
{
public:
    Disassembler() = default;
    bool disassemble(const std::string& file_name);
    void print(std::ostream& os) const;

private:
    static std::string getString(const std::string& klass, size_t* pos);
    void getClassName(const std::string& klass, size_t* pos);
    void getConstantPool(const std::string& klass, size_t* pos);
    void getFields(const std::string& klass, size_t* pos);
    void getMethods(const std::string& klass, size_t* pos);
    void getInstructions(const std::string& klass, size_t* pos);

    std::stringstream text_;
};

#endif // DISASSEMBLER_DISASSEMBLER_H