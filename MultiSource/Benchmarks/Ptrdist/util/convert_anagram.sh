# Make sure that the PATH includes 3c
# If necessary, set CPATH to point to checked C headers

3c -alltypes -warn-root-cause \
-output-postfix=checked \
-extra-arg-before=-Wall \
-extra-arg-before=-Wextra \
-extra-arg-before=-I. \
./anagram.c

python ../util/replace.py
