LEVEL = ../../../../../..

POLYBENCH_UTILS = SingleSource/Benchmarks/Polybench/utilities 
PROG          = mvt
CFLAGS        += -I $(PROJ_SRC_ROOT)/$(POLYBENCH_UTILS) -DPOLYBENCH_DUMP_ARRAYS -DFP_ABSTOLERANCE=1e-5

HASH_PROGRAM_OUTPUT = 1

ifeq ($(ARCH),XCore)
XCORE_TARGET_NEEDS_MEMORY := 128
endif

include $(LEVEL)/SingleSource/Makefile.singlesrc

