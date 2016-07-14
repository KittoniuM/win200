#undef KEY
#undef BUFLEN

template <unsigned int XORSTART, unsigned int BUFLEN, unsigned int XREFKILLER>
class XorStr
{
private:
	XorStr();
public:
	long s[BUFLEN];

	XorStr(const unsigned short* xs);
};

template <unsigned int XORSTART, unsigned int BUFLEN, unsigned int XREFKILLER>
XorStr<XORSTART, BUFLEN, XREFKILLER>::XorStr(const unsigned short* xs)
{
	unsigned int xvalue = XORSTART;
	unsigned int i = 0;
	for (; i < (BUFLEN - 1); i++)
	{
		s[i] = xs[i - XREFKILLER] ^ xvalue;
		xvalue += 1;
		xvalue %= 256;
	}
	s[BUFLEN - 1] = 0;
}
