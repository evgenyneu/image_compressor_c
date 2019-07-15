/*

Copy file from `from` to `to` path.

Inputs:
-------

from, to : the source and destination paths.

overwrite : When 1, overwrite if file already exists at `to`
            When 0, `cp` will fail when file already exists.

Output:
-------

Returns: 0 on success, non-zero on error.

*/
int cp(const char *from, const char *to, int overwrite);