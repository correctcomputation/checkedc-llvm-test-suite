list(APPEND LDFLAGS -lm)
set(Source
  ackermann.c
  ary3.c
  fib2.c
  hash.c
  heapsort.c
  lists.c
  matrix.c
  methcall.c
  nestedloop.c
  objinst.c
  random.c
  sieve.c
  strcat.c
)
if(NOT TEST_SUITE_BENCHMARKING_ONLY)
  list(APPEND Source hello.c)
endif()
llvm_singlesource(PREFIX Shootout-)
