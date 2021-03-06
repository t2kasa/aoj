cmake_minimum_required(VERSION 3.10)
project(aoj)

set(CMAKE_CXX_STANDARD 14)

# dpl
add_executable(dpl_a_1 dpl/dpl_1_a.cpp)
add_executable(dpl_1_a_2nd dpl/dpl_1_a_2nd.cpp)
add_executable(dpl_1_b dpl/dpl_1_b.cpp)
add_executable(dpl_1_b_2nd dpl/dpl_1_b_2nd.cpp)
add_executable(dpl_1_c dpl/dpl_1_c.cpp)
add_executable(dpl_1_d dpl/dpl_1_d.cpp)
add_executable(dpl_3_a dpl/dpl_3_a.cpp)

# alds
add_executable(alds1_1_a alds/alds1_1_a.cpp)
add_executable(alds1_1_b alds/alds1_1_b.cpp)
add_executable(alds1_1_c alds/alds1_1_c.cpp)
add_executable(alds1_1_d alds/alds1_1_d.cpp)

add_executable(alds1_2_a alds/alds1_2_a.cpp)
add_executable(alds1_2_b alds/alds1_2_b.cpp)
add_executable(alds1_2_c alds/alds1_2_c.cpp)
add_executable(alds1_2_d alds/alds1_2_d.cpp)

add_executable(alds1_3_a alds/alds1_3_a.cpp)
add_executable(alds1_3_b alds/alds1_3_b.cpp)
add_executable(alds1_3_c alds/alds1_3_c.cpp)
add_executable(alds1_3_d alds/alds1_3_d.cpp)

add_executable(alds1_4_a alds/alds1_4_a)
add_executable(alds1_4_b alds/alds1_4_b.cpp)
add_executable(alds1_4_b_s2 alds/alds1_4_b_s2.cpp)
add_executable(alds1_4_c alds/alds1_4_c.cpp)
add_executable(alds1_4_d alds/alds1_4_d.cpp)

add_executable(alds1_5_a alds/alds1_5_a.cpp)
add_executable(alds1_5_b alds/alds1_5_b.cpp)
add_executable(alds1_5_c alds/alds1_5_c.cpp)
add_executable(alds1_5_d alds/alds1_5_d.cpp)

add_executable(alds1_6_a alds/alds1_6_a.cpp)
add_executable(alds1_6_b alds/alds1_6_b.cpp)
add_executable(alds1_6_c alds/alds1_6_c.cpp)
add_executable(alds1_6_d alds/alds1_6_d.cpp)

add_executable(alds1_7_a alds/alds1_7_a.cpp)
add_executable(alds1_7_b alds/alds1_7_b.cpp)
add_executable(alds1_7_c alds/alds1_7_c.cpp)
add_executable(alds1_7_d alds/alds1_7_d.cpp)

add_executable(alds1_8_a alds/alds1_8_a.cpp)
add_executable(alds1_8_b alds/alds1_8_b.cpp)
add_executable(alds1_8_c alds/alds1_8_c.cpp)

add_executable(alds1_9_a alds/alds1_9_a.cpp)
add_executable(alds1_9_b alds/alds1_9_b.cpp)
add_executable(alds1_9_c alds/alds1_9_c.cpp)

add_executable(alds1_10_a alds/alds1_10_a.cpp)
add_executable(alds1_10_b alds/alds1_10_b.cpp)
add_executable(alds1_10_c alds/alds1_10_c.cpp)

add_executable(alds1_11_a alds/alds1_11_a.cpp)
add_executable(alds1_11_b alds/alds1_11_b.cpp)
add_executable(alds1_11_b_use_stack alds/alds1_11_b_use_stack.cpp)
add_executable(alds1_11_c alds/alds1_11_c.cpp)
add_executable(alds1_11_d alds/alds1_11_d.cpp)

add_executable(alds1_12_a alds/alds1_12_a.cpp)
add_executable(alds1_12_b alds/alds1_12_b.cpp)
add_executable(alds1_12_c alds/alds1_12_c.cpp)

add_executable(alds1_13_a alds/alds1_13_a.cpp)
add_executable(alds1_13_b alds/alds1_13_b.cpp)
#add_executable(alds1_13_c alds/alds1_13_c.cpp)
#add_executable(alds1_13_c_2 alds/alds1_13_c_2.cpp)

# dsl
add_executable(dsl_1_a dsl/dsl_1_a.cpp)

# cgl
add_executable(cgl_1_a cgl/cgl_1_a.cpp)
add_executable(cgl_1_b cgl/cgl_1_b.cpp)
add_executable(cgl_1_c cgl/cgl_1_c.cpp)
add_executable(cgl_2_a cgl/cgl_2_a.cpp)
add_executable(cgl_2_b cgl/cgl_2_b.cpp)
add_executable(cgl_2_d cgl/cgl_2_d.cpp)

# ntl
add_executable(ntl_1_b ntl/ntl_1_b.cpp)

# volume11
add_executable(0539 volume5/0539.cpp)

# volume11
add_executable(1160 volume11/1160.cpp)


# examples
#add_executable(example_iterator example_iterator.cpp)
#add_executable(example_lower_bound example_lower_bound.cpp)
add_executable(example_priority_queue alds/example_priority_queue.cpp)
