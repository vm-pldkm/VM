#ifndef VM_PKMVM_H
#define VM_PKMVM_H

#include "VM/ClassLinker.h"
#include "Frame.h"

#include <unordered_map>
#include <stack>

struct PkmVM
{
    PkmVM() = default;
    static void destroyVM();
    void create_new_frame(pmethodID pmethod);

    std::stack<Frame> stack_frame;
};

#endif // VM_PKMVM_H