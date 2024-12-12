#ifndef STATIC_RESOURCE_HPP
#define STATIC_RESOURCE_HPP

#include <memory_resource>
#include <list>
#include <new>
#include <cassert>

class ListMemoryResource : public std::pmr::memory_resource {
private:
    struct BlockInfo {
        void* ptr;
        std::size_t size;
        bool free;
    };

    std::list<BlockInfo> blocks;

protected:
    virtual void* do_allocate(std::size_t bytes, std::size_t alignment) override {
        for (auto &block : blocks) {
            if (block.free && block.size >= bytes) {
                block.free = false;
                return block.ptr;
            }
        }
        void* p = ::operator new(bytes, std::align_val_t(alignment));
        blocks.push_back({p, bytes, false});
        return p;
    }

    virtual void do_deallocate(void* p, std::size_t bytes, std::size_t alignment) override {
        (void)bytes;
        (void)alignment;
        for (auto &block : blocks) {
            if (block.ptr == p) {
                block.free = true;
                return;
            }
        }
        assert(false && "Attempt to deallocate memory not allocated by this resource");
    }

    virtual bool do_is_equal(const std::pmr::memory_resource& other) const noexcept override {
        return this == &other;
    }

public:
    ~ListMemoryResource() {
        for (auto &block : blocks) {
            if (block.ptr) {
                ::operator delete(block.ptr, std::align_val_t(alignof(std::max_align_t)));
            }
        }
    }
};

#endif // STATIC_RESOURCE_HPP