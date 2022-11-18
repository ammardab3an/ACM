#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

assert(__builtin_cpu_supports("avx2"))

__attribute__((target("avx2"), optimize("O3", "unroll-loops"))) void work() {
    // do something
}

__lg


#pragma GCC push_options
#pragma GCC pop_options
#pragma GCC reset_options

#pragma GCC target("arch=skylake")


