#include "FreeRTOS.h"
#include "task.h"
#include <bsp-interface/di/interrupt.h>
#include <cstddef>
#include <new>

char const *_freertos_heap4_new_error_message = nullptr;

void *operator new(size_t size)
{
    DI_DisableGlobalInterrupt();
    void *ptr = pvPortMalloc(size);
    DI_EnableGlobalInterrupt();
    if (ptr == nullptr)
    {
        _freertos_heap4_new_error_message = "分配内存失败";
        throw std::bad_alloc{};
    }

    return ptr;
}

void *operator new[](size_t size)
{
    DI_DisableGlobalInterrupt();
    void *ptr = pvPortMalloc(size);
    DI_EnableGlobalInterrupt();
    if (ptr == nullptr)
    {
        _freertos_heap4_new_error_message = "分配内存失败";
        throw std::bad_alloc{};
    }

    return ptr;
}

void operator delete(void *ptr) noexcept
{
    DI_DisableGlobalInterrupt();
    vPortFree(ptr);
    DI_EnableGlobalInterrupt();
}

void operator delete[](void *ptr) noexcept
{
    DI_DisableGlobalInterrupt();
    vPortFree(ptr);
    DI_EnableGlobalInterrupt();
}

void *operator new(size_t size, std::nothrow_t const &) noexcept
{
    DI_DisableGlobalInterrupt();
    void *p = pvPortMalloc(size);
    DI_EnableGlobalInterrupt();
    if (p == nullptr)
    {
        _freertos_heap4_new_error_message = "分配内存失败";
    }

    return p;
}

void *operator new[](size_t size, std::nothrow_t const &) noexcept
{
    DI_DisableGlobalInterrupt();
    void *p = pvPortMalloc(size);
    DI_EnableGlobalInterrupt();
    if (p == nullptr)
    {
        _freertos_heap4_new_error_message = "分配内存失败";
    }

    return p;
}

void operator delete(void *ptr, std::nothrow_t const &) noexcept
{
    DI_DisableGlobalInterrupt();
    vPortFree(ptr);
    DI_EnableGlobalInterrupt();
}

void operator delete[](void *ptr, std::nothrow_t const &) noexcept
{
    DI_DisableGlobalInterrupt();
    vPortFree(ptr);
    DI_EnableGlobalInterrupt();
}

void operator delete(void *ptr, size_t size) noexcept
{
    DI_DisableGlobalInterrupt();
    vPortFree(ptr);
    DI_EnableGlobalInterrupt();
}

void operator delete[](void *ptr, size_t size) noexcept
{
    DI_DisableGlobalInterrupt();
    vPortFree(ptr);
    DI_EnableGlobalInterrupt();
}
