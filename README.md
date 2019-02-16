# Ft_printf

Ft_printf is a 42 Project that aims to reproduce the printf function (included in <stdio.h>).
Work done with apsaint-

grade 104 / 112 (112 is the maximum grade possible)

Issues :
Problem with the flag 0 in the case of the precision is 0 and the width is longer that the argument to be printed.
Problem with the case of the wildcard '*' is used twice (both for the precision and the width).
Manage LDBL_MAX.
-0.00001 not printing the '-'.

Possible improvements :
Create a buffer to stock the future output instead of using multiples writes.
refactor the structure for the flags/size/precision (storing them in 15 bits is possible).
