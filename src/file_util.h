/*

Copy file from `from` to `to` path.

Based on https://stackoverflow.com/a/2180788/297131.

Inputs:
-------

from, to : the source and destination paths.

overwrite : When 1, overwrite if file already exists at `to`
            When 0, `cp` will fail when file already exists.

Output:
-------

Returns: 0 on success, non-zero on error.

*/
int copy_file(const char *from, const char *to, int overwrite);