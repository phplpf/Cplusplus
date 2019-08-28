int CppDll_add( int m, int n )
{
	return m + n;
}
int CppDll_sub( int m, int n )
{
	return m -n;
}
_declspec(dllexport)int CppDll_mul( int m, int n )
{
	return m * n;
}