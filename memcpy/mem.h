#ifndef MY_MEM_H
#define MY_MEM_H

void* memCpy(void* dst, const void* src, int n) {
    if (dst == nullptr || src == nullptr) {
        return nullptr;
    }

    // 按字节拷贝
    char* c_dst = (char*)dst;
    char* c_src = (char*)src;

    // 考虑覆盖
    if (c_src < dst && dst < c_src + n) {
        // 形如
        // src --------
        // dst     --------
        // 从尾部拷贝
        c_dst = c_dst + n - 1;
        c_src = c_src + n - 1;
        while (n--) {
            *c_dst = *c_src;
            c_dst--;
            c_src--;
        }
    } else {
        // 形如
        // src     --------
        // dst --------    
        // 从头部拷贝
        *c_dst = *c_src;
        c_dst++;
        c_src++;
    }
    return dst;
}

#endif // MY_MEM_H